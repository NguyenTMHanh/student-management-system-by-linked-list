#ifndef STUDENT_NODE_H
#define STUDENT_NODE_H

#include "Student.h"
#include "StudentList.h"
class StudentNode
{
    Student student;
    StudentNode *next;

public:
    StudentNode();
    StudentNode(Student student, StudentNode *next = nullptr);
    StudentNode(const StudentNode &studentNode);
    ~StudentNode();
    StudentNode *getNext();
    Student getStudent();
    void setNext(StudentNode *nextNode);
    void setStudent(Student student);
    friend void StudentList::addTail(StudentNode *studentNode);
    friend ostream &operator<<(ostream &out, StudentList &studentList);
    friend void StudentList::findStudentById();
    friend StudentNode* StudentList::getStudentNodeById(string id);
    friend StudentNode* StudentList::getStudentNodeBeforeStudent(StudentNode *studentNode);
    friend void StudentList::removeStudent(string id);
};

#endif 
