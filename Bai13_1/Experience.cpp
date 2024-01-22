#include "Experience.h"

Experience::Experience(int ID, std::string FullName, std::string BirdDay, std::string phone, std::string Email, std::vector<Certificate *> &Certificates,
                       short ExpInYear, std::string ProSkill, Employee_Type EmployeeType)
    : Employee(ID, FullName, BirdDay, phone, Email, Certificates, EmployeeType) {
    this->ExpInYear = ExpInYear;
    this->ProSkill = ProSkill;
}

short Experience::getExpInYear() {
    return ExpInYear;
}

void Experience::setExpInYear(short ExpInYear) {
    this->ExpInYear = ExpInYear;
}

std::string Experience::getProSkill() {
    return ProSkill;
}

void Experience::setProSkill(std::string ProSkill) {
    this->ProSkill = ProSkill;
}

void Experience::ShowInfo() {
    Employee::ShowInfo();
    std::cout << "ExpInYear: " << getExpInYear() << std::endl;
    std::cout << "ProSkill: " << getProSkill() << std::endl;
}
