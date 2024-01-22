#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "EmployeeManager.h"

class UserInterface {
private:
    EmployeeManager manager;

public:
    void getUserChoice();
    void run();
};
