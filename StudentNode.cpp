#include <iostream>
#include "StudentNode.h"
using namespace std;

// hàm dựng mặc định không làm gì cả
StudentNode::StudentNode()
{
    this->next = nullptr;
}

// hàm dựng với tham số
StudentNode::StudentNode(Student student, StudentNode *next)
{
    this->student = student;
    this->next = next;
}

// hàm dựng sao chép
StudentNode::StudentNode(const StudentNode &studentNode)
{
    this->student = studentNode.student;
    this->next = studentNode.next;
}

// hàm hủy
StudentNode::~StudentNode()
{
}

//hàm lấy con trỏ trỏ đến node kế tiếp
StudentNode* StudentNode::getNext(){
    return this->next;
}

//hàm thiết lập con trỏ trỏ đến node kế tiếp
void StudentNode::setNext(StudentNode *nextNode){
    this->next = nextNode;
}

//hàm lấy data của một node
Student StudentNode::getStudent(){
    return this->student;
}

//hàm thiết lập data cho một node
void StudentNode::setStudent(Student student){
    this->student = student;
}