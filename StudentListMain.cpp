#include <iostream>
#include <fstream>
#include "StudentList.h"
#include "Student.h"
using namespace std;

int main()
{
    StudentList studentList;
    string id;
    int chose;
    ifstream input;
    ofstream output;
    Student student;
    cout << "CHUONG TRINH QUAN LY SINH VIEN BANG DSLK TRONG C++" << endl;
    cout << "1. Nhap danh sach sinh vien tu ban phim" << endl;
    cout << "2. Nhap danh sach sinh vien tu file input va hien thi ra console" << endl;
    cout << "3. Ghi danh sach sinh vien vao file output" << endl;
    cout << "4. Them mot mang danh sach sinh vien" << endl;
    cout << "5. Cap nhat thong tin sinh vien boi ID" << endl;
    cout << "6. Xoa sinh vien boi ID" << endl;
    cout << "7. Tim kiem sinh vien theo ID" << endl;
    cout << "8. Sap xep danh sach sinh vien theo GPA" << endl;
    cout << "9. Hien thi danh sach sinh vien ra console" << endl;
    cout << "Nhap mot ky tu bat ky de thoat khoi chuong trinh" << endl;
    do
    {
        cout << "\nnhap lua chon cua ban: ";
        cin >> chose;
        switch (chose)
        {
        case 1:
            cin >> studentList;
            break;
        case 2:
            studentList.readFile(input);
            break;
        case 3:
            studentList.writeFile(output);
            break;
        case 4:
            studentList.addListStudent();
            break;
        case 5:
            cout << "nhap ma so sinh vien cua sinh vien ban muon cap nhat: ";
            cin >> id;
            studentList.updateStudentById(id);
            break;
        case 6:
            cout << "nhap ma so sinh vien cua sinh vien ma ban muon xoa: ";
            cin >> id;
            studentList.removeStudent(id);
            break;
        case 7:
            studentList.findStudentById();
            break;
        case 8:
            studentList.sortStudentListByGPA();
            cout<<studentList;
            break;
        case 9:
            cout << studentList;
            break;
        default:
            break;
        }
    } while (chose > 0 && chose < 10);
    return 0;
}