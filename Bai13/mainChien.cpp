#include <iostream>
#include <string>
#include <vector>
#include <regex>
using namespace std;

class Certificate
{
private:
    string ID;
    string Name;
    string Rank;
    string Date;

public:
    Certificate(string _ID, string _Name, string _Rank, string _Date)
        : ID(_ID), Name(_Name), Rank(_Rank), Date(_Date) {}

    void setID(string _ID)
    {
        ID = _ID;
    }

    string getID() const
    {
        return ID;
    }

    void setName(string _Name)
    {
        Name = _Name;
    }

    string getName() const
    {
        return Name;
    }

    void setRank(string _Rank)
    {
        Rank = _Rank;
    }

    string getRank() const
    {
        return Rank;
    }

    void setDate(string _Date)
    {
        Date = _Date;
    }

    string getDate() const
    {
        return Date;
    }
};

enum EmployeeType
{
    EXPERIENCE = 0,
    FRESHER,
    INTERN
}; typedef EmployeeType Type;

class Employee
{
private:
    int id;
    string fullName;
    string birthDay;
    string phone;
    string email;
    Type employeeType;
    vector<Certificate *> certificates;

public:
    static int employeeCount;

    Employee(int _id, string _fullName, string _phone, string _email, EmployeeType _employeeType, const vector<Certificate *> &_certificates)
        : id(_id), fullName(_fullName), phone(_phone), email(_email), employeeType(_employeeType), certificates(_certificates)
    {
        employeeCount++;
    }

    int getID() const
    {
        return id;
    }

    void setID(int _id)
    {
        id = _id;
    }

    string getFullName() const
    {
        return fullName;
    }

    void setFullName(string _fullName)
    {
        fullName = _fullName;
    }

    string getBirthDay() const
    {
        return birthDay;
    }

    void setBirthDay(string _birthDay)
    {
        birthDay = _birthDay;
    }

    string getPhone() const
    {
        return phone;
    }

    void setPhone(string _phone)
    {
        phone = _phone;
    }

    string getEmail() const
    {
        return email;
    }

    void setEmail(string _email)
    {
        email = _email;
    }

    Type getEmployeeType() const
    {
        return employeeType;
    }

    void setEmployeeType(Type _employeeType)
    {
        employeeType = _employeeType;
    }

    virtual void showInfo() const
    {
        cout << "ID: " << id << endl;
        cout << "Full name: " << fullName << endl;
        cout << "Phone: " << phone << endl;
        cout << "Email: " << email << endl;
        switch (employeeType)
        {
        case EXPERIENCE:
            cout << "Employee Type: Experience" << endl;
            break;
        case FRESHER:
            cout << "Employee Type: Fresher" << endl;
            break;
        case INTERN:
            cout << "Employee Type: Intern" << endl;
            break;
        default:
            break;
        }
        cout << "List certificates: \n";
        for (auto &cer : certificates)
        {
            cout << "\tCertificate ID: " << cer->getID() << endl;
            cout << "\tCertificate Name: " << cer->getName() << endl;
            cout << "\tCertificate Rank: " << cer->getRank() << endl;
            cout << "\tCertificate Date: " << cer->getDate() << endl;
        }
    }
};

int Employee::employeeCount = 0;

class Intern : public Employee
{
private:
    string major;
    int semester;
    string uniName;

public:
    Intern(string _major, int _semester, string _uniName, int _id, string _fullName, string _phone, string _email, EmployeeType _employeeType, const vector<Certificate *> &_certificates)
        : Employee(_id, _fullName, _phone, _email, _employeeType, _certificates), major(_major), semester(_semester), uniName(_uniName) {}

    void setMajor(string _major)
    {
        major = _major;
    }
    string getMajor() const
    {
        return major;
    }

    void setSemester(int _semester)
    {
        semester = _semester;
    }
    int getSemester() const
    {
        return semester;
    }

    void setUniName(string _uniName)
    {
        uniName = _uniName;
    }
    string getUniName() const
    {
       return uniName;
    }

    void showInfo() const
    {
        Employee::showInfo();
        cout << "Major: " << major << endl;
        cout << "Semester: " << semester << endl;
        cout << "University Name: " << uniName << endl;
    }
};

class Fresher : public Employee
{
private:
    string graDate;
    string graRank;
    string education;

public:
    Fresher(string _graDate,string _graRank,string _education , int _id, string _fullName, string _phone, string _email, EmployeeType _employeeType, const vector<Certificate *> &_certificates)
        : Employee(_id, _fullName, _phone, _email, _employeeType, _certificates), graDate(_graDate), graRank(_graRank), education(_education) {}

    void setGraDate(string _graDate)
    {
        graDate = _graDate;
    }

    string getGraDate() const
    {
        return graDate;
    }

    void setGraRank(string _graRank)
    {
        graRank = _graRank;
    }

    string getGraRank() const
    {
        return graRank;
    }

