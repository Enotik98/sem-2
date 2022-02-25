#ifndef DATABASE_H
#define DATABASE_H
#include "employee.hpp"
class Database
{
    private:
        void makeBigger();
        int capacity;
        Employee *data;
        int used;
    
    public:
        Database();
        ~Database();
        Database(const Database& other);
        void operator =(const Database& other);
        void resize();
        void add(const Employee& emp);
        void search(std::string name);
        void search_id(int id);
        void display_all();
        void remove(std::string name);
        void save(std::ostream& outs);
        void load(std::istream& ins);
};
#endif
