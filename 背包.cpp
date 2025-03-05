//
// Created by Administrator on 2024/2/29.
//
/*
#include<iostream>
#include<algorithm>
using namespace std;
struct coin
{
    int m;
    int v;
}a[110];
int n,t,c;
bool cmp (coin x ,coin y)
{
    return x.v*y.m>y.v*x.m;

}
int main()
{
    int ans=0;
    c=t;
    cin>>n>>t;
    for(int i=0;i<n;i++)
        cin>>a[i].m>>a[i].v;
    sort(a,a+n,cmp);
    for(int i=0;i<n;i++)
    {   if(a[i].m<t)
        {c-=a[i].m;
            ans+=a[i].v;
        }
        else
        {
            ans+=c*a[i].v/a[i].m;
       } break;
    }
    cout<<1.0*ans<<endl;
    return 0;
}*/