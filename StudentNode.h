#include <iostream>
#include "Student.h"
using namespace std;
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
};