#include <iostream>
#include <fstream>
#include "StudentList.h"
using namespace std;

int main()
{
    StudentList studenList;
    // cin >> studenList;
    // cout << studenList;
    // studenList.addListStudent();
    // cout<<studenList;

    // studenList.findStudentById();
    // string id;
    // cout<<"nhap ma so sinh vien cua sinh vien ma ban muon xoa: "; cin>>id;
    // studenList.removeStudent(id);
    // cout<<studenList;

    // cout << "nhap ma so sinh vien cua sinh vien ban muon cap nhat: ";
    // cin >> id;
    // studenList.updateStudentById(id);
    // cout << studenList;

    // studenList.sortStudentListByGPA();
    // cout << studenList;

    ifstream input;
    studenList.readFile(input);
    return 0;
}