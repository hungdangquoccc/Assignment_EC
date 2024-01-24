#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum Employee_Type{
    EXPERIENCE = 0,
    FRESHER,
    INTERN
};

class Certificate{
    private:
        int CertificateID;
        string CertificateName;
        string CertificateRank;
        string CertificateDate;
    public:
        Certificate(int CertificateID, string CertificateName, string CertificateRank, string CertificateDate)
        {
            this->CertificateID = CertificateID;
            this-> CertificateName = CertificateName;
            this->CertificateRank = CertificateRank;
            this->CertificateDate = CertificateDate;
        }

        int GetCertificateID()
        {
            return CertificateID;
        }

        void setCertificateID(int CertificateID) 
        {
            this->CertificateID = CertificateID;    
        }
        // get set name
        string getCertificateName()
        {
            return CertificateName;
        }

        void setCertificateName()
        {
            this-> CertificateName = CertificateName;
        }

        // get set rank
        string getCertificateRank()
        {
            return CertificateRank;
        }

        void setCertificateRank()
        {
            this-> CertificateRank = CertificateRank;
        }
        string getCertificateDate()
        {
            return CertificateDate;
        }

        void setCertificateDate()
        {
            this-> CertificateDate = CertificateDate;
        }     
};


class Employee{
    private:
        int ID;
        // static int EmployeeCount;
        string FullName;
        string BirdDay;
        string Phone;
        string Email;
        vector<Certificate> Certificates;
        Employee_Type EmployeeType;
    public:
        static int EmployeeCount;

        // Employee a(1, "A", "2")

        Employee(int ID, string FullName, string BirdDay,string phone, string Email, vector<Certificate> Certificates, Employee_Type EmployeeType)
        {
            this->ID = ID;
            this->FullName = FullName;
            this->BirdDay = BirdDay;
            this-> Phone = phone;
            this-> Email = Email;
            this->Certificates = Certificates;
            this->EmployeeType = EmployeeType;
            EmployeeCount +=1;
        }

        // get set ID
        int getID()
        {
            return ID;
        }

        void setID(int ID)
        {
            this->ID = ID;
        }
        // get set fullname
        string getFullName()
        {
            return FullName;
        }

        void setFullName(string FullName)
        {
            this-> FullName = FullName;
        }
        // get set BirdDay
        string getBirdDay()
        {
            return BirdDay;
        }

        void setBirdDay(string BirdDay)
        {
            this-> BirdDay = BirdDay;
        }

        // get set phone
        string getPhone()
        {
            return Phone;
        }

        void setPhone(string phone)
        {
            this->Phone = Phone;
        }

        // getset Email
        string getEmail()
        {
            return Email;
        }

        void setEmail(string email)
        {
            this->Email = email;
        }
        // get set certificate
        
        vector<Certificate> getCertificates()
        {
            return Certificates;
        }

        void setCertificates(vector<Certificate> Certificates)
        {
            this-> Certificates = Certificates;
        }

        Employee_Type getEmployeeType()
        {
            return EmployeeType;
        }

        virtual void ShowInfo()
        {
            cout << "----------------------------------------------"<< endl;
            cout << "Employee ID: " << getID() << endl;
            cout << "Full Name: " << getFullName() << endl;
            cout << "Birth Day: " << getBirdDay() << endl;
            cout << "Phone: " << getPhone() << endl;
            cout << "Email: " << getEmail() << endl;
            
            switch (EmployeeType)
            {
            case FRESHER:
                cout << "Employee Type: Fresher" << endl;
                break;
            case EXPERIENCE:
                cout << "Employee Type: EXPERIENCE" << endl;
                break;
            case INTERN:
                cout << "Employee Type: INTERN" << endl;
                break;
            
            default:
                break;
            }

            cout << "Cerificate:" << endl;
            for (auto &cer : Certificates )
            {
                cout << "\t" << "ID Cerificate: " << cer.GetCertificateID() << endl;
                cout << "\tCertificateName: " << cer.getCertificateName() << endl;
                cout << "\tCertificateRank: " << cer.getCertificateRank() << endl;
                cout << "\tCertificateDate: " << cer.getCertificateDate() << endl;
            }
            
        }
};

int Employee::EmployeeCount = 0;


class Experience : public Employee
{
private:
    /* data */
    short ExpInYear;
    string ProSkill;
public:
    Experience(int ID, string FullName, string BirdDay,string phone, string Email, vector<Certificate> Certificates, 
    short ExpInYear, string Proskill, Employee_Type EmployeeType) : Employee(ID, FullName, BirdDay, phone, Email, Certificates, EmployeeType)
    {
        this->ExpInYear = ExpInYear;
        this-> ProSkill = Proskill;
    }
    

