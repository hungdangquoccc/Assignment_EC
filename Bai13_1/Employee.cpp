#include "Employee.h"

int Employee::EmployeeCount = 0;

Employee::Employee(int ID, std::string FullName, std::string BirdDay, std::string phone, std::string Email, std::vector<Certificate *> &Certificates, Employee_Type EmployeeType) {
    this->ID = ID;
    this->FullName = FullName;
    this->BirdDay = BirdDay;
    this->Phone = phone;
    this->Email = Email;
    this->Certificates = Certificates;
    this->EmployeeType = EmployeeType;
    EmployeeCount++;
}

int Employee::getID() {
    return ID;
}

void Employee::setID(int ID) {
    this->ID = ID;
}

std::string Employee::getFullName() {
    return FullName;
}

void Employee::setFullName(std::string FullName) {
    this->FullName = FullName;
}

std::string Employee::getBirdDay() {
    return BirdDay;
}

void Employee::setBirdDay(std::string BirdDay) {
    this->BirdDay = BirdDay;
}

std::string Employee::getPhone() {
    return Phone;
}

void Employee::setPhone(std::string phone) {
    this->Phone = Phone;
}

std::string Employee::getEmail() {
    return Email;
}

void Employee::setEmail(std::string email) {
    this->Email = email;
}

std::vector<Certificate *> Employee::getCertificates() {
    return Certificates;
}

void Employee::setCertificates(std::vector<Certificate *> &Certificates) {
    this->Certificates = Certificates;
}

Employee_Type Employee::getEmployeeType() {
    return EmployeeType;
}

void Employee::ShowInfo() {
    std::cout << "----------------------------------------------" << std::endl;
    std::cout << "Employee ID: " << getID() << std::endl;
    std::cout << "Full Name: " << getFullName() << std::endl;
    std::cout << "Birth Day: " << getBirdDay() << std::endl;
    std::cout << "Phone: " << getPhone() << std::endl;
    std::cout << "Email: " << getEmail() << std::endl;

    switch (EmployeeType) {
    case FRESHER:
        std::cout << "Employee Type: Fresher" << std::endl;
        break;
    case EXPERIENCE:
        std::cout << "Employee Type: EXPERIENCE" << std::endl;
        break;
    case INTERN:
        std::cout << "Employee Type: INTERN" << std::endl;
        break;

    default:
        break;
    }

    std::cout << "Cerificates:" << std::endl;
    for (auto &cer : Certificates) {
        std::cout << "\t" << "ID Cerificate: " << cer->GetCertificateID() << std::endl;
        std::cout << "\tCertificateName: " << cer->getCertificateName() << std::endl;
        std::cout << "\tCertificateRank: " << cer->getCertificateRank() << std::endl;
        std::cout << "\tCertificateDate: " << cer->getCertificateDate() << std::endl;
    }
}
