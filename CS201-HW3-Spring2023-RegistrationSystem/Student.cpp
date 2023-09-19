/**
* Title: Student Registration System
* Author : Zeynep Begum Kara
* ID: 22003880
* Section : CS201 - 2
* Homework : 3
*/

#include "Student.h"

Student::Student(const int studentId, const string firstName, const string lastName) {
    this->studentId = studentId;
    this->firstName = firstName;
    this->lastName = lastName;
    enrollments = new CourseList();
}

Student::~Student() {
    delete enrollments;
}

void Student::addCourse(Course* course){
    enrollments->insertCourse(course);
}

Course* Student::findCourse(const int courseId){
    return enrollments->findCourse(courseId);
}

void Student::withdrawCourse(const int courseId) {
    Course* courseToBeWithdrawn = enrollments->findCourse(courseId);
    if( courseToBeWithdrawn != nullptr){
        enrollments->removeCourse(courseToBeWithdrawn);
        cout << "Student " << studentId << " has been withdrawn from course " << courseId << endl;
    }
    else{
        cout << "Student " << studentId << " is not enrolled in course " << courseId << endl;
    }
}

bool Student::courseClosed(const int courseId){
 Course* courseClosed = enrollments->findCourse(courseId);
    if( courseClosed != nullptr){
        enrollments->removeCourse(courseClosed);
        return true;
    }
    return false;
}

void Student::display(){
    cout << studentId << " " << firstName << " " << lastName << endl;
}

void Student::displayEnrollments(){
    enrollments->display();
}

string Student::getFirstName() const {
    return firstName;
}

string Student::getLastName() const {
    return lastName;
}

CourseList* Student::getEnrollments() const {
    return enrollments;
}

Student* Student::getNext() const {
    return next;
}

Student* Student::getPrev() const {
    return prev;
}

int Student::getStudentId() const {
    return studentId;
}

void Student::setNext(Student* next) {
    this->next = next;
}

void Student::setPrev(Student* prev) {
    this->prev = prev;
}

