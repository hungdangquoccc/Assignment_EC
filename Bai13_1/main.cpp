#pragma once
#include "EmployeeManager.h"
#include "UserInterface.h"

int main() {

    UserInterface test;
    test.run();   

    cout << "Sum People: "<< Employee::EmployeeCount << endl;

    return 0;
}
