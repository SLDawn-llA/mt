//
// Created by Administrator on 2024/2/28.
//

#include<iostream>
#include<map>
using namespace std;

class Student {
public:
    int id;
    string name;
    Student(){}
    Student(int id,string name)
    {
        this->id=id;
        this->name=name;
    }
};
int main()
{//构造一个map容器对象，存储student 对象
    map<int,Student> stus;

    return 0;
}
