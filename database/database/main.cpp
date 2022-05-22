#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include "employee.hpp"
#include "database.hpp"
#include <gtest/gtest.h>

using namespace std;

int menu();
void interface();



int main(int argc, const char * argv[]) {
    interface();
    return 0;
//    testing::InitGoogleTest(&argc, (char**)argv);
//       return RUN_ALL_TESTS();
}


TEST(testsearch, search){
    Database database;
    Employee emp;
    string file = "base";
    //my files are stored without extension ".txt"
    
    ifstream fin(file.c_str());
    
    database.load(fin);
    fin.close();
    string search_name = "polina";
    EXPECT_EQ(1, database.search(search_name));
}
TEST(testsearchId, search_id){
    Database database;
    Employee emp;
    //my files are stored without extension ".txt"
    
    string file = "base";
    
    ifstream fin(file.c_str());
    
    database.load(fin);
    fin.close();
    int searchId = 12;
    EXPECT_EQ(1, database.search_id(searchId));
}

void interface(){
    Database database;
    Employee emp;
    string file;
    
    cout << "Enter name of file (No file extension): ";
    getline(cin, file);
    file + ".txt";
    ifstream fin(file.c_str());
    
    if(!fin.fail()){
        database.load(fin);
        fin.close();
        int choice = 0;
        
        while(choice != 6){
            choice = menu();
            switch (choice){
                case 1:{
                    cin >> emp;
                    database.add(emp);
                    break;
                }
                case 2:{
                    string name;
                    
                    cout << "Enter name of employee to find: ";
                    if(cin.peek() == '\n'){
                        cin.ignore();
                    }
                    getline(cin,name);
                    database.search(name);
                    break;
                }
                case 3:{
                    int id_emp;
                    
                    cout << "Enter Employee ID number: ";
                    cin >> id_emp;
                    
                    database.search_id(id_emp);
                    break;
                }
                case 4:{
                    cout << "All the employees in the database!" << endl;
                    
                    database.display_all();
                    break;
                }
                case 5:{
                    string name;
                    
                    cout << "Enter employee that has been sacked: ";
                    if(cin.peek() == '\n'){
                        cin.ignore();
                    }
                    getline(cin,name);
                    database.remove(name);
                    break;
                }
                case 6:{
                    database.sort_by_name();
                    cout << "Employees sorted by first name." << endl;
                    database.display_all();
                    break;
                }
                case 7:{
                    database.sort_by_salary();
                    cout << "Employees sorted by salary." << endl;
                    database.display_all();
                    break;
                }
                case 8:{
                    break;
                }
                default:{
                    cout << "Not a valid input dummy!" << endl;
                    break;
                }
            }
        }
        
        ofstream fout(file.c_str());
        
        if(!fout.fail()){
            database.save(fout);
        }
        else{
            cout << "File could not open!" << endl;
        }
        fout.close();
        cout << "Thank you for using! COME AGAIN SOON!" << endl;
    }
    else{
        cout << "File does not exist, creating new file!" << endl;
        ofstream new_file(file.c_str());
        new_file.close();
        interface();
    }
    
}
int menu(){
    int choice = 0;
    
    cout << "1. Add new employee." << endl;
    cout << "2. Search for employee by name." << endl;
    cout << "3. Searh for employee by ID." << endl;
    cout << "4. Display all employees." << endl;
    cout << "5. Remove employee from database." << endl;
    cout << "6. Sort by first name. " << endl;
    cout << "7. Sort by salary." << endl;
    cout << "8. Quit" << endl;
    cin >> choice;
    
    return choice;
}

