#include "Fresher.h"

Fresher::Fresher(int ID, std::string FullName, std::string BirdDay, std::string phone, std::string Email, std::vector<Certificate *> Certificates,
                 std::string GraduationDate, std::string GraduationRank, std::string Education, Employee_Type EmployeeType)
    : Employee(ID, FullName, BirdDay, phone, Email, Certificates, EmployeeType) {
    this->GraduationDate = GraduationDate;
    this->GraduationRank = GraduationRank;
    this->Education = Education;
}

std::string Fresher::getGraDate() {
    return GraduationDate;
}

void Fresher::setGraDate(std::string GraduationDate) {
    this->GraduationDate = GraduationDate;
}

std::string Fresher::getGraRank() {
    return GraduationRank;
}

void Fresher::setGraRank(std::string GraduationRank) {
    this->GraduationRank = GraduationRank;
}

std::string Fresher::getEducation() {
    return Education;
}

void Fresher::setEducation(std::string Education) {
    this->Education = Education;
}

void Fresher::ShowInfo() {
    Employee::ShowInfo();
    std::cout << "GraduationDate: " << getGraDate() << std::endl;
    std::cout << "GraduationRank: " << getGraRank() << std::endl;
    std::cout << "Education: " << getEducation() << std::endl;
}
