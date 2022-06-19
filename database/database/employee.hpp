#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include <string>
/**
 @class Employee
 */
class Employee
{
    private:
    ///name
        std::string name;
    ///addres
        std::string address;
    ///id employee
        int id_emp;
    ///salary
        double salary;
    ///year sinceemloyee started working
        int year_started;
    public:
    ///Constructor zero
        Employee();
    ///Main Constructor
        Employee(std::string new_name, std::string new_address, int new_id,double new_salary, int new_years_worked);
    ///@return name this employee
        std::string get_name() const{return name;}
    ///@return address this employee
        std::string get_address() const{return address;}
    ///@return id this employee
        int get_id_emp() const{return id_emp;}
    ///@return salary this employee
        double get_salary() const{return salary;}
    ///@return year this employee
        int get_years_started() const{return year_started;}
    ///dowload information
        void output(std::ostream& outs);
    ///put indormation
        void input(std::istream& ins);
    
};
///out  file
std::ostream& operator <<(std::ostream& outs, Employee& tmp);
///in file
std::istream& operator >>(std::istream& ins, Employee& tmp);
#endif
