//
// Created by shoha on 28/04/2022.
//

#ifndef HW1_SALARYKEY_H
#define HW1_SALARYKEY_H


class salaryKey {
private:
    int _salary;
    int ID;

public:
    salaryKey(const int salary, const int ID){
        _salary = salary;
        this->ID = ID;
    }

    //getters
    int salary()const{
        return _salary;
    }
    int getID()const{
        return ID;
    }

    void update_salary(const int salary){
        _salary = salary;
    }

    friend bool operator<(const salaryKey& k1, const salaryKey& k2){
        return ( (k1.salary() < k2.salary()) || ( (k1.salary() == k2.salary()) && (k1.getID() > k2.getID()) ) );
    }

    friend bool operator==(const salaryKey& k1, const salaryKey& k2){
        return ( (k1.salary() == k2.salary()) && (k1.getID() == k2.getID() ) );
    }

};

inline bool operator>(const salaryKey& k1, const salaryKey& k2){ return (k2 < k1); }
inline bool operator<=(const salaryKey& k1, const salaryKey& k2){ return !(k1 > k2); }
inline bool operator>=(const salaryKey& k1, const salaryKey& k2){ return !(k1 < k2); }
inline bool operator!=(const salaryKey& k1, const salaryKey& k2){ return !(k1 == k2); }

#endif //HW1_SALARYKEY_H
