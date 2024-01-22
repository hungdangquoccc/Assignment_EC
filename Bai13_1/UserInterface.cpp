#include "UserInterface.h"

using namespace std;

void UserInterface::getUserChoice() {
    int choice;

    cout << "Choose employee type:" << endl;
    cout << "1. Fresher" << endl;
    cout << "2. Experience" << endl;
    cout << "3. Intern" << endl;
    cout << "Enter your choice (1-3): ";
    cin >> choice;
    cout << "\n";
    switch (choice) {
        case 1:
            manager.addFresher();
            break;
        case 2:
            manager.addExperience();
            break;
        case 3:
            manager.addIntern();
            break;
        default:
            cerr << "Invalid choice. Defaulting to Fresher." << endl;
            break;
    }
}

void UserInterface::run() {
    int choice;
    while (true) {
        cout << "-----------------------------------------\n";
        cout << "Choice: \n";
        cout << "1 - Add Employee\n" << "2 - Print\n" << "3 - Edit: \n";
        cout << "-----------------------------------------\n";
        cin >> choice;

        switch (choice) {
            case 1:
                getUserChoice();
                break;
            case 2:
                cout << "-----------------------------------------\n";
                int printChoice;
                cout << "Choose how to print\n";
                cout << "1 - Show All Employee" << endl << "2 - Print All Fresher" << endl << "3 - Print All Experience\n" << "4 - Print All Intern: \n";
                cin >> printChoice;
                switch (printChoice) {
                    case 1:
                        manager.printAllEmployees();
                        break;
                    case 2:
                        manager.printAllFresher();
                        break;
                    case 3:
                        manager.printAllExPerience();
                        break;
                    case 4:
                        manager.printAllIntern();
                        break;
                    default:
                        break;
                }
                break;

            case 3:
                int ID;
                cout << "Enter ID Employee need to Edit: ";
                cin >> ID;
                manager.edit(ID);
                break;
            default:
                cout << "Invalid Choice" << endl;
                break;
        }
    }
}
