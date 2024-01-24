#include <iostream>
#include <vector>
#include <string>
#include "student.h"

//using namespace std;

Result::Result() { }
Result::Result(string semester, double gpa) : semester(semester), gpa(gpa) {}
void Result::displayResult() const{
    cout << "Semester: " << semester << "\tGpa: " << gpa << endl;
}
void Result::add_result(){
    cout << "Semester: ";
    cin >> semester;
    cout << "gpa: ";
    cin >> gpa;
}
Result::~Result() { }

Student::Student() { }
Student::Student(string id, string name, int enrollmentYear, double entranceScore) :
    id(id), name(name), enrollmentYear(enrollmentYear), entranceScore(entranceScore) { }
Student::~Student() { }
void Student::addResult(Result result){
    results.push_back(result);
}
void Student::addResult(){
    Result temp;
    temp.add_result();
    results.push_back(temp);
}
void Student::setStudentType(student_t type){
    this->type = type;
}
void Student::displayInfo(){
    cout << "Id: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "EnrollmentYear: " << enrollmentYear << endl;
    cout << "EntranceScore: " << entranceScore << endl;
    cout << "Result: " << endl;
    for (size_t i = 0; i < results.size(); i++){
        results[i].displayResult();
    }
}
double Student::getEntranceScore(){
    return entranceScore;
}
void Student::input(){
    cout << "Id: ";
    cin >> id;
    cout << "Name:";
    cin.ignore();
    getline(cin, name);
    cout << "EnrollmentYear: ";
    cin >> enrollmentYear;
    cout << "EntranceScore: ";
    cin >> entranceScore;
}
student_t Student::getStudentType(){
    return type;
}
vector<Result>& Student::getResult(){
    return results;
}

RegularStudent::RegularStudent() {
    setStudentType(regular_student);
}
RegularStudent::RegularStudent(string id, string name, int enrollmentYear, double entranceScore) :
    Student(id, name, enrollmentYear, entranceScore) {
        setStudentType(regular_student);
}
RegularStudent::~RegularStudent() { }
void RegularStudent::displayInfo() {
    cout << "Regular Student: " << endl;
    Student::displayInfo();
}
void RegularStudent::input(){
    Student::input();
}

PartTimeStudent::PartTimeStudent() {
    type = parttime_student;
}
PartTimeStudent::PartTimeStudent(string id, string name, int enrollmentYear, double entranceScore, string trainingLocation) :
    Student(id, name, enrollmentYear, entranceScore), trainingLocation(trainingLocation) {
        type = parttime_student;
}
PartTimeStudent::~PartTimeStudent() { }
void PartTimeStudent::displayInfo() {
    cout << "Parttime Student: " << endl;
    Student::displayInfo();
    cout << "Training location: " << trainingLocation << endl;
}
void PartTimeStudent::input(){
    Student::input();
    cout << "Training location: ";
    cin.ignore();
    getline(cin, trainingLocation);
}
string PartTimeStudent::getTrainingLocation(){
    return trainingLocation;
}



Department::Department() {}
Department::Department(string name) : name(name) {}

void Department::addStudent(){
    int temp;
    Student * x;
    do{
        cout << "Add student (0 - regular, 1 - parttime): ";
        cin >> temp;
        switch (temp)
        {
        case 0: 
            x = new RegularStudent;
            break;
        case 1:
            x = new PartTimeStudent;
            break;
        default:
            cout << "Wrong...\n";
            break;
        }
    }while( (temp < 0) || (temp > 1) );
    x->input();
    Department::addStudent(x);
    cout << "Added!\n";
}

void Department::addStudent(Student * student) {
    students.push_back(student);
}
void Department::displayStudents() const {
    cout << "Students in Department " << name << ":\n";
    for (size_t i = 0; i < students.size(); i++) {
        students[i]->displayInfo();
        cout << "-------------------------\n";
    }
}
Department::~Department(){
    for(size_t i = 0; i < students.size(); i++){
        delete students[i];
        cout << "? ";
    }
    students.clear();
}
size_t Department::getNumberRegular(){
    size_t count = 0;

    for(size_t i = 0; i < students.size(); i++){
        if (students[i]->getStudentType() == regular_student){
            count++;
        }
    }
    return count;
}

vector<Student*> Department::getMaxEntranceScore(){
    vector<Student*> v;
    double max = students[0]->getEntranceScore();
    for(size_t i = 1; i < students.size(); i++){
        if (students[i]->getEntranceScore() > max){
            max = students[i]->getEntranceScore();
        }
    }
    for (size_t i = 0; i < students.size(); i++){
        if (students[i]->getEntranceScore() == max){
            v.push_back(students[i]);
        }
    }
    return v;
}

vector<Student*> Department::getParttime_TrainingLocation(string locationtraining){
    vector<Student*> v;
    for (size_t i = 0; i < students.size(); i++){
        if (students[i]->getStudentType() == regular_student){
            //if (students[i]->(dynamic_cast<RegularStudent>)getTrainingLocation() == locationtraining)
                v.push_back(students[i]);
        }
    }
    return v;
}

