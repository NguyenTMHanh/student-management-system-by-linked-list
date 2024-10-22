#include <iostream>
using namespace std;
#ifndef STUDENT_LIST_H
#define STUDENT_LIST_H

class StudentNode;
class StudentList
{
    StudentNode *head;
    StudentNode *tail;

public:
    StudentList();
    StudentList(const StudentList &studentList);
    ~StudentList();
    friend istream &operator>>(istream &in, StudentList &studentList);
    friend ostream &operator<<(ostream &out, StudentList &studentList);
    void addTail(StudentNode *studentNode);
    void addListStudent();
};

#endif
