/**
* Title: Student Registration System
* Author : Zeynep Begum Kara
* ID: 22003880
* Section : CS201 - 2
* Homework : 3
*/
#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <string>

using namespace std;

class Course{
private:
    int courseId;
    string courseName;
    Course* next;

public:
    Course(int courseId, string courseName);
    int getCourseId() const;
    string getCourseName() const;
    Course* getNext() const;
    void setNext(Course* nextCourse);
    void display();
};

#endif
