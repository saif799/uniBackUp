#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>
using namespace std;
struct student
{
    char fullname[30];
    char id[12];
    float asd3;
    float ado;
    float si;
    float tg;
    float lm;
    float mn;
    float en;
    int credit;
    float moy;
};
bool compare(float a, float b, bool above)
{
    // this function returns the result of a 'operation' b, it depends on the parameter above
    //                                   //^ the order is strictly respected
    if (above)
        return a > b;
    return a < b;
}
void basic_display()
{
    fstream file;
    file.open("ranked_students_list.bin", ios::in | ios::binary);
    student *in_bin_ob = new student();
    int i = 1;
    while (!file.eof())
    {
        file.read((char *)in_bin_ob, sizeof(student));
        cout << left << setw(4) << i << "-" << setw(30) << in_bin_ob->fullname << setw(15) << in_bin_ob->id << setw(15) << in_bin_ob->asd3 << setw(15) << in_bin_ob->ado << setw(15) << in_bin_ob->si << setw(15) << in_bin_ob->tg << setw(15) << in_bin_ob->lm << setw(15) << in_bin_ob->mn << setw(15) << in_bin_ob->en << setw(15) << in_bin_ob->credit << setw(15) << in_bin_ob->moy << endl;
        i++;
    }
    file.close();
}
void my_rank()
{
    cout << "\nEnter your student ID : ";
    char id[13];
    cin >> id;
    fstream file;
    file.open("ranked_students_list.bin", ios::in | ios::binary);
    student *in_bin_ob = new student();
    int i = 1;

    while (!file.eof())
    {
        file.read((char *)in_bin_ob, sizeof(student));
        if (strcmp(in_bin_ob->id, id) == 0)
        {
            cout << "your rank : " << i << endl;
        }
        i++;
    }
    file.close();
}
void module_based_list(int module)
{
    vector<string> modules = {"ASD3", "ADO", "SI", "TG", "LM", "MN", "EN"};
    cout << "Enter the limit : ";
    float li;
    cin >> li;
    cout << "Do you want the list above or under your limit ?\n0-under\n1-above :";
    bool above;
    cin >> above;
    cout << "students who got above " << li << " in " << modules[module - 1] << " : \n";
    fstream file;
    int i = 1;
    file.open("ranked_students_list.bin", ios::in | ios::binary);
    student *in_bin_ob = new student();
    switch (module)
    {
    case 1:
        while (!file.eof())
        {
            file.read((char *)in_bin_ob, sizeof(student));
            if (compare(in_bin_ob->asd3, li, above))
            {
                cout << left << setw(30) << in_bin_ob->fullname << modules[module - 1] << " mark : " << in_bin_ob->asd3 << endl;
            }
        }
        break;
    case 2:
        while (!file.eof())
        {
            file.read((char *)in_bin_ob, sizeof(student));
            if (in_bin_ob->ado, li, above)
            {
                cout << left << setw(30) << in_bin_ob->fullname << modules[module - 1] << " mark : " << in_bin_ob->ado << endl;
            }
        }
        break;
    case 3:
        while (!file.eof())
        {
            file.read((char *)in_bin_ob, sizeof(student));
            if (in_bin_ob->si, li, above)
            {
                cout << left << setw(30) << in_bin_ob->fullname << modules[module - 1] << " mark : " << in_bin_ob->si << endl;
            }
        }
        break;
    case 4:
        while (!file.eof())
        {
            file.read((char *)in_bin_ob, sizeof(student));
            if (in_bin_ob->tg, li, above)
            {
                cout << left << setw(30) << in_bin_ob->fullname << modules[module - 1] << " mark : " << in_bin_ob->tg << endl;
            }
        }
        break;
    case 5:
        while (!file.eof())
        {
            file.read((char *)in_bin_ob, sizeof(student));
            if (in_bin_ob->lm, li, above)
            {
                cout << left << setw(30) << in_bin_ob->fullname << modules[module - 1] << " mark : " << in_bin_ob->lm << endl;
            }
        }
        break;
    case 6:
        while (!file.eof())
        {
            file.read((char *)in_bin_ob, sizeof(student));
            if (in_bin_ob->mn, li, above)
            {
                cout << left << setw(30) << in_bin_ob->fullname << modules[module - 1] << " mark : " << in_bin_ob->mn << endl;
            }
        }
        break;
    case 7:
        while (!file.eof())
        {
            file.read((char *)in_bin_ob, sizeof(student));
            if (in_bin_ob->en, li, above)
            {
                cout << left << setw(30) << in_bin_ob->fullname << modules[module - 1] << " mark : " << in_bin_ob->en << endl;
            }
        }
        break;
    default:
        break;
    }
    file.close();
}
void better_than()
{
    cout << "\nEnter a student ID : ";
    char id[13];
    cin >> id;
    fstream file;
    file.open("ranked_students_list.bin", ios::in | ios::binary);
    student *in_bin_ob = new student();
    cout << "list of student who got better marks than ";
    while (!file.eof())
    {
        file.read((char *)in_bin_ob, sizeof(student));
        if (strcmp(in_bin_ob->id, id) == 0)
        {
            cout << in_bin_ob->moy;
            break;
        }
    }
    cout << " : \n";
    file.close();
    file.open("ranked_students_list.bin", ios::in | ios::binary);
    while (!file.eof())
    {
        file.read((char *)in_bin_ob, sizeof(student));
        cout << "student : " << in_bin_ob->fullname << " moy : " << in_bin_ob->moy << endl;
        if (strcmp(in_bin_ob->id, id) == 0)
        {
            cout << "your student : " << in_bin_ob->fullname << " moy : " << in_bin_ob->moy << endl;
            break;
        }
    }
    file.close();
}
void html_creator()
{
    fstream binfile, html;
    binfile.open("ranked_students_list.bin", ios::in | ios::binary);
    html.open("students_list.html", ios::out);
    html << "<!DOCTYPE html>\n<html> <head><link rel=" << '"' << "stylesheet" << '"' << " href=" << '"' << "students_list.css" << '"' << ">    <title>Document</title>\n</head>\n<body>\n<section>\n<h1>Sorted students list</h1><table>";
    html << "  <input type=" << '"' << "text" << '"' << "id=" << '"' << "search" << '"' << "placeholder=" << '"' << "enter the student name" << '"' << ">";
    html << "<tr><th>Rank</th><th>Full name</th><th>ID</th><th>ASD3</th><th>ADO</th><th>SI</th><th>TG</th><th>LM</th><th>MN</th><th>EN</th><th>Credit</th><th>Global Mark</th><th>DeleteBtn</th></tr>\n";
    student *in_bin_ob = new student();
    int i = 1;
    while (!binfile.eof())
    {
        html << "<tr>\n";
        binfile.read((char *)in_bin_ob, sizeof(student));
        html << "<td>"
             << i << "</td>\n"
             << "<td>"
             << in_bin_ob->fullname << "</td>\n"
             << "<td>"
             << in_bin_ob->id << "</td>\n"
             << "<td>"
             << in_bin_ob->asd3 << "</td>\n"
             << "<td>"
             << in_bin_ob->ado << "</td>\n"
             << "<td>"
             << in_bin_ob->si << "</td>\n"
             << "<td>"
             << in_bin_ob->tg << "</td>\n"
             << "<td>"
             << in_bin_ob->lm << "</td>\n"
             << "<td>"
             << in_bin_ob->mn << "</td>\n"
             << "<td>"
             << in_bin_ob->en << "</td>\n"
             << "<td>"
             << in_bin_ob->credit << "</td>\n"
             << "<td>"
             << in_bin_ob->moy << "</td>\n"
             << endl;
        html << "\n<td class=" << '"' << "deleteBtn" << '"' << ">DELETE</td>";

        html << "</tr>\n";
        i++;
    }
    html << "</table>\n </section> <script src=" << '"' << "app.js" << '"'
         << "></script></body>\n</html>";
}
int main()
{

    int ch;
    cout << "***********************************Menu***********************************" << endl;
    cout << "1-creat a html page with the name of 'students_list.html' that contains all the students ranked +you can search in it " << endl;
    cout << "2-display a list of students who got mark better than a specific student" << endl;
    cout << "3-display your rank" << endl;
    cout << "4-display students who got higher or lower mark than a specific mark in a specific module" << endl;
    cin >> ch;
    switch (ch)
    {
    case 1:
        system("cls");
        cout << "- creat a html page with the name of 'students_list.html' that contains all the students ranked +you can search in it" << endl;
        html_creator();
        break;
    case 2:
        system("cls");
        cout << "- displaying a list of students who got mark better than a specific student" << endl;
        better_than();
        break;
    case 3:
        system("cls");
        cout << "- display your rank" << endl;
        my_rank();
        break;
    case 4:
        system("cls");
        cout << "- displaying students who got higher or lower mark than a specific mark in a specific module" << endl;
        cout << "Modules :\n1-ASD3  2-ADO   3-SI    4-TG    5-LM    6-MN    7-EN\n";
        int mod;
        cout << "Choose a module : ";
        cin >> mod;
        module_based_list(mod);
        break;
    default:;
    }
    html_creator();
}