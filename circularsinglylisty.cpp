#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int info;
	struct node *next;
	
}NODE;
NODE * create(NODE *list)
{
	NODE *header,*temp,*newnode;
	int i,n;
	printf("nodes:");
	scanf("%d",&n);
	header=(NODE *)malloc(sizeof(NODE));
	header->info=-1;
	header->next=NULL;
	header=list;
	for(i=1;i<n;i++)
	{
		newnode=(NODE *)malloc(sizeof(NODE));
		newnode->next=NULL;
		printf("enter info:\n");
		scanf("%d",&newnode->info);
		if(list->next==list)
		{
			header->next=newnode;
			newnode->next=header;
			list=header;
			temp=header;
			
		}
		else
		{
			temp->next=newnode;
			newnode->next=list;
			temp=newnode;
			
		}
		
	}
	return(list);
	
}
void display(NODE *list)
{
	NODE *temp;
	for(temp=list->next;temp!=list;temp=temp->next)
	{
		printf("%d-->",temp->info);
	}
}
int main()
{
	NODE *list;
	list->next=list;
	list=create(list);
	display(list);
	return 0;
	
	
}
