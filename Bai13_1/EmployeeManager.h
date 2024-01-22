#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include "Employee.h"
#include "Fresher.h"
#include "Experience.h"
#include "Intern.h"

class EmployeeManager
{
private:
    std::vector<Employee *> employees;
    
    std::vector<Certificate*> inputCertificates();

public:
    EmployeeManager();

    bool isValidInteger(int number);
    bool isValidPhoneNumber(const std::string& phoneNumber);
    bool IsValidDateOfBirth(const std::string& dateOfBirth);
    bool IsValidEmail(const std::string& email);
    bool IsValidName(const std::string& name);

    // void add(Employee *employee);
    void addFresher();
    void addExperience();
    void addIntern();
    void edit(int employeeID);
    void remove(int id);
    void printAllFresher();
    void printAllExPerience();
    void printAllIntern();
    void printAllEmployees();
};