    // get set Exp
    short getExpInYear()
    {
        return ExpInYear;
    }
    void setExpInYear( string ProSkill)
    {
        this->ProSkill = ProSkill;
    }
    //getset proskill
    string getProSkill()
    {
        return ProSkill;
    }

    void setProSkill( string ProSkill)
    {
        this->ProSkill = ProSkill;
    }

    void ShowInfo()
    {
        Employee::ShowInfo();
        cout << "ExpInYear: " << getExpInYear() << endl;
        cout << "ProSkill: " << getProSkill() << endl;
    }

};

class Fresher : public Employee
{
private:
    /* data */
    string GraduationDate;
    string GraduationRank;
    string Education;
public:
    Fresher(int ID, string FullName, string BirdDay, string phone, string Email, vector<Certificate> Certificates,
    string GraduationDate, string GraduationRank, string Education, Employee_Type EmployeeType) : Employee(ID, FullName, BirdDay, phone, Email, Certificates, EmployeeType)
    {
        this->GraduationDate = GraduationDate;
        this->GraduationRank = GraduationRank;
        this-> Education = Education;

    }
    // get set GraDate
    string getGraDate()
    {
        return GraduationDate;
    }
    void setGraDate(string GraduationDate)
    {
        this->GraduationDate = GraduationDate;
    }

    // get set gra rank
    string getGraRank()
    {
        return GraduationRank;
    }
    void setGraRank(string GraduationRank)
    {
        this->GraduationRank = GraduationRank;
    }
    // get set education
    string getEducation()
    {
        return Education;
    }

    void setEducation( string Education)
    {
        this-> Education = Education;
    }

    void ShowInfo()
    {
        Employee::ShowInfo();
        cout << "GraduationDate: " << getGraDate() << endl;
        cout << "GraduationRank: " << getGraRank() << endl;
        cout << "Education: " << getEducation() << endl;
    }
    
};

class Intern : public Employee
{
    private:
        /* data */
        string Major;
        int Semester;
        string UniversityName;
    public:
        Intern(int ID, string FullName, string BirdDay, string phone, string Email, vector<Certificate> Certificates, 
        string Major, int Semester, string UniversityName, Employee_Type EmployeeType) : Employee(ID, FullName, BirdDay, phone, Email, Certificates, EmployeeType)
        {
            this->Major = Major;
            this->Semester = Semester;
            this-> UniversityName = UniversityName;
        }

        string getMajor() {
            return Major;
        }

        void setMajor(string Major) {
            this->Major = Major;
        }

        int getSemester() {
            return Semester;
        }

        void setSemester(int Semester)
        {
            this->Semester = Semester;   
        }

        string getUniversityName() {
            return UniversityName;
        }

        void setUniversityName(string UniversityName) {
            this->UniversityName = UniversityName;
        }

        void ShowInfo()
        {
            Employee::ShowInfo();
            cout << "Major: " << getMajor() << endl;
            cout << "Semester: " << getSemester() << endl;
            cout << "UniversityName: " << getUniversityName() << endl;

        }
        
};

class EmployeeManager
{
private:
    vector<Employee *> employees;
    // Employee test;
    
    int getNextID() {
        return Employee::EmployeeCount + 1;
    }

    vector<Certificate> inputCertificates() {
        vector<Certificate> certificates;

        int certificateCount;
        cout << "Enter number of certificates: ";
        cin >> certificateCount;

        for (int i = 0; i < certificateCount; ++i) {
            int certID;
            string certName, certRank, certDate;

            cout << "\tEnter Certificate ID: ";
            cin >> certID;

            cout << "\tEnter Certificate Name: ";
            cin.ignore();
            getline(cin, certName);

            cout << "\tEnter Certificate Rank: ";
            cin >> certRank;

            cout << "\tEnter Certificate Date: ";
            cin >> certDate;
            cout <<"\n";

            Certificate cert(certID, certName, certRank, certDate);
            certificates.push_back(cert);
        }

        return certificates;
    }

public:
    EmployeeManager() {}

    void add(Employee *employee)
    {
        employees.push_back(employee);
    }

    void addFresher() {
        Employee_Type type = FRESHER;

        int ID;
        cout << "Enter ID: ";
        cin >> ID;

        string fullName;
        cout << "Enter Full Name: ";
        cin.ignore();
        getline(cin, fullName);

        string birdDay;
        cout << "Enter Birth Day: ";
        cin >> birdDay;

        string phone;
        cout << "Enter Phone: ";
        cin >> phone;

        string email;
        cout << "Enter Email: ";
        cin >> email;

        vector<Certificate> certificates = inputCertificates();

        string graduationDate, graduationRank, education;
        cout << "Enter Graduation Date: ";
        cin >> graduationDate;
        cout << "Enter Graduation Rank: ";
        cin >> graduationRank;
        cout << "Enter Education: ";
        cin.ignore();
        getline(cin, education);

        Fresher* fresher = new Fresher(ID, fullName, birdDay, phone, email, certificates,
                                      graduationDate, graduationRank, education, type);
        employees.push_back(fresher);
        cout << "Fresher added successfully." << endl;
    }

