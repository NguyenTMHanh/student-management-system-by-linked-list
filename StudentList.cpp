#include <iostream>
#include <iomanip>
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
    formatHeaderPrint();
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
    cout<<"\nnhap so luong sinh vien muon them: "; cin>>size;
    while(i<=size){
        cout<<"\nNHAP THONG TIN SINH VIEN MUON THEM THU "<<i<<" :"<<endl;
        cin>>student;
        this->addTail(new StudentNode (student, nullptr));
        i++;
    }
}

//hàm tìm kiếm một sinh viên dựa trên mã số sinh viên
//hàm này trả về thông tin của sinh viên có mã số sinh viên trùng khớp đầu tiên được tìm thấy
void StudentList::findStudentById(){
    string id;
    cout<<"\nnhap ma so sinh vien cua sinh vien ban muon tim kiem: "; cin>>id;
    StudentNode *studentNode;
    studentNode = this->head;
    while(studentNode != nullptr){
        if(studentNode->student.getIdStudent()==id){
            formatHeaderPrint();
            cout<<studentNode->student;
            return;
        }
        studentNode = studentNode->next;
    }
    cout<<"khong tim thay sinh vien!"<<endl;
}

//hàm này format cho tên cột khi in ra console
void formatHeaderPrint()
{
    cout << "\n                                                        DANH SACH SINH VIEN                                " << endl;
    cout << left << setw(5) << "STT" << setw(15) << "ID" << setw(30) << "Ho va ten"
         << setw(10) << "Lop" << setw(10) << "Khoa" << setw(15) << "Gioi tinh" << setw(10) << "Toan"
         << setw(10) << "Anh" << setw(10) << "Van" << setw(10) << "Diem TB"
         << setw(10) << "Hoc luc" << endl;
}