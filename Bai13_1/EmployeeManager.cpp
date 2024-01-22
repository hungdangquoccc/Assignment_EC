#include "EmployeeManager.h"

EmployeeManager::EmployeeManager() {}

std::vector<Certificate*> EmployeeManager::inputCertificates() {
    std::vector<Certificate*> certificates;

    int certificateCount;
    try
    {
        std::cout << "Enter number of certificates: ";
        std::cin >> certificateCount;

        if (!isValidInteger(certificateCount)) {
            throw "Invalid certificateCount";
        }
    }
    catch(const char* e) {
        std::cout << "Error: " << e << std::endl;
    }

    for (int i = 0; i < certificateCount; ++i) {
        int certID;
        std::string certName, certRank, certDate;

        std::cout << "\tEnter Certificate ID: ";
        std::cin >> certID;

        std::cout << "\tEnter Certificate Name: ";
        std::cin.ignore();
        std::getline(std::cin, certName);

        std::cout << "\tEnter Certificate Rank: ";
        std::cin >> certRank;

        std::cout << "\tEnter Certificate Date: ";
        std::cin >> certDate;
        std::cout << "\n";

        Certificate* cert = new Certificate(certID, certName, certRank, certDate);
        certificates.push_back(cert);
    }

    return certificates;
}

bool EmployeeManager::isValidInteger(int number) {
    return number > 0;
}

bool EmployeeManager::isValidPhoneNumber(const std::string& phoneNumber) {
    regex pattern("(\\+84|0)\\d{9,10}");
    return regex_match(phoneNumber,pattern);
}

bool EmployeeManager::IsValidDateOfBirth(const std::string& dateOfBirth) {
    regex pattern("\\d{2}/\\d{2}/\\d{4}");
        if (!regex_match(dateOfBirth, pattern)) 
        {
            return false;
        }
        int day, month, year;
        sscanf(dateOfBirth.c_str(), "%d/%d/%d", &day, &month, &year);

        if (day < 1 || day > 31 || month < 1 || month > 12 || year < 1900) 
        {
            return false;
        }
        
        if ((day == 31) && (month == 2 || month == 4 || month == 6 || month == 9 || month == 11)) 
        {
            return false;
        }

        if (month == 2) 
        {
            bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
            if ((day > 29) || (day == 29 && !isLeapYear)) 
            {
                return false;
            }
        }

        return true;
}

bool EmployeeManager::IsValidEmail(const std::string& email) {
    regex emailRegex("[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,}");
    return regex_match(email, emailRegex);
}

bool EmployeeManager::IsValidName(const std::string& name) {
        regex nameRegex("[A-Za-z\\s]+");
        return regex_match(name, nameRegex);
}

// void EmployeeManager::add(Employee *employee) {
//     employees.push_back(employee);
// }

void EmployeeManager::addFresher() {
    int ID;
    string fullName, birdDay, phone, email, graduationDate, graduationRank, education;

    try {
        cout << "Enter ID: ";
        cin >> ID;
        if (!isValidInteger(ID)) {
            throw "Invalid ID";
        }

        cout << "Enter Full Name: ";
        cin.ignore();
        getline(cin, fullName);
        if (!IsValidName(fullName)) {
            throw "Invalid name";
        }

        cout << "Enter Birth Day: ";
        cin >> birdDay;
        if (!IsValidDateOfBirth(birdDay)) {
            throw "Invalid date of birth";
        }

        cout << "Enter Phone: ";
        cin >> phone;
        if (!isValidPhoneNumber(phone)) {
            throw "Invalid phone";
        }

        cout << "Enter Email: ";
        cin >> email;
        if (!IsValidEmail(email)) {
            throw "Invalid email";
        }

        vector<Certificate*> certificates = inputCertificates();

        cout << "Enter Graduation Date: ";
        cin >> graduationDate;
        cout << "Enter Graduation Rank: ";
        cin >> graduationRank;
        cout << "Enter Education: ";
        cin.ignore();
        getline(cin, education);

        Fresher* fresher = new Fresher(ID, fullName, birdDay, phone, email, certificates,
                                      graduationDate, graduationRank, education, FRESHER);
        employees.push_back(fresher);
        cout << "Fresher added successfully." << endl;
    }
    catch (const char* e) {
        cout << "Error: " << e << endl;
    }
}

