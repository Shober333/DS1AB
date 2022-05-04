//
// Created by shoha on 28/04/2022.
//

#ifndef HW1_COMPANYDATA_H
#define HW1_COMPANYDATA_H

#include "salaryKey.h"
#include "employeeData.h"

class companyData {
private:
    int _value;
    int _size; //employeeAmount
    AvlTree _employees_by_ID;
    AvlTree _employees_by_salary;
    int best_employee_ID;
public:

    companyData(const int value){
        _value = value;
        _size = 0;
        _employees_by_ID = new AvlTree();
        _employees_by_salary = new AvlTree();
    }


    //getters
    int value()const{
        return _value;
    }
    int size()const{
        return _size;
    }
    //something with employers and the trees

    //setters
    void update_value(const int new_value){
        _value = new_value;
    }

    void add_employee(const int ID, const salaryKey s_k, const employeeData data){
        _employees_by_ID.insert(data, ID);
        _employees_by_salary.insert(data, s_k);
        _size++;
    }

    void remove_employee(const int ID){
        int salary = (_employees_by_ID.find(ID)).salary();
        _employees_by_ID.remove(ID);
        _employees_by_salary.remove(salaryKey(salary, ID));
        _size--;
    }

    employeeData& find_employee(const int ID){
        return _employees_by_ID.find(ID);
    }

    employeeData& find_employee(const salaryKey sk){
        return this.find_employee(sk.ID());
    }
};


#endif //HW1_COMPANYDATA_H
