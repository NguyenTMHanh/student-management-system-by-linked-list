#include <iostream>
#include <iomanip>
#include <fstream>
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

// hàm xuất danh sách
ostream &operator<<(ostream &out, StudentList &studentList)
{
    StudentNode *studentNode = studentList.head;
    formatHeaderPrint();
    while (studentNode != nullptr)
    {
        out << studentNode->student;
        studentNode = studentNode->next;
    }
    return out;
}

// hàm thêm một mảng sinh viên vào danh sách
void StudentList::addListStudent()
{
    int size;
    int i = 1;
    Student student;
    StudentNode *studentNode;
    cout << "\nnhap so luong sinh vien muon them: ";
    cin >> size;
    while (i <= size)
    {
        cout << "\nNHAP THONG TIN SINH VIEN MUON THEM THU " << i << " :" << endl;
        cin >> student;
        this->addTail(new StudentNode(student, nullptr));
        i++;
    }
}

// hàm tìm kiếm một sinh viên dựa trên mã số sinh viên
// hàm này trả về thông tin của sinh viên có mã số sinh viên trùng khớp đầu tiên được tìm thấy
void StudentList::findStudentById()
{
    string id;
    cout << "\nnhap ma so sinh vien cua sinh vien ban muon tim kiem: ";
    cin >> id;
    StudentNode *studentNode;
    studentNode = this->head;
    while (studentNode != nullptr)
    {
        if (studentNode->student.getIdStudent() == id)
        {
            formatHeaderPrint();
            cout << studentNode->student;
            return;
        }
        studentNode = studentNode->next;
    }
    cout << "khong tim thay sinh vien!" << endl;
}

// hàm này format cho tên cột khi in ra console
void formatHeaderPrint()
{
    cout << "\n                                                        DANH SACH SINH VIEN                                " << endl;
    cout << left << setw(5) << "STT" << setw(15) << "ID" << setw(30) << "Ho va ten"
         << setw(10) << "Lop" << setw(10) << "Khoa" << setw(15) << "Gioi tinh" << setw(10) << "Toan"
         << setw(10) << "Anh" << setw(10) << "Van" << setw(10) << "Diem TB"
         << setw(10) << "Hoc luc" << endl;
}

// hàm này trả về sinh viên đầu tiên có mã số sinh viên trùng với mã số sinh viên cần tìm
StudentNode *StudentList::getStudentNodeById(string id)
{
    StudentNode *studentNode;
    studentNode = this->head;
    while (studentNode != nullptr)
    {
        if (studentNode->student.getIdStudent() == id)
        {
            return studentNode;
        }
        studentNode = studentNode->next;
    }
    return nullptr;
}

// hàm trả về 1 student nằm trước 1 student
StudentNode *StudentList::getStudentNodeBeforeStudent(StudentNode *studentNode)
{
    StudentNode *currentStudent;
    currentStudent = this->head;
    while (currentStudent != nullptr)
    {
        if (currentStudent->next == studentNode)
        {
            return currentStudent;
        }
        currentStudent = currentStudent->next;
    }
    return nullptr;
}

// hàm xóa một student theo id
void StudentList::removeStudent(string id)
{
    StudentNode *currentStudent = getStudentNodeById(id);
    if (currentStudent != nullptr)
    {
        if (currentStudent == this->head)
        {
            this->head = currentStudent->next;
            delete currentStudent;
        }
        else
        {
            StudentNode *beforeStudent = getStudentNodeBeforeStudent(currentStudent);
            if (beforeStudent == nullptr)
            {
                cout << "Loi: khong tim thay sinh vien nam truoc sinh vien hien tai" << endl;
            }
            else
            {
                beforeStudent->next = currentStudent->next;
                delete currentStudent;
            }
        }
    }
    else
    {
        cout << "khong tim thay sinh vien can xoa" << endl;
    }
}

