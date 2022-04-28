//
// Created by shoha on 27/04/2022.
//

#include "EmployeeManager.h"

EmployeeManager(){
    _c_amount = 0;
    _e_amount = 0;
    _companies = new AvlTree(companyData, int);
    _employees_by_ID = new AvlTree(employeeData, int);
    _employees_by_salary new AvlTree(employeeData, salaryKey);
}

StatusType AddCompany(int CompanyID, int Value){
    if((CompanyID <= 0) || (Value <= 0)){
        return INVALID_INPUT;
    }
    company_data = companyData(Value);
    if (company_data == NULL) return ALLOCATION_ERROR;
    StatusType status= _companies.add(CompanyID, company_data);
    if (status == SUCCESS)
            _c_amount++;
    free(company_data); //is there a special constructor? is it automatic?
    return status;
}

StatusType AddEmployee(int EmployeeID, int CompanyID, int Salary, int Grade){
    if((CompanyID <= 0) || (EmployeeID <= 0) || (Salary <= 0) || Grade <= 0)){
        return INVALID_INPUT;
    }
    employer = _companies.find(CompanyID);
    if (employer = NULL) return FAILURE;
    if (_employees_by_ID.find(EmployeeID) != NULL) return FAILURE;

    employee_data = employeeData(EmployeeID, companyData*, Salary, Grade);
    if (employee_date == NULL) return ALLOCATION_ERROR;

    StatusType status = _employees_by_ID.add(EmployeeID, employee_data);
    if (status!=SUCCESS) return status;
    status = _employees_by_ID.add(salaryKey(salary, EmployeeID), employee_data);
    if (status == SUCCESS)
        _c_amount++;
    free(employee_data); //is there a special constructor? is it automatic?
    return status;
}

StatusType RemoveCompany(int CompanyID);

StatusType RemoveEmployee(int EmployeeID);

StatusType GetCompanyInfo(int CompanyID, int *Value, int *NumEmployees);

StatusType GetEmployeeInfo(int EmployeeID, int *EmployerID, int *Salary, int *Grade);

StatusType IncreaseCompanyValue(int CompanyID, int ValueIncrease);

StatusType PromoteEmployee(int EmployeeID, int SalaryIncrease, int BumpGrade);

StatusType HireEmployee(int EmployeeID, int NewCompanyID);

StatusType AcquireCompany(int AcquirerID, int TargetID, double Factor);

StatusType GetHighestEarner(int CompanyID, int *EmployeeID);

StatusType GetAllEmployeesBySalary(int CompanyID, int **Employees, int *NumOfEmployees);

StatusType GetHighestEarnerInEachCompany(int NumOfCompanies, int **Employees);

StatusType GetNumEmployeesMatching(int CompanyID, int MinEmployeeID, int MaxEmployeeId,
                                   int MinSalary, int MinGrade, int *TotalNumOfEmployees, int *NumOfEmployees);

