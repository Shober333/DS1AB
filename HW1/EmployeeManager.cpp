//
// Created by shoha on 27/04/2022.
//

#include "employeeData.h"
#include "companyData.h"
#include "EmployeeManager.h"

EmployeeManager::EmployeeManager(){
    _c_amount = 0;
    _e_amount = 0;
    _companies = AvlTree();
    _employees_by_ID = AvlTree();
    _employees_by_salary = AvlTree();
}

EMStatusType EmployeeManager::AddCompany(int CompanyID, int Value){
    if((CompanyID <= 0) || (Value <= 0)){
        return EM_INVALID_INPUT;
    }
    companyData company_data = companyData(Value);
    if (company_data == nullptr) return EM_ALLOCATION_ERROR;
    EMStatusType status= _companies.insert(company_data, CompanyID);
    if (status == EM_SUCCESS)
            _c_amount++;
    delete(company_data); //is there a special constructor? is it automatic?
    return status;
}

EMStatusType EmployeeManager::AddEmployee(int EmployeeID, int CompanyID, int Salary, int Grade){
    if((CompanyID <= 0) || (EmployeeID <= 0) || (Salary <= 0) || (Grade <= 0)){
        return EM_INVALID_INPUT;
    }
    companyData employer = _companies.find(CompanyID);
    if (employer == nullptr) return EM_FAILURE;
    if (_employees_by_ID.find(EmployeeID) != nullptr) return EM_FAILURE;

    employeeData employee_data = employeeData(Salary, Grade, &companyData, CompanyID);
    EMStatusType status = _employees_by_ID.insert(EmployeeID, employee_data);
    if (status != EM_SUCCESS) return status;

    status = _employees_by_salary.insert(salaryKey(Salary, EmployeeID), employee_data);
    employer.add_employee(EmployeeID, salaryKey(Salary, EmployeeID), employee_data);

    if (status == EM_SUCCESS){
        _e_amount++;
    }

    else{
        _employees_by_ID.remove(EmployeeID, employee_data);
        _employees_by_salary.remove(salaryKey(Salary, EmployeeID), employee_data);
    }

    delete(employee_data); //is there a special constructor? is it automatic?
    return status;
}

EMStatusType EmployeeManager::RemoveCompany(int CompanyID){
    if(CompanyID <= 0) return EM_INVALID_INPUT;
    companyData our_company = _companies.find(CompanyID);
    if( (our_company == nullptr) || (our_company.size() != 0) ) return EM_FAILURE;
    _companies.remove(CompanyID);
    _c_amount--;
    return EM_SUCCESS;
}

EMStatusType EmployeeManager::RemoveEmployee(int EmployeeID){
    if(EmployeeID <= 0) return EM_INVALID_INPUT;
    employeeData our_employee = _employees_by_ID.find(EmployeeID);
    if(our_employee == nullptr) return EM_FAILURE;
    salaryKey sk = salaryKey(our_employee.salary(), EmployeeID);
    companyData* employer = our_employee.employerData();
    employer->remove_employee(EmployeeID);
    _employees_by_ID.remove(EmployeeID);
    _employees_by_salary(sk);
    _e_amount--;
    return EM_SUCCESS;
}

EMStatusType EmployeeManager::GetCompanyInfo(int CompanyID, int *Value, int *NumEmployees){
    if((Value == nullptr) || (NumEmployees == nullptr) || (CompanyID <= 0)) retunr EM_INVALID_INPUT;
    companyData our_company = _companies.find(CompanyID);
    if (our_company == nullptr) return EM_FAILURE;
    *Value = our_company.value();
    *NumEmployees = our_company.size();
    return EM_SUCCESS;
}

EMStatusType EmployeeManager::GetEmployeeInfo(int EmployeeID, int *EmployerID, int *Salary, int *Grade){
    if((EmployerID == nullptr) || (Salary == nullptr) || (Grade == nullptr) || (EmployeeID <= 0)) retunr EM_INVALID_INPUT;
    employeeData our_employee = _employees_by_ID.find(EmployeeID);
    if (our_employee == nullptr) return EM_FAILURE;
    (*EmployerID) = our_employee.employer_ID();
    (*Salary) = our_employee.salary();
    (*Grade) = our_employee.grade();
    return EM_SUCCESS;
}

EMStatusType EmployeeManager::IncreaseCompanyValue(int CompanyID, int ValueIncrease){
    if( (ValueIncrease <= 0) || (CompanyID <= 0)) return EM_INVALID_INPUT;
    companyData our_company = _companies.find(CompanyID);
    if(our_company == nullptr) return EM_FAILURE;
    our_company.update_value(our_company.value() + ValueIncrease);
    return EM_SUCCESS;
}

EMStatusType EmployeeManager::PromoteEmployee(int EmployeeID, int SalaryIncrease, int BumpGrade){
    if( (SalaryIncrease <= 0) || (CompanyID <= 0)) return EM_INVALID_INPUT;
    employeeData our_employee = _employees_by_ID.find(EmployeeID);
    if(our_employee == nullptr) return EM_FAILURE;
    salaryKey sk = salaryKey(our_employee.salary(), EmployeeID);
    if(BumpGrade > 0){
        our_employee.increase_grade();
    }
    our_employee.increase_salary(SalaryIncrease);
    _employees_by_salary.remove(sk);
    sk.update_salary(sk.salary() + SalaryIncrease);
    _employees_by_salary.insert)(our_employee, sk);
    return EM_SUCCESS;
}

EMStatusType EmployeeManager::HireEmployee(int EmployeeID, int NewCompanyID){
    if( (EmployeeID <= 0) || (NewCompanyID <= 0) ) return EM_INVALID_INPUT;
    employeeData our_employee = _employees_by_ID.find(EmployeeID);
    int old_employer_ID = our_employee.employer_ID();
    if ( (our_employee == nullptr) || (old_employer_ID == NewCompanyID)) return EM_FAILURE;
    companyData new_company = _companies.find(NewCompanyID);
    if (new_company == nullptr) reutnr EM_FAILURE;
    (our_employee.employerData())->remove_employee(EmployeeID);
    salaryKey our_sk = salaryKey(EmployeeID, our_employee.salary());
    new_company.add_employee(EmployeeID, our_sk, our_employee);
    our_employee.change_employer(&new_company);
    _employees_by_salary.remove(our_sk);
    _employees_by_salary.insert)(our_employee, our_sk);
    return EM_SUCCESS;
}

EMStatusType EmployeeManager::AcquireCompany(int AcquirerID, int TargetID, double Factor){
    if((AcquirerID <= 0) || (TargetID <= 0) || (Factor < 1.00) || (AcquirerID == TargetID)) return EM_INVALID_INPUT;
    companyData AcquirerCompany = _companies(AcquirerID);
    companyData TargetCompany = _companies(TargetID);
    if((AcquirerCompany == nullptr) || (TargetCompany == nullptr) ||
        AcquirerCompany.value() < 10*TargetCompany.value()) return EM_FAILURE;
    //to be continued...

}

EMStatusType EmployeeManager::GetHighestEarner(int CompanyID, int *EmployeeID);

EMStatusType EmployeeManager::GetAllEmployeesBySalary(int CompanyID, int **Employees, int *NumOfEmployees);

EMStatusType EmployeeManager::GetHighestEarnerInEachCompany(int NumOfCompanies, int **Employees);

EMStatusType EmployeeManager::GetNumEmployeesMatching(int CompanyID, int MinEmployeeID, int MaxEmployeeId,
                                   int MinSalary, int MinGrade, int *TotalNumOfEmployees, int *NumOfEmployees);

