/**
* Title: Student Registration System
* Author : Zeynep Begum Kara
* ID: 22003880
* Section : CS201 - 2
* Homework : 3
*/

#include "Student.h"

class StudentList{
private:
    Student* head;

public:
    StudentList();
    ~StudentList();
    bool isEmpty();
    void insertStudent(Student* student);
    void removeStudent(const int studentId);
    Student* findStudent(const int studentId);
    void display();
    bool removeCourse(int courseId);
    void showCourse(int courseId);
    Course* courseExist(const int courseId);
};