    void addExperience() {
        Employee_Type type = EXPERIENCE;

        int ID;
        cout << "Enter ID: ";
        cin >> ID;

        string fullName;
        cout << "Enter Full Name: ";
        cin.ignore();
        getline(cin, fullName);

        string birdDay;
        cout << "Enter Birth Day: ";
        cin >> birdDay;

        string phone;
        cout << "Enter Phone: ";
        cin >> phone;

        string email;
        cout << "Enter Email: ";
        cin >> email;

        vector<Certificate> certificates = inputCertificates();
        
        short expInYear;
        string proSkill;
        cout << "Enter Experience in Years: ";
        cin >> expInYear;
        cout << "Enter Professional Skill: ";
        cin.ignore();
        getline(cin, proSkill);

        Experience* experience = new Experience(ID, fullName, birdDay, phone, email, certificates,
                                                expInYear, proSkill, type);
        employees.push_back(experience);
        cout << "Experience added successfully." << endl;
    }

    void addIntern() {
        Employee_Type type = INTERN;

        int ID;
        cout << "Enter ID: ";
        cin >> ID;

        string fullName;
        cout << "Enter Full Name: ";
        cin.ignore();
        getline(cin, fullName);

        string birdDay;
        cout << "Enter Birth Day: ";
        cin >> birdDay;

        string phone;
        cout << "Enter Phone: ";
        cin >> phone;

        string email;
        cout << "Enter Email: ";
        cin >> email;

        vector<Certificate> certificates = inputCertificates();

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
                                   major, semester, universityName, type);
        employees.push_back(intern);
        cout << "Intern added successfully." << endl;
    }

     void edit(int employeeID)
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

    void remove(int ID)
    {

    }
    
    void printAllFresher()
    {
        for (const auto &employee : employees)
        {
            if (employee->getEmployeeType() == FRESHER)
                employee->ShowInfo();
        }
    }

    void printAllExPerience()
    {
        for (const auto &employee : employees)
        {
            if (employee->getEmployeeType() == EXPERIENCE)
                employee->ShowInfo();
        }
    }

    void printAllIntern()
    {
        for (const auto &employee : employees)
        {
            if (employee->getEmployeeType() == INTERN)
                employee->ShowInfo();
        }
    }

    void printAllEmployees()
    {
        for (const auto &employee : employees)
        {
            employee->ShowInfo();
        }
    }
};

class UserInterface {
private:
    EmployeeManager manager;
    
public:
    void getUserChoice() {
        int choice;
        
        cout << "Choose employee type:" << endl;
        cout << "1. Fresher" << endl;
        cout << "2. Experience" << endl;
        cout << "3. Intern" << endl;
        cout << "Enter your choice (1-3): ";
        cin >> choice;
        cout << "\n";
        switch (choice) {
            case 1:
                manager.addFresher();
                break;
            case 2:
                manager.addExperience();
                break;
            case 3:
                manager.addIntern();
                break;
            default:
                std::cerr << "Invalid choice. Defaulting to Fresher." << std::endl;
                break;
        }
    }

    void run()
    {
        int choice;
        while(true)
        {
            cout << "-----------------------------------------\n";
            cout << "Choice: \n";
            cout << "1 - Add Employee\n" << "2 - Print\n" << "3 - Edit: \n";
            cout << "-----------------------------------------\n";
            cin >> choice;

            switch (choice)
            {
            case 1:
                getUserChoice();
                break;
            case 2:
                cout << "-----------------------------------------\n";
                int choice;
                cout << "Choose how to print\n";
                cout << "1 - Show All Employee" << endl << "2 - Print All Fresher" << endl << "3 - Print All Experience\n" <<"4 - Print All Intern: \n";
                cin >> choice;
                switch (choice)
                {
                case 1:
                    manager.printAllEmployees();
                    break;
                case 2:
                    manager.printAllFresher();
                    break;
                case 3:
                    manager.printAllExPerience();
                    break;
                case 4:
                    manager.printAllIntern();
                    break;
                default:
                    break;
                }
                // manager.printAllEmployees();
                break;
            
            case 3:
                int ID;
                cout << "Enter ID Employee need to Edit: ";
                cin >> ID;
                manager.edit(ID);
                break;
            default:
                cout << "Invalid Choice" << endl;
                break;
            }
        }
    }
};


int main() {

    UserInterface test;
    test.run();   

    cout << "Sum People: "<< Employee::EmployeeCount << endl;

    return 0;
}