void EmployeeManager::addExperience() {
    int ID;
    string fullName, birdDay, phone, email, proSkill;
    short expInYear;

    try {
        cout << "Enter ID: ";
        cin >> ID;
        if (!isValidInteger(ID)) {
            throw "Invalid ID";
        }

        cout << "Enter Full Name: ";
        cin.ignore();
        getline(cin, fullName);
        if (!IsValidName(fullName)) {
            throw "Invalid name";
        }

        cout << "Enter Birth Day: ";
        cin >> birdDay;
        if (!IsValidDateOfBirth(birdDay)) {
            throw "Invalid date of birth";
        }

        cout << "Enter Phone: ";
        cin >> phone;
        if (!isValidPhoneNumber(phone)) {
            throw "Invalid phone";
        }

        cout << "Enter Email: ";
        cin >> email;
        if (!IsValidEmail(email)) {
            throw "Invalid email";
        }

        vector<Certificate*> certificates = inputCertificates();

        cout << "Enter Experience in Years: ";
        cin >> expInYear;
        cout << "Enter Professional Skill: ";
        cin.ignore();
        getline(cin, proSkill);

        Experience* experience = new Experience(ID, fullName, birdDay, phone, email, certificates,
                                                expInYear, proSkill, EXPERIENCE);
        employees.push_back(experience);
        cout << "Experience added successfully." << endl;
    }
    catch (const char* e) {
        cout << "Error: " << e << endl;
    }
}

void EmployeeManager::addIntern() {
    int ID;
    string fullName, birdDay, phone, email;

    try {
        cout << "Enter ID: ";
        cin >> ID;
        if (!isValidInteger(ID)) {
            throw "Invalid ID";
        }

        cout << "Enter Full Name: ";
        cin.ignore();
        getline(cin, fullName);
        if (!IsValidName(fullName)) {
            throw "Invalid name";
        }

        cout << "Enter Birth Day: ";
        cin >> birdDay;
        if (!IsValidDateOfBirth(birdDay)) {
            throw "Invalid date of birth";
        }

        cout << "Enter Phone: ";
        cin >> phone;
        if (!isValidPhoneNumber(phone)) {
            throw "Invalid phone";
        }

        cout << "Enter Email: ";
        cin >> email;
        if (!IsValidEmail(email)) {
            throw "Invalid email";
        }

        vector<Certificate*> certificates = inputCertificates();

        string major, universityName;
        int semester;
        cout << "Enter Major: ";
        cin.ignore();
        getline(cin, major);
        cout << "Enter Semester: ";
        cin >> semester;
        cout << "Enter University Name: ";
        cin.ignore();
        getline(cin, universityName);

        Intern* intern = new Intern(ID, fullName, birdDay, phone, email, certificates,
                                   major, semester, universityName, INTERN);
        employees.push_back(intern);
        cout << "Intern added successfully." << endl;
    }
    catch (const char* e) {
        cout << "Error: " << e << endl;
    }
}
void EmployeeManager::printAllFresher()
    {
        for (const auto &employee : employees)
        {
            if (employee->getEmployeeType() == FRESHER)
                employee->ShowInfo();
        }
    }

 void EmployeeManager::printAllExPerience()
    {
        for (const auto &employee : employees)
        {
            if (employee->getEmployeeType() == EXPERIENCE)
                employee->ShowInfo();
        }
    }

void EmployeeManager::printAllIntern()
    {
        for (const auto &employee : employees)
        {
            if (employee->getEmployeeType() == INTERN)
                employee->ShowInfo();
        }
    }

void EmployeeManager::printAllEmployees()
    {
        for (const auto &employee : employees)
        {
            employee->ShowInfo();
        }
    }
void EmployeeManager::edit(int employeeID)
    {
        for (auto &employee : employees)
        {
            if (employee->getID() == employeeID)
            {
                // Display the current information
                cout << "Current Information:" << endl;
                employee->ShowInfo();

                // Ask for new information
                cout << "\nEnter new information:" << endl;

                // Assuming you want to edit all fields, you can call the set functions accordingly
                // You might want to add validation or error handling here
                string newName, newBirdDay, newPhone, newEmail;
                cout << "Enter new Full Name: ";
                getline(cin, newName);
                employee->setFullName(newName);

                cout << "Enter new Birth Day: ";
                getline(cin, newBirdDay);
                employee->setBirdDay(newBirdDay);

                cout << "Enter new Phone: ";
                getline(cin, newPhone);
                employee->setPhone(newPhone);

                cout << "Enter new Email: ";
                getline(cin, newEmail);
                employee->setEmail(newEmail);

                // Display the updated information
                cout << "\nUpdated Information:" << endl;
                employee->ShowInfo();

                return; // Once edited, exit the function
            }
        }

        // If the ID is not found
        cout << "Employee with ID " << employeeID << " not found." << endl;
    }


