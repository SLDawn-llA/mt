//
// Created by Administrator on 2024/2/13.

#if 0
#include<iostream>
#include<set>

using namespace std;
int main()
{   //less 升序    greater 降序
    set<int> s1;//set 容器默认是以升序排序 相当于set<int,less<int>> s1;

    s1.insert(3);
    s1.insert(2);
    s1.insert(6);
    s1.insert(1);
//    set<int,greater<int>> s4(s1);//拷贝构造函数 只能升序拷贝升序   降序拷贝降序 所以 错误
    set<int,greater<int>> s4;
    s4.insert(4);
    s4.insert(2);
    s4.insert(6);
    s4.insert(1);
set<int>::iterator it;
    cout<<"s1:";
    for(it=s1.begin();it!=s1.end();it++)
        cout<<*it<<" ";
    cout<<endl;
    it=s1.find(10) ;  //find函数的返回值为找到元素的迭代器 找不到时 返回end()
            if(it==s1.end())//it==NULL是错的 因为null就相当于空指针类型 而it是迭代器类型 二者之间不能画等号
                cout<<"can not find 10";

             else
                cout<<*it<<endl;
             cout<<endl;

    cout<<"s4:";
    for(it=s4.begin();it!=s4.end();it++)
        cout<<*it<<" ";
cout<<endl;
#endif
#if 0
    set<int>::reverse_iterator it2;
    cout<<"s1:";
    for(it2=s1.rbegin();it2!=s1.rend();it2++)
        cout<<*it2<<" ";
    cout<<endl;

    set<int>s2(s1);//拷贝构造函数
    set<int>s3;//默认构造函数
    s3=s2;
    cout<<"s3:";
    for(it=s3.begin();it!=s3.end();it++)
        cout<<*it<<" ";
    cout<<endl;
    s3.insert(10);
    s3.swap(s1);
    cout<<"s1:";
    for(it=s1.begin();it!=s1.end();it++)
    cout<<*it<<" ";
    cout<<endl;

    //删除set元素的最大值 只能用正向的迭代器  下面反向 的报错
    //因为set容器是以升序排列 所以比较容易删除   最大最小值
    it=s3.end();
    it--;
    s3.erase(it);
    cout<<"it(s3):"<<*it<<endl;
    it--;//迭代器重新指向容器第一个元素  可能讲错了   ！！！！！！！！！！！ erase 后迭代器指向啥待定（查查
    cout<<"it(s3):"<<*it<<endl;
    cout<<"s3:";
    for(it=s3.begin();it!=s3.end();it++)
        cout<<*it<<" ";
    cout<<endl;

#if 0//不能用反向迭代器删除元素
    set<int>::reverse_iterator it3=s3.rbegin();//it3 指向容器最后一个元素
    s3.erase(it3);
    for(it=s3.begin();it!=s3.end();it++)
        cout<<*it<<" ";
    cout<<endl;
#endif

    //删除指定值     erase函数 返回值是 不在容器返回flase(零)  在容器中返回true (非零）
    cout<<s3.erase(4)<<endl;
    cout<<s3.erase(100)<<endl;
    for(it=s3.begin();it!=s3.end();it++)
        cout<<*it<<" ";
    cout<<endl ;
#endif
