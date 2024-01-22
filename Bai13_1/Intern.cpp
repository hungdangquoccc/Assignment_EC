#include "Intern.h"

Intern::Intern(int ID, std::string FullName, std::string BirdDay, std::string phone, std::string Email, std::vector<Certificate *> Certificates,
               std::string Major, int Semester, std::string UniversityName, Employee_Type EmployeeType)
    : Employee(ID, FullName, BirdDay, phone, Email, Certificates, EmployeeType) {
    this->Major = Major;
    this->Semester = Semester;
    this->UniversityName = UniversityName;
}

std::string Intern::getMajor() {
    return Major;
}

void Intern::setMajor(std::string Major) {
    this->Major = Major;
}

int Intern::getSemester() {
    return Semester;
}

void Intern::setSemester(int Semester) {
    this->Semester = Semester;
}

std::string Intern::getUniversityName() {
    return UniversityName;
}

void Intern::setUniversityName(std::string UniversityName) {
    this->UniversityName = UniversityName;
}

void Intern::ShowInfo() {
    Employee::ShowInfo();
    std::cout << "Major: " << getMajor() << std::endl;
    std::cout << "Semester: " << getSemester() << std::endl;
    std::cout << "UniversityName: " << getUniversityName() << std::endl;
}
