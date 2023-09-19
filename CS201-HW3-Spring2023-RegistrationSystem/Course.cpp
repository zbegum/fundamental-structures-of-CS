/**
* Title: Student Registration System
* Author : Zeynep Begum Kara
* ID: 22003880
* Section : CS201 - 2
* Homework : 3
*/

#include "Course.h"

Course::Course(int courseId, string courseName) {
    this->courseId = courseId;
    this->courseName = courseName;
    next = nullptr;
}

int Course::getCourseId() const {
    return courseId;
}

string Course::getCourseName() const {
    return courseName;
}

Course* Course::getNext() const {
    return next;
}

void Course::setNext(Course* nextCourse) {
    next = nextCourse;
}

void Course::display() {
    cout << courseId << " " << courseName << endl;
}


