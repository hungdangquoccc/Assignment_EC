#pragma once

#include "Employee.h"

class Fresher : public Employee {
private:
    std::string GraduationDate;
    std::string GraduationRank;
    std::string Education;

public:
    Fresher(int ID, std::string FullName, std::string BirdDay, std::string phone, std::string Email, std::vector<Certificate *> Certificates,
            std::string GraduationDate, std::string GraduationRank, std::string Education, Employee_Type EmployeeType);

    std::string getGraDate();
    void setGraDate(std::string GraduationDate);

    std::string getGraRank();
    void setGraRank(std::string GraduationRank);

    std::string getEducation();
    void setEducation(std::string Education);

    void ShowInfo() override;
};
