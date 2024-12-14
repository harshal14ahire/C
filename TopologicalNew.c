#include<stdio.h>
#define MAXSIZE 10
typedef struct
{
 int data[MAXSIZE];
 int top;
}STACK;
 void push(STACK *ps,int n)
 {
   ps->data[++ps->top]=n;
 }
 int pop(STACK *ps)
 {
   return ps ->data[ps->top--];
 }
 void init(STACK *ps)
 {
  ps->top=-1;
 }
 int isempty(STACK *ps)
 {
 return(ps->top==-1);
 }
 
 void topologicalSort(int n)
 {
    int i,j,v,w;
    int visited[20]={0};
    int indeg[10]={0};
    //calculate indegrees
    for(i=0;i<n;i++)
     for(j=0;j<n;j++)
      indeg[i]=indeg[i]+m[i][j];
      STACK s;
      init(&s);
      while(1)
      {
        for(v=0;v<n;v++)
         if((visited[v]==0)&&(indeg[v]==0))
         {
          visited[v]=1;
          push(&s,v);
          printf("v%d",v+1);
          }
      if(isempty(&s))
         break;
       v=pop(&s);
       for(w=0;w<n;w++)
          if(m[v][w]==1)
             indeg[w]=indeg[w]-1;
             }
             }
void main()
 {
    int m[5][5]={{0,1,1,0,0},{0,0,0,1,0},{0,0,0,1,1},{0,0,0,0,1},{0,0,0,0,0}};
      topologicalSort(m,5);  
 }
