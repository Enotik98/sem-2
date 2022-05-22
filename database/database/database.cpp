#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include "database.hpp"
#include "employee.hpp"
using namespace std;

Database::Database(){
    used = 0;
    capacity = 5;
    data = new Employee[capacity];
}

Database::Database(const Database& other){
    used = other.used;
    capacity = other.capacity;
    data = new Employee[capacity];
    copy(other.data,other.data+used,data);
}

Database::~Database(){
    delete[]data;
}

void Database::operator =(const Database& other){
    if(&other == this){
        return;
    }
    
    delete[]data;
    
    capacity = other.capacity;
    used = other.used;
    data = new Employee[capacity];
    copy(other.data,other.data+used,data);
}

void Database::makeBigger(){
    
    Employee *tmp;
    tmp = new Employee[capacity+5];
    
    copy(data, data+used,tmp);
    delete []data;
    data = tmp;
    capacity +=5;
}
int Database::search(std::string name){
    
    int num_found = 0;
    
    for(int i=0; i<used;i++){
        if(data[i].get_name() == name){
            cout << "Found Employee!" << endl;
            data[i].output(cout);
            num_found+=1;
        }
    }
    
    if(num_found == 0){
        cout << "No Employee by that name" << endl;
    }
    return num_found;
}
int Database::search_id(int id){
    int num_found = 0;
    
    for(int i=0; i<used;i++){
        if(data[i].get_id_emp() == id){
            cout << "Employee Found!" << endl;
            data[i].output(cout);
            num_found++;
        }
    }
    if(num_found == 0){
        cout << "No employee with that ID number!" << endl;
    }
    return num_found;
}
void Database::add(const Employee& emp){
    if(used >= capacity){
        makeBigger();
    }
    
    data[used] = emp;
    used++;
}
void Database::save(std::ostream& outs){
    for(int i=0; i < used; i++){
        outs << data[i];
    }
}
void Database::display_all(){
    for(int i=0;i<used;i++){
        data[i].output(cout);
    }
}
void Database::remove(std::string name){
    for(int i=0; i < used; i++){
        if(data[i].get_name() == name){
            data[i] = data[used-1];
            used--;
        }
    }
}

void Database::load(std::istream& ins){
    Employee tmp;
    
    while(ins >> tmp){
        if(used >= capacity){
            makeBigger();
        }
        data[used] = tmp;
        used++;
    }
}
void Database::sort_by_name()
{
    bool done = false;
    Employee tmp;
    while(!done)
    {
        done = true;
        for(int i=0;i<used-1;i++)
        {
            if(data[i].get_name() > data[i+1].get_name())
            {
                done = false;
                tmp = data[i];
                data[i] = data[i+1];
                data[i+1] = tmp;
            }
        }
    }
}
void Database::sort_by_salary()
{
    bool done = false;
    Employee tmp;
    while(!done)
    {
        done = true;
        for(int i=0;i<used-1;i++)
        {
            if(data[i].get_salary() < data[i+1].get_salary())
            {
                done = false;
                tmp = data[i];
                data[i] = data[i+1];
                data[i+1] = tmp;
            }
        }
    }
}
