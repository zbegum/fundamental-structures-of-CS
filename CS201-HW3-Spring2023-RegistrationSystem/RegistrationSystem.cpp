/**
* Title: Student Registration System
* Author : Zeynep Begum Kara
* ID: 22003880
* Section : CS201 - 2
* Homework : 3
*/

#include "RegistrationSystem.h"

RegistrationSystem::RegistrationSystem() {
    students = new StudentList();
}

RegistrationSystem::~RegistrationSystem() {
    delete students;
}

void RegistrationSystem::addStudent(const int studentId, const string firstName, const string lastName) {
    if(students->findStudent(studentId) == nullptr){
        Student* newStudent = new Student(studentId, firstName, lastName);
        students->insertStudent(newStudent);
        cout << "Student " << newStudent->getStudentId() << " has been added" << endl;
    }
    else{
        cout << "Student " << studentId << " already exists" << endl;
    }
}

void RegistrationSystem::deleteStudent(const int studentId) {
    Student* studentToBeDeleted = students->findStudent(studentId);
    if( studentToBeDeleted != nullptr){
        students->removeStudent(studentId);
    }
    else{
        cout << "Student " << studentId << " does not exist" << endl;
    }
}

void RegistrationSystem::addCourse(const int studentId, const int courseId, const string courseName) {
    Student* student = students->findStudent(studentId);
    if( student != nullptr){
        Course* course = students->courseExist(courseId);
        if(course == nullptr){
            Course* newCourse = new Course(courseId, courseName);
            //courses->insertCourse(newCourse);
            student->addCourse(newCourse);
            cout << "Course " << courseId << " has been added to student " << studentId << endl;
        }
        else{
            if(student->findCourse(courseId) != nullptr && course->getCourseName() == courseName){
                cout << "Student " << studentId << " is already enrolled in course " << courseId << endl;
            }
            else{
                if(course->getCourseName() == courseName){
                    Course* newCourse = new Course(courseId, courseName);
                    student->addCourse(newCourse);
                    cout << "Course " << courseId << " has been added to student " << studentId << endl;
                }
                else{
                    cout << "Course " << courseId << " already exists with another name" << endl;
                }
            }
        }
        //courses->display();
        //student->displayEnrollments();
    }
    else{
        cout << "Student " <<  studentId << " does not exist" << endl;
    }
}

void RegistrationSystem::withdrawCourse(const int studentId, const int courseId) {
    Student* student = students->findStudent(studentId);
    if( student != nullptr){
        student->withdrawCourse(courseId);
    }
    else{
        cout << "Student " <<  studentId << " does not exist" << endl;
    }
}

void RegistrationSystem::cancelCourse(const int courseId) {
    bool deleted = false;
    deleted = students->removeCourse(courseId);

    if(deleted)
        cout << "Course " << courseId << " has been cancelled" << endl;
    else{
        cout << "Course " << courseId << " does not exist" << endl;
    }
}

void RegistrationSystem::showStudent(const int studentId) {
    Student* studentToBeShown = students->findStudent(studentId);
    if( studentToBeShown != nullptr){
        cout << "Student id First name Last name" << endl;
        studentToBeShown->display();
        studentToBeShown->getEnrollments()->display();
    }
    else{
        cout << "Student " << studentId << " does not exist" << endl;
    }
}

void RegistrationSystem::showCourse(const int courseId) {
    students->showCourse(courseId);
}

void RegistrationSystem::showAllStudents() {
    if(students->isEmpty())
        cout << "There are no students in the system" << endl;
    else{
        cout << "Student id First name Last name" << endl;
        students->display();
    }
}
