//
// Created by shoha on 28/04/2022.
//

#ifndef HW1_EMPLOYEEDATA_H
#define HW1_EMPLOYEEDATA_H

#include "companyData.h"


class employeeData {
private:
    int _salary;
    int _grade;

    companyData* _employer;
    int _employer_ID;

    //int getID;

public:

    employeeData(int salary, int grade, companyData* employerData, int employer_ID ){
        _salary = salary;
        _grade = grade;
        _employer = employerData;
        _employer_ID = employer_ID;
    }

    //some getters:
    int salary()const{
        return _salary;
    }

    int grade()const{
        return _grade;
    }

    int employer_ID()const{
        return _employer_ID;
    }

    companyData* employerData()const{
        return _employer;
    }

    void increase_grade(){
        _grade++;
    }

    void increase_salary(const int SalaryIncrease){
        _salar += SalaryIncrease;
    }

};


#endif //HW1_EMPLOYEEDATA_H
