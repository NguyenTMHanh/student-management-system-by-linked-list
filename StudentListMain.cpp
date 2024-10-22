#include<iostream>
#include "StudentList.h"
using namespace std;

int main(){
    StudentList studenList;
    cin>>studenList;
    cout<<studenList;
    // studenList.addListStudent();
    // cout<<studenList;

    // studenList.findStudentById();
    string id;
    cout<<"nhap ma so sinh vien cua sinh vien ma ban muon xoa: "; cin>>id;
    studenList.removeStudent(id);
    cout<<studenList;
    return 0;
}