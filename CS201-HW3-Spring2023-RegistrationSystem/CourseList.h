/**
* Title: Student Registration System
* Author : Zeynep Begum Kara
* ID: 22003880
* Section : CS201 - 2
* Homework : 3
*/

#ifndef COURSELIST_H
#define COURSELIST_H

#include "Course.h"

class CourseList{
private:
    Course* head;

public:
    CourseList();
    ~CourseList();
    bool isEmpty();
    void insertCourse(Course* course);
    void removeCourse(Course* course);
    Course* findCourse(const int courseId);
    void display();
    bool cancelCourse(const int courseId);
    Course* getHead();

};

#endif
