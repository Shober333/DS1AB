//
// Created by shoha on 27/04/2022.
//

#ifndef HW1_EMPLOYEEMANAGER_H
#define HW1_EMPLOYEEMANAGER_H


// ................................................
typedef enum {
    EM_SUCCESS = 0,
    EM_FAILURE = -1,
    EM_ALLOCATION_ERROR = -2,
    EM_INVALID_INPUT = -3
} EMStatusType;
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

    EMStatusType AddCompany(int CompanyID, int Value);

    EMStatusType AddEmployee(int EmployeeID, int CompanyID, int Salary, int Grade);

    EMStatusType RemoveCompany(int CompanyID);

    EMStatusType RemoveEmployee(int EmployeeID);

    EMStatusType GetCompanyInfo(int CompanyID, int *Value, int *NumEmployees);

    EMStatusType GetEmployeeInfo(int EmployeeID, int *EmployerID, int *Salary, int *Grade);

    EMStatusType IncreaseCompanyValue(int CompanyID, int ValueIncrease);

    EMStatusType PromoteEmployee(int EmployeeID, int SalaryIncrease, int BumpGrade);

    EMStatusType HireEmployee(int EmployeeID, int NewCompanyID);

    EMStatusType AcquireCompany(int AcquirerID, int TargetID, double Factor);

    EMStatusType GetHighestEarner(int CompanyID, int *EmployeeID);

    EMStatusType GetAllEmployeesBySalary(int CompanyID, int **Employees, int *NumOfEmployees);

    EMStatusType GetHighestEarnerInEachCompany(int NumOfCompanies, int **Employees);

    EMStatusType GetNumEmployeesMatching(int CompanyID, int MinEmployeeID, int MaxEmployeeId,
                                       int MinSalary, int MinGrade, int *TotalNumOfEmployees, int *NumOfEmployees);


    //a destructor
    //...............................................................................

    void Quit(void** DS);


};


#endif //HW1_EMPLOYEEMANAGER_H
