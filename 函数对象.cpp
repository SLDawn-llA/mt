//
// Created by Administrator on 2024/3/5.由set容器中的 升序降序  less greater 引出
////尽管函数指针被广泛用于函数回调 但c++中还提供了一种重要的函数回调方法，就是函数对象
//// 伪函数 类 函数指针
/*
////计算器
#include<iostream>
#include<set>

using namespace std;
typedef int(*FUNC)(int,int);
class cal
{private:
    int func1(int x,int y)
    {
        return x+y;
    }
    int func2(int x,int y)
    {
        return x-y;
    }
    int func3(int x,int y)
    {
        return x*y;
    }
    int func4(int x,int y)
    {
        return x/y;
    }
public: int machine(int x,int y,FUNC f)
    {
        return f(x,y);
    }
};

int func1(int x,int y)
{
    return x+y;
}
int func2(int x,int y)
{
    return x-y;
}
int func3(int x,int y)
{
    return x*y;
}
int func4(int x,int y)
{
    return x/y;
}
 int machine(int x,int y,FUNC f)
{
    return f(x,y);
}
int main()
{
    int x,y;
    cin>>x>>y;
    cout<<machine(x,y,func1)<<endl;////若用类cal的话 就不能用func1了 在类中不能使用？ （还未理解学习类）
    return 0;
}*/