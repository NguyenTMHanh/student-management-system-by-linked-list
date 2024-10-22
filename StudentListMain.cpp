#include<iostream>
#include "StudentList.h"
using namespace std;

int main(){
    StudentList studenList;
    cin>>studenList;
    cout<<studenList;
    studenList.addListStudent();
    cout<<studenList;
    return 0;
}