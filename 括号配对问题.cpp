#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#define MI 100
#define MX 1000
using namespace std;
typedef struct
{
    int *top;
    int *base;
    int stacklist;
}sqstack;
int inistack(sqstack &s)
{
    s.base =(int *)malloc(MI*sizeof(int));
    if(!s.base)exit(-2);
    s.top=s.base;
    s.stacklist=MI;
    return 0;
}
int push(sqstack &s,int e)
{
    if(s.top-s.base==s.stacklist)
    {
        s.base=(int *)realloc(s.base,(s.stacklist+MX)*sizeof(int));
        s.top=s.base+s.stacklist;
        s.stacklist+=MX;
    }
    *s.top++=e;
    return 1;
}
int pop(sqstack &s)
{
    if(s.top==s.base)return 0;
    *--s.top;
    return 1;
}
int gettop(sqstack &s,char &e)
{
    if(s.top==s.base)return 0;
    e=*(s.top-1);
    return 1;
}
int main()
{
    int n;
    sqstack s;
    char c,e;
    cin>>n;
    getchar();
    while(n--)
    {
        inistack(s);
        while((c=getchar())!='\n'){
            if(s.top==s.base)push(s,c);
            else
            {if(c=='('||c=='[')push(s,c);
            if(c==')')
                {
                    gettop(s,e);
                    if(e=='(')pop(s);
                    else push(s,c);
                }
             if(c==']')
                {
                    gettop(s,e);
                    if(e=='[')pop(s);
                    else push(s,c);
                }
            }
        }
        if(s.top==s.base)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}