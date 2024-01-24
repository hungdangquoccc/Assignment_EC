#include <iostream>
#include <vector>
#include "student.h"

using namespace std;

enum menu_t{
    menu_exit   = 0,
    menu_add    = 1,
    //menu_delete = 2,
    menu_show   = 3,
    menu_number_regular    = 4,
    //menu_max_entrancescore = 5,
    menu_hide = 9,
};

int main() {
    Department cntt;
    menu_t choice;
    int x;
    Student * t;
    do{
        system("cls");
        cout << "1. Add\n2. Delete\n3. Show\n4. Number of regular\n0. Exit\nChoice: " << endl;
        cin >> x;
        cin.ignore();
        choice = (menu_t)x;
        switch (choice)
        {
        case menu_add: 
            cntt.addStudent();
            break;
        case menu_show: 
            cntt.displayStudents();
            break;
        case menu_exit:
            cout << "Exit...\n";
            break;
        case menu_number_regular:
            cout << "Number of regular students: " << cntt.getNumberRegular() << endl;
            break;
        case menu_hide:
            t = new RegularStudent("123", "ng ng ng", 2018, 78);
            cntt.addStudent(t);
            t = new PartTimeStudent("123", "ng ng ng", 2017, 80, "Ha Noi");
            cntt.addStudent(t);
            break;
        default:
            cout << "Wrong...\n";
            break;
        }
        system("pause");
    }while(x != 0);

    return 0;
}