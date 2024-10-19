#include <iostream>
#include "StudentNode.h"
using namespace std;

class StudentList
{
    StudentNode *head;
    StudentNode *tail;

public:
    StudentList();
    StudentList(const StudentList &studentList);
    ~StudentList();
};
