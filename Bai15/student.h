// student.h
#ifndef STUDENT_H
#define STUDENT_H

using namespace std;

enum student_t{
    regular_student  = 0,
    parttime_student = 1,
};

class Result {
private:
    string semester;
    double gpa;
public:
    Result();
    ~Result();
    Result(string semester, double gpa);
    void add_result();
    void displayResult() const;
};

class Student {
private:
    string id;
    string name;
    int enrollmentYear;
    double entranceScore;
    vector<Result> results;
protected:
    student_t type;
public:
    Student();
    Student(string id, string name, int enrollmentYear, double entranceScore);
    void setStudentType(student_t type);
    student_t getStudentType();
    virtual ~Student();
    virtual void input();
    double getEntranceScore();
    void addResult();
    void addResult(Result result);
    vector<Result>& getResult();
    virtual void displayInfo();
};

class RegularStudent : public Student {
public:
    RegularStudent();
    RegularStudent(string id, string name, int enrollmentYear, double entranceScore);
    ~RegularStudent();
    void displayInfo();
    void input();
};

class PartTimeStudent : public Student {
private:
    string trainingLocation;
public:
    PartTimeStudent();
    PartTimeStudent(string id, string name, int enrollmentYear, double entranceScore, string trainingLocation);
    ~PartTimeStudent();
    string getTrainingLocation();
    void displayInfo();
    void input();
};

class Department{
private:
    string name;
    vector<Student*> students;
public:
    Department();
    Department(string name);
    ~Department();
    void addStudent();
    void addStudent(Student * student);
    void displayStudents() const;
    size_t getNumberRegular();
    vector<Student*> getMaxEntranceScore();
    vector<Student*> getParttime_TrainingLocation(string locationtraining);
};

#endif


