//
// Created by shoha on 24/04/2022.
//
import "library1.h"

void *Init(){
    EmployeeManager *DS = new EmployeeManager();
    return (void*)DS;
}

StatusType AddCompany(void *DS, int CompanyID, int Value){
    if((DS == NULL))
        return INVALID_INPUT;
    else if (!(DS.findCompany(CompanyID))){
        return FAILUE;
    }  //assuming DS will return NULL if companyID is not in the system
    else{
        if(DS.addCompany(CompanyID, Value)){
            return SUCCESS;
        }
        else{
            return ALLOCATION_ERROR;
        }
    }
}

StatusType AddEmployee(void *DS, int EmployeeID, int CompanyID, int Salary, int Grade);

StatusType RemoveCompany(void *DS, int CompanyID);

StatusType RemoveEmployee(void *DS, int EmployeeID);

StatusType GetCompanyInfo(void *DS, int CompanyID, int *Value, int *NumEmployees);

StatusType GetEmployeeInfo(void *DS, int EmployeeID, int *EmployerID, int *Salary, int *Grade);

StatusType IncreaseCompanyValue(void *DS, int CompanyID, int ValueIncrease);

StatusType PromoteEmployee(void *DS, int EmployeeID, int SalaryIncrease, int BumpGrade);

StatusType HireEmployee(void *DS, int EmployeeID, int NewCompanyID);

StatusType AcquireCompany(void *DS, int AcquirerID, int TargetID, double Factor);

StatusType GetHighestEarner(void *DS, int CompanyID, int *EmployeeID);

StatusType GetAllEmployeesBySalary(void *DS, int CompanyID, int **Employees, int *NumOfEmployees);

StatusType GetHighestEarnerInEachCompany(void *DS, int NumOfCompanies, int **Employees);

StatusType GetNumEmployeesMatching(void *DS, int CompanyID, int MinEmployeeID, int MaxEmployeeId,
                                   int MinSalary, int MinGrade, int *TotalNumOfEmployees, int *NumOfEmployees);

void Quit(void** DS);