    void setEducation(string _education)
    {
        education = _education;
    }

    string getEducation() const
    {
        return education;
    }

    void showInfo() const
    {
        Employee::showInfo();
        cout << "Graduation Date: " << graDate << endl;
        cout << "Graduation Rank: " << graRank << endl;
        cout << "Education: " << education << endl;
    }
};

class Experience : public Employee
{
private:
    int expInYear;
    string proSkill;

public:
    Experience(int _expInYear, string _proSkill, int _id, string _fullName, string _phone, string _email, EmployeeType _employeeType, const vector<Certificate *> &_certificates)
        : Employee(_id, _fullName, _phone, _email, _employeeType, _certificates), expInYear(_expInYear), proSkill(_proSkill) {}

    void setExpInYear(int _expInYear)
    {
        expInYear = _expInYear;
    }

    int getExpInYear() const
    {
        return expInYear;
    }

    void setProSkill(string _proSkill)
    {
        proSkill = _proSkill;
    }

    string getProSkill() const
    {
        return proSkill;
    }

    void showInfo() const
    {
        Employee::showInfo();
        cout << "Experience (in years): " << expInYear << endl;
        cout << "Professional Skill: " << proSkill << endl;
    }
};

class Manager
{
private:
    vector<Employee *> employees;

public:
    Manager() {}

    void add(Employee &e)
    {
        employees.push_back(&e);
    }

    void remove(int id)
    {
        int pos = -1;
        for (size_t i = 0; i < employees.size(); i++)
        {
            if (employees[i]->getID() == id)
            {
                pos = i;
                break;
            }
        }

        if (pos != -1)
        {
            employees.erase(employees.begin() + pos);
            cout << "Employee with ID " << id << " has been removed." << endl;
        }
        else
        {
            cout << "Employee with ID " << id << " not found." << endl;
        }
    }

    void showAllEmployee() const
    {
        for (auto &ee : employees)
        {
            ee->showInfo();
        }
    }

    void showAllIntern() const
    {
        for (auto &ee : employees)
        {
            if (ee->getEmployeeType() == Type::INTERN)
            {
                ee->showInfo();
            }
            
        }
    }

    void showAllFresher() const
    {
        for (auto &ee : employees)
        {
            if (ee->getEmployeeType() == Type::FRESHER)
            {
                ee->showInfo();
            }
            
        }
    }

    void showAllExp() const
    {
        for (auto &ee : employees)
        {
            if (ee->getEmployeeType() == Type::EXPERIENCE)
            {
                ee->showInfo();
            }
            
        }
    }

    bool isValidPhoneNumber(const string& phoneNumber)
    {
        regex pattern("(\\+84|0)\\d{9,10}");
        return regex_match(phoneNumber,pattern);
    }
    bool IsValidDateOfBirth(const std::string& dateOfBirth) {
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
    bool IsValidEmail(const string& email) 
    {
        regex emailRegex("[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,}");
        return regex_match(email, emailRegex);
    }

    #include <regex>

    bool IsValidName(const string& name) 
    {
        regex nameRegex("[A-Za-z\\s]+");
        return regex_match(name, nameRegex);
    }
};

class App
{
private:
    Manager manager;

public:
    vector<Certificate*> EnterCertificates() 
    {
        vector<Certificate*> certificates;
        
        int certificateCount;
        cout << "Enter the number of certificates: ";
        cin >> certificateCount;
        cin.ignore();

        for (int i = 0; i < certificateCount; i++) {
            string certificateID, certificateName, certificateRank, certificateDate;
            cout << "Enter certificate ID: ";
            getline(cin, certificateID);
            cout << "Enter certificate name: ";
            getline(cin, certificateName);
            cout << "Enter certificate rank: ";
            getline(cin, certificateRank);
            cout << "Enter certificate date: ";
            getline(cin, certificateDate);

            Certificate* certificate = new Certificate(certificateID, certificateName, certificateRank, certificateDate);
            certificates.push_back(certificate);
        }

        return certificates;
    }