// hàm cập nhật thông tin của sinh viên theo id
void StudentList::updateStudentById(string id)
{
    StudentNode *currentStudent = this->getStudentNodeById(id);
    if (currentStudent != nullptr)
    {
        cout << "ban muon cap nhat thong tin gi cua sinh vien co ma so " << id << "?" << endl;
        cout << "1. Ho va ten" << endl;
        cout << "2. Lop" << endl;
        cout << "3. Khoa" << endl;
        cout << "4. Gioi tinh" << endl;
        cout << "5. Diem Toan" << endl;
        cout << "6. Diem Tieng anh" << endl;
        cout << "7. Diem Van" << endl;
        int chose;
        do
        {
            cout << "Hay nhap lua chon cua ban(ban muon cap nhat thong tin nao cua sinh vien): ";
            cin >> chose;
            switch (chose)
            {
            case 1:
                cout << "Nhap ten: ";
                getline(cin >> std::ws, currentStudent->student.name);
                break;
            case 2:
                cout << "Nhap lop: ";
                cin >> currentStudent->student.className;
                break;
            case 3:
                cout << "nhap khoa: ";
                cin >> currentStudent->student.facultyName;
                break;
            case 4:
                cout << "Nhap gioi tinh:";
                cin >> currentStudent->student.sex;
                break;
            case 5:
                cout << "Nhap diem Toan: ";
                cin >> currentStudent->student.mathScore;
                currentStudent->student.averageScore = currentStudent->student.caculateGPA();
                currentStudent->student.academicPerformance = currentStudent->student.getAcademicPerformance(currentStudent->student.averageScore);
                break;
            case 6:
                cout << "Nhap diem Tieng anh: ";
                cin >> currentStudent->student.englishScore;
                currentStudent->student.averageScore = currentStudent->student.caculateGPA();
                currentStudent->student.academicPerformance = currentStudent->student.getAcademicPerformance(currentStudent->student.averageScore);
                break;
            case 7:
                cout << "Nhap diem Van: ";
                cin >> currentStudent->student.literatureScore;
                currentStudent->student.averageScore = currentStudent->student.caculateGPA();
                currentStudent->student.academicPerformance = currentStudent->student.getAcademicPerformance(currentStudent->student.averageScore);
                break;
            default:
                break;
            }
        } while (chose > 0 && chose < 8);
    }
}

// hàm sắp xếp danh sách theo GPA
void StudentList::sortStudentListByGPA()
{
    if (this->head == nullptr)
    {
        return;
    }
    for (StudentNode *temp = this->head; temp != nullptr; temp = temp->next)
    {
        for (StudentNode *temp2 = temp->next; temp2 != nullptr; temp2 = temp2->next)
        {
            if (temp2->student.averageScore > temp->student.averageScore)
            {
                Student tempStudent = temp2->student;
                temp2->student = temp->student;
                temp->student = tempStudent;
            }
        }
    }
}

// hàm đọc file đầu vào input
void StudentList::readFile(ifstream &input)
{
    input.open("input.txt", ios::in);
    if (!input.is_open())
    {
        cout << "khong the mo file" << endl;
        return;
    }
    string line;
    while (getline(input, line))
    {
        Student student;
        stringstream ss(line);
        string math, english, literature;
        getline(ss, student.id, ',');
        getline(ss, student.name, ',');
        getline(ss, student.className, ',');
        getline(ss, student.facultyName, ',');
        getline(ss, student.sex, ',');
        getline(ss, math, ',');
        getline(ss, english, ',');
        getline(ss, literature, ',');
        student.mathScore = stof(math);
        student.englishScore = stof(english);
        student.literatureScore = stof(literature);
        student.averageScore = student.caculateGPA();
        student.academicPerformance = student.getAcademicPerformance(student.averageScore);
        StudentNode *studentNode = new StudentNode(student, nullptr);
        this->addTail(studentNode);
    }
    formatHeaderPrint();
    cout << *this;
    input.close();
}
