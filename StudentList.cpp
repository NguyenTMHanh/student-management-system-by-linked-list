#include <iostream>
#include "StudentNode.h"
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
        this->head = new StudentNode(studentList.head->getStudent(), nullptr);
        StudentNode *currentSource = studentList.head->getNext();
        StudentNode *currentDest = this->head;
        while (currentSource != nullptr)
        {
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

// hàm thêm một node vào cuối danh sách
void StudentList::addTail(StudentNode *studentNode)
{
    if (this->head == nullptr)
    {
        this->head = studentNode;
        this->tail = studentNode;
    }
    else
    {
        this->tail->next = studentNode;
        this->tail = studentNode;
    }
}

// hàm nhập danh sách
istream &operator>>(istream &in, StudentList &studentList)
{
    int size;
    cout << "Nhap so luong sinh vien: ";
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        cout << "\nNHAP THONG TIN SINH VIEN THU " << i + 1 << " :" << endl;
        Student student;
        in >> student;
        StudentNode *studentNode = new StudentNode(student, nullptr);
        studentList.addTail(studentNode);
    }
    return in;
}

//hàm xuất danh sách
ostream &operator<<(ostream &out, StudentList &studentList){
    StudentNode *studentNode = studentList.head;
    while(studentNode != nullptr){
        out<<studentNode->student;
        studentNode = studentNode->next;
    }
    return out;
}

//hàm thêm một mảng sinh viên vào danh sách
void StudentList::addListStudent(){
    int size;
    int i = 1;
    Student student;
    StudentNode *studentNode;
    cout<<"nhap so luong sinh vien muon them: "; cin>>size;
    while(i<=size){
        cout<<"\nNHAP THONG TIN SINH VIEN MUON THEM THU "<<i<<" :"<<endl;
        cin>>student;
        this->addTail(new StudentNode (student, nullptr));
        i++;
    }
}