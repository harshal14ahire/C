#include<stdio.h>
#include<stdlib.h>
struct q
{
  int data[20];
  int front,rear;
}q1;
 
struct node
{
  int vertex;
  struct node *next;
} *v[10];

void add(int n)
{
 q1.rear++;
 q1.data[q1.rear]=n;
}

int del()
{
 q1.front++;
 return q1.data[q1.front];
}
 
void initq()
{
 q1.front=q1.rear=-1;
}

int emptyq()
{
 return(q1.rear==q1.front);
}

void creatematrix(int m[10][10],int n)
{
  int i,j;
 // char ans;
  for(i=0;i<n;i++)
  for(j=0;j<n;j++)
   {
     m[i][j]=0;
     if(i!=j)
     {

   {
     printf("\n Is there an edge between %d and %d(1/0)",i+1,j+1);
     scanf("%d",&m[i][j]);
    }
 } 
}
}
void displaymatrix(int m[10][10],int n)
{
  int i,j;
  printf("\n The adjacency matrix is:\n");
  for(i=0;i<n;i++)
   {
     for(j=0;j<n;j++)
     printf("%5d",m[i][j]);
     printf("\n");
   } 
}

void createlist(int m[10][10],int n)
{
  int i,j;
  struct node *temp,*newnode;
  for(i=0;i<n;i++)
  {
    v[i]=NULL;
    for(j=0;j<n;j++)
    {
     if(m[i][j]==1)
       {
        newnode=(struct node*)malloc(sizeof(struct node));
         
         newnode->vertex=j+1;
         newnode->next=NULL;
         if(v[i]==NULL)
          v[i]=temp=newnode;
         else
         {
           temp->next=newnode;
           temp=newnode;
         }
        }
    }
  }
}
void displaylist(int n)
{
   struct node *temp;
   int i;
   for(i=0;i<n;i++)
    { 
       printf("\nv%d |",i+1);
       temp=v[i];
       while(temp)
      {
        printf("v%d->",temp->vertex);
        temp=temp->next;
       }
       printf("null");
}
}
void bfs(int m[10][10], int n)
{
  int i,j,w,v;
  int visited[20];
  initq();
  for(i=0;i<n;i++)
  visited[i]=0;
  printf("\n BFS traversal is:\n");
  v=0;
   visited[v]=1;
  add(v);
  while(!emptyq())
   {
     v=del();
      printf("\nv%d",v+1);
      printf("\n");
     for(w=0;w<n;w++)
     if((m[v][w]==1)&&(visited[w]==0))
        {
           add(w);
           visited[w]=1;
        }
}
}
void main()
{
  int m[10][10],n;
  printf("\n Enter no.of vertices");
  scanf("%d",&n);
  creatematrix(m,n);
displaymatrix(m,n);
 createlist(m,n);
displaylist(n);
bfs(m,n);
}
  
