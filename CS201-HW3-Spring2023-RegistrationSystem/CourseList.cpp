/**
* Title: Student Registration System
* Author : Zeynep Begum Kara
* ID: 22003880
* Section : CS201 - 2
* Homework : 3
*/

#include "CourseList.h"
#include <iostream>
using namespace std;

CourseList::CourseList() {
    head = nullptr;
}

CourseList::~CourseList() {
    while (head != nullptr) {
        Course* temp = head;
        head = head->getNext();
        delete temp;
    }
}

bool CourseList::isEmpty() {
    return head == nullptr;
}

// sorted insertion based on courseId
void CourseList::insertCourse(Course* course) {
    if (head == nullptr || head->getCourseId() > course->getCourseId()) {
        course->setNext(head);
        head = course;
    }
    else {
        if (head->getCourseId() == course->getCourseId()) {
            return;
        }
        Course* cur = head;
        while (cur->getNext() != nullptr &&
               cur->getNext()->getCourseId() < course->getCourseId()) {
            cur = cur->getNext();
        }
        course->setNext(cur->getNext());
        cur->setNext(course);
    }
    //cout << "tamam" << endl;
}

void CourseList::removeCourse(Course* course) {
    if (isEmpty()) {
        cout << "EMPTY LIST -- cannot remove" << endl;
        return;
    }

    Course* prev = nullptr;
    Course* cur = head;

    // find course to be deleted, if exist - might result in traversing the whole list
    while (cur != nullptr && cur != course) {
        prev = cur;
        cur = cur->getNext();
    }

    if (cur == nullptr) {
        //cout << "COURSE " << course->getCourseId() << " NOT FOUND - Cannot remove." << endl;
        return;
    }

    if (prev == nullptr) {
        head = cur->getNext();
    }
    else {
        prev->setNext(cur->getNext());
    }

    delete cur;
    //cout << "Course removed successfully." << endl;
}

Course* CourseList::findCourse(const int courseId) {
    Course* cur = head;
    while (cur != nullptr) {
        if (cur->getCourseId() == courseId) {
            return cur;
        }
        cur = cur->getNext();
    }
    return nullptr;
}

void CourseList::display() {
    if (isEmpty()) {
        return;
    }
    cout << "Course id Course name" << endl;
    Course* cur = head;
    while (cur != nullptr) {
        cur->display();
        cur = cur->getNext();
    }
}

bool CourseList::cancelCourse(const int courseId){
    cout << "not implemented" << endl;
    return false;
}

Course* CourseList::getHead(){
    return head;
}
