#include<stdio.h>
#include <string.h> 
#include <stdlib.h>
  
typedef char ElemType;
  
typedef struct linknode
{
  ElemType data;
  struct linknode *next;
}LiStack;
  
void InitStack(LiStack **s)
{
  *s=(LiStack *)malloc(sizeof(LiStack));
  (*s)->next=NULL;
}
  
void push(LiStack *s, ElemType e)
{
  LiStack *p;
  LiStack *temp = s;
  while(NULL != temp->next)
  {
    temp = temp->next;
  }
  p=(LiStack *)malloc(sizeof(LiStack));
  p->data=e;
  p->next=NULL;
  temp->next=p;
  temp = p;
}
  
ElemType pop(LiStack *s)
{
   LiStack *p = s;
   LiStack *temp = s;
   ElemType e;
   if(p->next==NULL)
       return NULL;
   while(NULL != p->next)
  {
    temp = p;
    p = p->next;
  }
   e=p->data;
   temp->next = NULL;
   free(p);
   return e;
}
  
bool compare(ElemType str[])
{
  int i,m;
  bool flag = true;
  ElemType e=' ';
  LiStack *s=NULL;
  /*
  m=10;
  for(i=0;i<m;i++) 
  {
     scanf("str[i]\n",e);
  }
   
  InitStack(&s);
  for(m=0;str[m]!='\0';m++)
      for(i=0;i<(m+1)/2;i++)
      {
        push(s,str[i]);
      }
  pop(s,e);
  for(i=m/2;i<m;i++)
        if(str[i]!=e)
            return 0;
        else
            return 1;
        return 0;
        */
  InitStack(&s);
  for(i = 0; i < strlen(str); i++)
  {
    push(s,str[i]);
  }
  for(i = 0; i < strlen(str); i++)
  {
    if (str[i] != pop(s))
    {
        flag = false;
        break;
    }
  }
  return flag;
}
  
int main()
{
  ElemType str[50];
  scanf("%s",str);
  if(compare(str))
      printf("\nright");
      else
      printf("\nwrong");
       
}