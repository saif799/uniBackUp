#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>
using namespace std;
string ename;
string job;
string hiredate;
string dname, loc;
string deptno;
string empno;
string mgr;
string sal;
string comm;
void CreatBdEmp(string s)
{
    ofstream employe;
    employe.open(s);
    if (employe.is_open())
    {
        employe << left << setw(10) << "empno";
        employe << left << setw(10) << "ename";
        employe << left << setw(10) << "job";
        employe << left << setw(10) << "mgr";
        employe << left << setw(10) << "hiredate";
        employe << left << setw(7) << "sal";
        employe << left << setw(7) << "comm";
        employe << left << setw(7) << "deptno\n";
        employe << "--------------------------------------------------------------------------\n";

        employe.close();
    }
}
void CreatBdDep(string s)
{
    ofstream employe;
    employe.open(s);
    if (employe.is_open())
    {
        employe << left << setw(15) << "deptno" << setw(15) << "dname" << setw(10) << "loc\n";
        employe.close();
    }
}
void FindDep(string input_file)
{
    string find_departement;
    cout << "give the number of the department you want to find : ";
    cin >> find_departement;
    ifstream in(input_file);
    string deprtement_found;
    if (in.is_open())
    {
        while (getline(in, deprtement_found))
        {
            if (deprtement_found.find(find_departement) != string::npos)
            {
                cout << "this is your department : " << endl
                     << deprtement_found << endl;
            }
        }
        in.close();
    }
}
void AddDep(string where)
{
    fstream department;
    int state = 0;
    department.open(where, ios::app);
    if (department.is_open())
    {
        cout << "Enter this : deptno  dname  loc : " << endl;
        cin >> deptno >> dname >> loc;

        department << left << setw(15) << deptno;
        department << left << setw(15) << dname;
        department << left << setw(10) << loc << endl;
        department.close();
    }
}
void AddEmp(string where)
{
    fstream employe;
    employe.open(where, ios::app);
    if (employe.is_open())
    {
        cout << "Enter this : empno  ename job mgr  hiredate  sal  comm  deptno : " << endl;
        cin >> empno >> ename >> job >> mgr >> hiredate >> sal >> comm >> deptno;
        employe << left << setw(10) << empno << setw(10) << ename << setw(10);
        employe << left << job;
        employe << left << setw(10) << mgr;
        employe << left << setw(10) << hiredate;
        employe << left << setw(7) << sal;
        employe << left << setw(7) << comm;
        employe << left << setw(7) << deptno << endl;
        employe.close();
    }
}
void DeleteEmp(string input_file)
{

    string output_file = "output.txt";
    string text_to_delete;
    cout << "give me the number of the employe you want to delete : ";
    cin >> text_to_delete;
    ifstream in(input_file);
    ofstream out(output_file);
    string line;
    while (getline(in, line))
    {
        if (line.find(text_to_delete) != string::npos)
        {
            continue;
        }
        out << line << endl;
    }
    in.close();
    out.close();
    remove(input_file.c_str());
    rename(output_file.c_str(), input_file.c_str());
}
void menu()
{
    int choix;
    string filename;
    do
    {
        cout << "**************MENU*******************" << endl;
        cout << "  1- Creat database of epmloyees." << endl;
        cout << "  2- Creat databas of departments." << endl;
        cout << "  3- Add an employee." << endl;
        cout << "  4- add a department." << endl;
        cout << "  5- Delete an emloyee." << endl;
        cout << "  6- Find a department" << endl;
        cout << "  7- Exit." << endl;
        cout << "Donner votre choix? ";
        cin >> choix;
        switch (choix)
        {
        case 1:
            cout << "choose file name : ";
            cin >> filename;
            CreatBdEmp(filename);
            break;
        case 2:
            cout << "choose file name : ";
            cin >> filename;
            CreatBdDep(filename);
            break;
        case 3:
            cout << "choose file name : ";
            cin >> filename;
            AddEmp(filename);
            break;
        case 4:
            cout << "choose file name : ";
            cin >> filename;
            AddDep(filename);
            break;
        case 5:
            cout << "choose file name : ";
            cin >> filename;
            DeleteEmp(filename);
            break;
        case 6:
            cout << "choose file name : ";
            cin >> filename;
            FindDep(filename);
            break;

        default:
            break;
        }

    } while (choix != 7);
}
int main()
{
    menu();
}