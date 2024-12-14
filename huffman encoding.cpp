#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 20

//binary tree node
typedef struct node
{
	char code[10];
	char ch ;
	int freq;
	struct node *left,*right;
}node;
typedef struct 
{
	node *data[MAXSIZE];
	int front,rear;
	
}QUEUE;
 void initQ(QUEUE *pq)
{
	pq->rear=pq->front=-1;
	
}

void addQ(QUEUE *pq,node *num)
{
	int i;
	for(i=pq->rear;i>pq->front;i--)
	{
		if(num->freq<pq->data[i]->freq)
		{
			pq->data[i+1]=pq->data[i];
			
		}
		else
		{
			break;
		}
    }
	 pq->data[i+1]=num;
	 pq->rear++;
    
}

node* removeQ(QUEUE *pq)
{
	node *num;
	pq->front++;
	num=pq->data[pq->front];
	return(num);
	
}
int isempty(QUEUE *pq)
{
	return(pq->rear==pq->front);
}

node* getnode(char ch,int f)
{
	node *ptr;
	ptr=(node*)malloc(sizeof(node));
	ptr->ch=ch;
	ptr->freq=f;
	strcpy(ptr->code,"code=");
	ptr->left=ptr->right=NULL;
	return ptr;
	
}

void encode(node *root)
{
	if(root!=NULL)
	{
		if((root->left==NULL)&&(root->right==NULL ))
		    printf("\n%c->%d->%s",root->ch,root->freq,root->code);
		if(root->left!=NULL)
		{
			strcpy(root->left->code,root->code);
			strcat(root->left->code,"0");
			encode(root->left);
			
		}
		if(root->right!=NULL)
		{
			strcpy(root->right->code,root->code);
			strcat(root->right->code,"1");
			encode(root->right);
			
		}
	}
}

void huffman(node *list[],int n)
{
	int i,sum;
	node *t1,*t2,*t3;
	QUEUE q;
	initQ(&q);
	for(i=0;i<n;i++)
	{
		addQ(&q,list[i]);
		
	}
	while(1)
	{
		t1=removeQ(&q);
		  if(isempty(&q));
		    break;
		t2=removeQ(&q);
	    t3=getnode('-',t1->freq+t2->freq);
	    t3->left=t1;
	    t3->right=t2;
		addQ(&q,t3);
	}
	encode(t1);
}
int main()
{
	int n,i,f;
	char ch;
	node *newnode;
	node *list[10];
	printf("how many characters :");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter the char & freq:");
		scanf("%c",&ch);
		scanf("%d",&f);
		list[i]=getnode(ch,f);
		
	}
	huffman(list,n);
	
}
