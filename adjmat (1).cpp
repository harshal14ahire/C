#include<stdio.h>
#include<stdlib.h>
void dis(int n);
 void createadjlist(int m[10][10],int n);
typedef struct node
{
	int vertex;
	struct node *next;
	
}NODE;
NODE *list[20];
void createmat(int [10][10],int );
void displaymat(int [10][10],int );

/*int greater(int [3][3]);*/
int main()
{ int n,m[10][10];
printf("how many vertices:\n");
 scanf("%d",&n);
 createmat(m,n);
 displaymat(m,n);
 createadjlist(m,n);
 dis( n);
/* greater(m);*/
	return 0;
}
 void createmat(int m[10][10],int n)
{
	int i,j;
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	{
		m[i][j]=0;
		if(i!=j)
		{
		printf("is their edge between Vertex:%d -> Vertex %d:(1/0):=",i+1,j+1);
			scanf("%d",&m[i][j]);
			
		}
	}
}
void displaymat(int m[10][10],int n)
{
	int i,j;
	printf("Adjancency Matrix is :\n");
	for(i=0;i<n;i++)
	{
	    for(j=0;j<n;j++)
		printf("%5d",m[i][j]);
		printf("\n");
	}
		
			
}  
 void createadjlist(int m[10][10],int n)
 {
 	int i,j;
 	NODE *temp,*newnode;
 	for(i=0;i<n;i++)
	{
		list[i]=NULL;
		for(j=0;j<n;j++)//
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
void dis(int n)
{
	NODE *temp;
	int i;
	printf("\n adjancecny  list is:\n");
	for(i=0;i<n;i++)
	{
		printf("V%d-->",i+1);
		temp=list[i];
		while(temp!=NULL)
		{
			printf("V%d-->",temp->vertex);
			temp=temp->next;
			
		}
		printf("NULL\n");
		
	}
}
