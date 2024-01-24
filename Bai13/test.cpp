#include <iostream>

class UserInterface {
private:
    EmployeeManager manager;

public:
    void getUserChoice() {
        int choice;
        
        std::cout << "Choose employee type:" << std::endl;
        std::cout << "1. Fresher" << std::endl;
        std::cout << "2. Experience" << std::endl;
        std::cout << "3. Intern" << std::endl;
        std::cout << "Enter your choice (1-3): ";

        while (!(std::cin >> choice) || choice < 1 || choice > 3) {
            std::cout << "Invalid choice. Please enter a number between 1 and 3: ";
            std::cin.clear(); // clear input buffer to restore cin to a usable state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore last input
        }

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
                std::cerr << "Invalid choice. Defaulting to Fresher." << std::endl;
                break;
        }
    }

    void run() {
        int choice;

        while (true) {
            std::cout << "0 - Add Employee" << std::endl;
            std::cout << "1 - Print" << std::endl;
            std::cout << "-----------------------------------------" << std::endl;
            std::cout << "Enter your choice (0-1): ";

            while (!(std::cin >> choice) || choice < 0 || choice > 1) {
                std::cout << "Invalid choice. Please enter 0 or 1: ";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }

            switch (choice) {
                case 0:
                    getUserChoice();
                    break;
                case 1:
                    manager.printAllEmployees();
                    break;
                default:
                    std::cout << "Invalid Choice" << std::endl;
                    break;
            }
        }
    }
};

int main() {
    UserInterface test;
    test.run();   

    std::cout << "Sum People: " << Employee::EmployeeCount << std::endl;

    return 0;
}
