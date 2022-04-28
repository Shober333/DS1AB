//
// Created by shoha on 27/04/2022.
//

#ifndef HW1_EMPLOYEEMANAGER_H
#define HW1_EMPLOYEEMANAGER_H


// ................................................
typedef enum {
    SUCCESS = 0,
    FAILURE = -1,
    ALLOCATION_ERROR = -2,
    INVALID_INPUT = -3
} StatusType;
// ................................................


class EmployeeManager {
private:
    int _c_amount;
    int _e_amount;
    AvlTree _companies;
    AvlTree _employees_by_ID;
    AvlTree _employees_by_salary;


public:

    EmployeeManager();

    StatusType AddCompany(int CompanyID, int Value);

    StatusType AddEmployee(int EmployeeID, int CompanyID, int Salary, int Grade);

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


    //a destructor
    //...............................................................................

    void Quit(void** DS);


};


#endif //HW1_EMPLOYEEMANAGER_H
