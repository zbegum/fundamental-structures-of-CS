/**
* Title: Student Registration System
* Author : Zeynep Begum Kara
* ID: 22003880
* Section : CS201 - 2
* Homework : 3
*/

#ifndef STUDENT_H
#define STUDENT_H

#include "CourseList.h"

class Student{
private:
    int studentId;
    string firstName;
    string lastName;
    CourseList* enrollments;
    Student* next;
    Student* prev;

public:
    Student( const int studentId, const string firstName, const string lastName );
    ~Student();
    void addCourse( Course* course );
    Course* findCourse(const int courseId);
    void withdrawCourse(const int courseId );
    void showStudent();
    bool courseClosed(const int courseId);
    void display();
    void displayEnrollments();
    string getFirstName() const;
    string getLastName() const;
    CourseList* getEnrollments() const;
    Student* getNext() const;
    Student* getPrev() const ;
    int getStudentId() const;
    void setNext(Student* next);
    void setPrev(Student* prev);
};

#endif

