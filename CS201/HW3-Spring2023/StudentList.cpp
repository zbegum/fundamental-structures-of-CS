/**
* Title: Student Registration System
* Author : Zeynep Begum Kara
* ID: 22003880
* Section : CS201 - 2
* Homework : 3
*/

//=================================================check=============
#include "StudentList.h"

using namespace std;

StudentList::StudentList() {
    head = nullptr;
}

StudentList::~StudentList() {
    while(head != nullptr) {
        Student* temp = head;
        head = head->getNext();
        if (head != nullptr) {
            head->setPrev(nullptr);
        }
        delete temp;
    }
}

bool StudentList::isEmpty() {
    return head == nullptr;
}

void StudentList::insertStudent(Student* newStudent) {
    if (isEmpty() || newStudent->getStudentId() < head->getStudentId()) {
        newStudent->setNext(head);
        if (head != nullptr) {
            head->setPrev(newStudent);
        }
        head = newStudent;
        return;
    }
    else {
        Student* cur = head;
        while (cur->getNext() != nullptr && newStudent->getStudentId() > cur->getNext()->getStudentId()) {
            cur = cur->getNext();
        }
        newStudent->setNext(cur->getNext());
        if (cur->getNext() != nullptr) {
            cur->getNext()->setPrev(newStudent);
        }
        cur->setNext(newStudent);
        newStudent->setPrev(cur);
        return;
    }
}

void StudentList::removeStudent(const int studentId) {
    if (isEmpty()) {
        cout << "EMPTY LIST" << endl;
        return;
    }

    Student* student = findStudent(studentId);
    if(student != nullptr){
        // delete head
        if (student == head) {
            head = student->getNext();
            if (head != nullptr) {
                head->setPrev(nullptr);
            }
            cout << "Student " << student->getStudentId() << " has been deleted" << endl;
            delete student;
            return;
        }

        // delete non-head students
        Student* current = head;
        while (current != nullptr && current != student) {
            current = current->getNext();
        }

        if (current == nullptr) {
            cout << "Student " << student->getStudentId() << " does not exist" << endl;
            return;
        }
        Student* prev = current->getPrev();
        Student* next = current->getNext();
        prev->setNext(next);
        if (next != nullptr) {
            next->setPrev(prev);
        }
        cout << "Student " << student->getStudentId() << " has been deleted" << endl;
        delete current;
    }
}

bool StudentList::removeCourse(int courseId){
    Student* cur = head;
    bool deleted = false;
    while (cur != nullptr) {
        bool temp = cur->courseClosed(courseId);
        deleted = temp || deleted;
        cur = cur->getNext();
    }
    return deleted;
}

Student* StudentList::findStudent(const int studentId) {
    Student* cur = head;
    while (cur != nullptr) {
        if (cur->getStudentId() == studentId) {
            return cur;
        }
        cur = cur->getNext();
    }
    return nullptr;
}

Course* StudentList::courseExist(const int courseId){
    Student* cur = head;
    while (cur != nullptr) {
        if (cur->findCourse(courseId) != nullptr) {
            return cur->findCourse(courseId);
        }
        cur = cur->getNext();
    }
    return nullptr;
}

void StudentList::showCourse(int courseId){
    bool courseFound = false;
    Student* cur = head;
    while (cur != nullptr) {
        Course* course = cur->findCourse(courseId);
        if (course != nullptr) {
            if(!courseFound){
                cout << "Course id Course name" << endl;
                course->display();
                cout << "Student id First name Last name" << endl;
            }
            cur->display();
            courseFound = true;
        }
        cur = cur->getNext();
    }
    if(!courseFound)
        cout << "Course " << courseId << " does not exist" << endl;
}

void StudentList::display() {
    Student* cur = head;
    while(cur != nullptr){
        cur->display();
        cur->displayEnrollments();
        cur = cur->getNext();
    }
}

