//
// Created by shoha on 28/04/2022.
//

#ifndef HW1_EMPLOYEEDATA_H
#define HW1_EMPLOYEEDATA_H


class employeeData {
private:
    int _salary;
    int _grade;

    companyData* _employer;
    int _employer_ID;

    //int ID;

public:

    employeeData(int salary, int grade, companyData* employerData, int employer_ID ){
        _salary = salary;
        _grade = grade;
        _employer = employer;
        _employer_ID = employer_ID;
    }

    //some getters:
    int salary(){
        return _salary;
    }

    int grade(){
        return _grade;
    }

    int employer_ID(){
        return _employer_ID;
    }

    companyData employerData(){
        return _employer*;
    }

    void update_employer(companyData){
        (_employer*).update(companyData);
    }


};


#endif //HW1_EMPLOYEEDATA_H
