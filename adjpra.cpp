#include<stdio.h>
#include<stdlib.h>
void createmat(int m[10][10],int n);
void dispmat(int m[10][10],int n);
void inout(int m[10][10],int n);
void print(int n);
void createlist(int m[10][10],int n);
int main()
{
	int m[10][10];int n;
	printf("how many vertices :\n");
	scanf("%d",&n);
	createmat(m,n);
	dispmat(m,n);
	inout(m,n);
  createlist(m,n);
  print(n);
}
void createmat(int m[10][10],int n)
{
	for(int i=0;i<n;i++)
	{ for(int j=0;j<n;j++)
	{
		m[i][j]=0;
		if(i!=j)
		{
			printf("is their edge between %d--->%d:(1/0):",i+1,j+1);
			scanf("%d",&m[i][j]);
		}
	}
	}
}
void dispmat(int m[10][10],int n){
		for(int i=0;i<n;i++)
	{ for(int j=0;j<n;j++)
	{	printf("%3d",m[i][j]);
}
printf("\n");
}
}
void inout(int m[10][10],int n)
{  int static in,out;
	for(int i=0;i<n;i++)
	
	  { in =0;
	  out=0;
	 for(int j=0;j<n;j++)
	{
		in+=m[j][i];
		out+=m[i][j];
		
} 
printf("\nindegree of %d is:%d\n",i+1,in);
printf("\n out degree of %d is:%d\n",i+1,out);
printf("\n total degree of %d is:%d\n",i+1,in+out);
}
}
typedef struct  node
{
	int vertex;
	struct node *next;
}NODE;
NODE *list[10];
void createlist(int m[10][10],int n)
{
	int i,j;
	NODE *temp,*newnode;
	for(i=0;i<n;i++)
	
	 {list[i]=NULL;
	  for(j=0;j<n;j++)
	{
	  if(m[i][j]==1)
	  {
	  
		newnode=(NODE *)malloc(sizeof(NODE));
		newnode->next=NULL;
		newnode->vertex=j+1;
		if(list[i]==NULL)
		{
			list[i]=temp=newnode;
		}
		else
		{
			temp->next=newnode;
			temp=newnode;
		}
	}
}
}
}
void print(int n)
{
	NODE *temp;int i;
	for(i=0;i<n;i++)
	{
		printf("V%d-->",i+1);
		temp=list[i];
		while(temp)
		{
			printf("V%d-->",temp->vertex);
			temp=temp->next;
		}
		printf("NULL\n");
	}
}
