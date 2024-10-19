#include <iostream>
#include "StudentList.h"
using namespace std;

// hàm dựng mặc định
StudentList::StudentList()
{
    this->head = nullptr;
    this->tail = nullptr;
}

// hàm dựng sao chép
StudentList::StudentList(const StudentList &studentList)
{
    if (studentList.head == nullptr)
    {
        this->head = this->tail = nullptr;
    }
    else
    {
        this -> head = new StudentNode(studentList.head->getStudent(), nullptr);
        StudentNode *currentSource = studentList.head->getNext();
        StudentNode *currentDest = this->head;
        while(currentSource!=nullptr){
            StudentNode *newNode = new StudentNode(currentSource->getStudent(), nullptr);
            currentDest->setNext(newNode);
            currentDest = newNode;
            currentSource = currentSource->getNext();
        }
        this->tail = currentDest;
    }
}

// hàm hủy
StudentList::~StudentList()
{
    while (this->head != nullptr)
    {
        StudentNode *temp = this->head;
        this->head = this->head->getNext();
        delete temp;
    }
}