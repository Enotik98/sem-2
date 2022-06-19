#ifndef DATABASE_H
#define DATABASE_H
#include "employee.hpp"
/**
 @class Database
 */
class Database
{
private:
    ///Function make a biger base when add new employeer
    void makeBigger();
    int capacity;
    ///Class Employee
    Employee *data;
    int used;
    
public:
    ///Constructor zero
    Database();
    ///Destructor
    ~Database();
    ///Main constructor
    Database(const Database& other);
    ///

    ///Function change number
    void resize();
    ///Function craet new Employee in base
    void add(const Employee& emp);
//  void search(std::string name);
    ///Search by name
    int search(std::string name);
//  void search_id(int id);
    ///Search by id in base
    int search_id(int id);
    ///Show all information
    void display_all();
    ///Remove Employee by name
    void remove(std::string name);
    ///Save base in file
    void save(std::ostream& outs);
    ///Download information from a file
    void load(std::istream& ins);
    ///Sort by name
    void sort_by_name();
    ///Sort by salary
    void sort_by_salary();
};
#endif
