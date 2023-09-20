/**
* Title: Student Registration System
* Author : Zeynep Begum Kara
* ID: 22003880
* Section : CS201 - 2
* Homework : 3
*/

#include "StudentList.h"

class RegistrationSystem {
private:
    StudentList* students;

public:
    RegistrationSystem();
    ~RegistrationSystem();
    void addStudent( const int studentId, const string firstName, const string lastName );
    void deleteStudent( const int studentId );
    void addCourse( const int studentId, const int courseId, const string courseName );
    void withdrawCourse( const int studentId, const int courseId );
    void cancelCourse( const int courseId );
    void showStudent( const int studentId );
    void showCourse( const int courseId );
    void showAllStudents();
};
