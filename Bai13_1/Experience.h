#pragma once

#include "Employee.h"

class Experience : public Employee {
private:
    short ExpInYear;
    std::string ProSkill;

public:
    Experience(int ID, std::string FullName, std::string BirdDay, std::string phone, std::string Email, std::vector<Certificate *> &Certificates,
               short ExpInYear, std::string Proskill, Employee_Type EmployeeType);

    short getExpInYear();
    void setExpInYear(short ExpInYear);

    std::string getProSkill();
    void setProSkill(std::string ProSkill);

    void ShowInfo() override;
};
