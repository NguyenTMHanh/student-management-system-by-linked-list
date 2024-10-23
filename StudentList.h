#include <iostream>
#include <fstream>
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
    void findStudentById();
    StudentNode* getStudentNodeById(string id);
    void removeStudent(string id);
    StudentNode* getStudentNodeBeforeStudent(StudentNode *StudentNode);
    void updateStudentById(string id);
    void sortStudentListByGPA();
    void readFile(ifstream &input);
};
void formatHeaderPrint();
#endif
