#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include <string>
class Employee
{
    private:
        std::string name;
        std::string address;
        int id_emp;
        double salary;
        int year_started;
    public:
        Employee();
        Employee(std::string new_name, std::string new_address, int new_id,double new_salary, int new_years_worked);
    
        std::string get_name() const{return name;}
        std::string get_address() const{return address;}
        int get_id_emp() const{return id_emp;}
        double get_salary() const{return salary;}
        int get_years_started() const{return year_started;}
        void output(std::ostream& outs);
        void input(std::istream& ins);
    
};
std::ostream& operator <<(std::ostream& outs, Employee& tmp);
std::istream& operator >>(std::istream& ins, Employee& tmp);
#endif