    void AddEmp()
    {
        int choice;
        cout << "0 - Experience, 1 - Fresher, 2 - Intern \n";
        cout << "Enter type employee: ";
        cin >> choice;
        if (static_cast<Type>(choice) == Type::EXPERIENCE)
        {
            int id, expInYear;
            string fullName, dateOfBirth, phone, email, proSkill;
            vector<Certificate *> certificates;

            try 
            {
                cout << "Enter ID: ";
                cin >> id;
                cin.ignore();

                cout << "Enter full name: ";
                getline(cin, fullName);
                if (!manager.IsValidName(fullName)) 
                {
                    throw "Invalid name";
                }

                cout << "Enter date of birth: ";
                getline(cin, dateOfBirth);
                if (!manager.IsValidDateOfBirth(dateOfBirth)) 
                {
                    throw "Invalid date of birth";
                }

                cout << "Enter phone: ";
                getline(cin, phone);
                if (!manager.isValidPhoneNumber(phone)) 
                {
                    throw "Invalid phone";
                }

                cout << "Enter email: ";
                getline(cin, email);
                if (!manager.IsValidEmail(email)) 
                {
                    throw "Invalid email";
                }

                cout << "Enter professional skill: ";
                getline(cin, proSkill);

                cout << "Enter years of experience: ";
                cin >> expInYear;
                cin.ignore();

                certificates = EnterCertificates();
                Experience *experience = new Experience(expInYear, proSkill, id, fullName, phone, email, EmployeeType::EXPERIENCE, certificates);
                manager.add(*experience);
            }
            catch (const char* e) 
            {
                cout << "Error: " << e << endl;
            }
        }

        else if (static_cast<Type>(choice) == Type::FRESHER)
        {
            int id;
            string fullName, dateOfBirth, phone, email;
            vector<Certificate *> certificates;

            try 
            {
                cout << "Enter ID: ";
                cin >> id;
                cin.ignore();

                cout << "Enter full name: ";
                getline(cin, fullName);
                if (!manager.IsValidName(fullName)) 
                {
                    throw "Invalid name";
                }

                cout << "Enter date of birth: ";
                getline(cin, dateOfBirth);
                if (!manager.IsValidDateOfBirth(dateOfBirth)) 
                {
                    throw "Invalid date of birth";
                }

                cout << "Enter phone: ";
                getline(cin, phone);
                if (!manager.isValidPhoneNumber(phone)) 
                {
                    throw "Invalid phone";
                }

                cout << "Enter email: ";
                getline(cin, email);
                if (!manager.IsValidEmail(email)) 
                {
                    throw "Invalid email";
                }
                
                string graduationDate, graduationRank, education;
                cout << "Enter Graduation Date: ";
                cin >> graduationDate;
                cout << "Enter Graduation Rank: ";
                cin >> graduationRank;
                cout << "Enter Education: ";
                cin.ignore();
                getline(cin, education);

                certificates = EnterCertificates();
                Fresher* fresher = new Fresher(graduationDate,graduationRank,education,id,fullName,phone,email,Type::FRESHER,certificates);
                manager.add(*fresher);
                
            }

            catch (const char* e) 
            {
                cout << "Error: " << e << endl;
            }
        }

        else if (static_cast<Type>(choice) == Type::INTERN)
        {
            int id, semester;
            string fullName, dateOfBirth, phone, email, major, uniName;
            vector<Certificate *> certificates;

            try
            {
                cout << "Enter ID: ";
                cin >> id;
                cin.ignore();
                cout << "Enter full name: ";
                getline(cin, fullName);
                if (manager.IsValidName(fullName) == false)
                {
                    throw "Invalid name";
                }
                
                cout << "Enter date of birth: ";
                getline(cin, dateOfBirth);
                if (manager.IsValidDateOfBirth(dateOfBirth) == false)
                {
                    throw "Invalid date of birth";
                }
                

                cout << "Enter phone: ";
                getline(cin, phone);
                if (manager.isValidPhoneNumber(phone) == false)
                {
                    throw "Invalid phone";
                }
                
                cout << "Enter email: ";
                getline(cin, email);
                if (manager.IsValidEmail(email) == false)
                {
                    throw "Invalid email";
                }

                cout << "Enter major: ";
                getline(cin, major);

                cout << "Enter semester: ";
                cin >> semester;

                cin.ignore();
                cout << "Enter university name: ";
                getline(cin, uniName);

                certificates = EnterCertificates();
                
                Intern *intern = new Intern(major, semester, uniName, id, fullName, phone, email, EmployeeType::INTERN, certificates);
                manager.add(*intern);
            }

            catch (const char* e)
            {
                cout<<"Error: "<<e << endl;
            }
        }
        else
        {
            cout << "Invalid choice" << endl;
        }
        
    }
    
    void remove()
    {
        int id;
        cout<<"Nhap id can xoa";
        cin>>id;
        manager.remove(id);
    }

    void run()
    {
        int choice;
        while (true)
        {
            cout<<"------------------------------------------------"<<endl;
            cout << "0 - ADD \n1 - PRINT ALL \n2 - PRINT INTERN \n3 - PRINT FRESHER" << endl;
            cout << "4 - PRINT EXPERIENCE \n5 - EDIT \n6 - REMOVE"<<endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice)
            {
            case 0:
            {
                AddEmp();
                break;
            }
            case 1:
                manager.showAllEmployee();
                break;
            case 2:
                manager.showAllIntern();
                break;
            case 3:
                manager.showAllIntern();
                break;
            case 4:
                manager.showAllFresher();
                break;
            case 5:
                manager.showAllExp();
            case 6:
                remove();
            default:
                cout << "Invalid choice" << endl;
                break;
            }
        }
    }
};

int main()
{
    App app;
    app.run();
}