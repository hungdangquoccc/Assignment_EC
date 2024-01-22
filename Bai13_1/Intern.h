#pragma once

#include "Employee.h"

class Intern : public Employee {
private:
    std::string Major;
    int Semester;
    std::string UniversityName;

public:
    Intern(int ID, std::string FullName, std::string BirdDay, std::string phone, std::string Email, std::vector<Certificate *> Certificates,
           std::string Major, int Semester, std::string UniversityName, Employee_Type EmployeeType);

    std::string getMajor();
    void setMajor(std::string Major);

    int getSemester();
    void setSemester(int Semester);

    std::string getUniversityName();
    void setUniversityName(std::string UniversityName);

    void ShowInfo() override;
};
