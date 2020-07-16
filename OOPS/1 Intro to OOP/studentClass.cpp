#include <cassert>
#include <stdexcept>
#include <iostream>
using namespace std;
// TODO: Define "Student" class
class Student {
 public:
    Student(string name, int grade, float GPA) : name(name), 
            grade(grade), GPA(GPA) {
        validate();
    }
    string getName() const;
    int getGrade() const;
    float getGPA() const;
    void setName(string name);
    void setGrade(int grade);
    void setGPA(float GPA);
    void validate();
    
 private:
    string name;
    int grade;
    float GPA;
};

string Student::getName() const {
    return name;
}

int Student::getGrade() const {
    return grade;
}

float Student::getGPA() const {
    return GPA;
}

void Student::setName(string name) {
    Student::name = name;
    validate();
}

void Student::setGrade(int grade) {
    Student::grade = grade;
    validate();
}

void Student::setGPA(float GPA) {
    Student::GPA = GPA;
    validate();
}

void Student::validate() {
    if (grade < 0 || grade > 12 )
        throw invalid_argument("grade not valid");
    else if (GPA < 0.0 || GPA > 4.0) 
        throw invalid_argument("GPA not valid");
}

// TODO: Test
int main() {
    Student stu("raghav", 12, 4.0);
    assert(stu.getName() == "raghav");
    assert(stu.getGrade() == 12);
    assert(stu.getGPA() == 4.0);
    
    bool caught{false};
    try {
        Student stu1("rv", 9, 9.6);
    }
    catch(...) {
        caught = true;
    }
    assert(caught);
    
}