#include<iostream>
#include "StudentList.h"
using namespace std;

int main(){
    StudentList studenList;
    cin>>studenList;
    cout<<studenList;
    // studenList.addListStudent();
    // cout<<studenList;

    studenList.searchStudent();
    return 0;
}