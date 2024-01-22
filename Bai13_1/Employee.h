#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Certificate.h"

enum Employee_Type{
    EXPERIENCE = 0,
    FRESHER,
    INTERN
};

class Employee {
private:
    int ID;
    std::string FullName;
    std::string BirdDay;
    std::string Phone;
    std::string Email;
    std::vector<Certificate *> Certificates;
    Employee_Type EmployeeType;

public:
    static int EmployeeCount;

    Employee(int ID, std::string FullName, std::string BirdDay, std::string phone, std::string Email, std::vector<Certificate *> &Certificates, Employee_Type EmployeeType);

    int getID();
    void setID(int ID);

    std::string getFullName();
    void setFullName(std::string FullName);

    std::string getBirdDay();
    void setBirdDay(std::string BirdDay);

    std::string getPhone();
    void setPhone(std::string phone);

    std::string getEmail();
    void setEmail(std::string email);

    std::vector<Certificate *> getCertificates();
    void setCertificates(std::vector<Certificate *> &Certificates);

    Employee_Type getEmployeeType();

    virtual void ShowInfo();
};

