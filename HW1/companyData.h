//
// Created by shoha on 28/04/2022.
//

#ifndef HW1_COMPANYDATA_H
#define HW1_COMPANYDATA_H


class companyData {
private:
    int _value;
    int _size; //employeeAmount
    AvlTree _employees_by_ID;
    AvlTree _employees_by_salary;
public:

    companyData(int value){
        _value = value;
        _size = 0;
        _employees_by_ID = AvlTree();
        _employees_by_salary = AvlTree();
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
    void update_value(int new_value){
        _value = new_value;
    }

    void add_employee(int ID, salaryKey s_k, employeeData data){
        _employees_by_ID.insert(data, ID);
        _employees_by_salary.insert(data, s_k);
    }

    void update_tree(AvlTree new_by_ID, AvlTree new_by_salery){
        //maybe we want to only allow add and remove?
    }



    companyData update(companyData new_data){
        this.update_value(new_data.get_value());
        this.update_size(new_data.get_size());
        //AVL should be update too
    };
};


#endif //HW1_COMPANYDATA_H
