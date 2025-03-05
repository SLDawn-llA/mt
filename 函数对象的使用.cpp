//
// Created by Administrator on 2024/3/5.
//
#include<iostream>
#include<set>
using namespace std;

//学生类
class CStudent
{
public:CStudent(int id,string name)
    {
    m_id=id;
    m_name=name;
    }
    int m_id;//姓名
    string m_name;//学号
};
//伪函数类
class StuFunctor
{
    bool operator()(const CStudent &s1,const CStudent &s2)
    {
        return s1.m_id>s2.m_id;
    }
};
int main()
{
    set<CStudent,StuFunctor> stu;
    stu.insert(CStudent(1111,"xiaoming"));
    stu.insert(CStudent(22222,"lou"));
    stu.insert(CStudent(3333,"wang"));
    set<CStudent,StuFunctor>::iterator it1;
    for(it1=stu.begin();it1!=stu.end();it1++)
    {cout<<it1->m_id<<" ";
    cout<<endl;}
    return 0;
}
