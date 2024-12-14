#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int info;
	struct node *left,*right;
}NODE;
int find(NODE *root,int key);
void inorder(NODE *root);
NODE * BST(NODE *root);
NODE * BST(NODE *root)
{
	NODE *temp,*parent,*newnode;
	int i,num,n;
	printf("nodes:?:");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		newnode=(NODE *)malloc(sizeof(NODE));
		newnode->left=newnode->right=NULL;
		printf("enter info:");
		scanf("%d",&num);
		newnode->info=num;
		if(root==NULL)
		{
			root=newnode;
			continue;
		}
		temp=root;
		while(temp!=NULL)
		{
			parent=temp;
			if(num<temp->info){
				temp=temp->left;
			}
			else
			{
				temp=temp->right;
			}
		}
		if(num<parent->info)
		{
			parent->left=newnode;
		}
		else
		parent->right=newnode;
	}
	return root;
}
void inorder(NODE *root)
{
	NODE *temp=root;
	if(root!=NULL)
	{
		
		inorder(temp->left);
		printf("%d-->",temp->info);
		inorder(temp->right);
	}
}
int find(NODE *root,int key)
{
	if(root==NULL)
	{
		return 0;
	}
	NODE *temp=root;
	while(temp!=NULL)
	{
		if(key==root->info)
		{
			return 1;
		}
		if(key<temp->info)
		temp=temp->left;
		else
		temp=temp->right;
	}
	return 0;
}
NODE * insert (NODE *root,int num)
{
	NODE *temp=root,*newnode,*parent;
	newnode=(NODE *)malloc(sizeof(NODE));
	newnode->left=newnode->right=NULL;
	newnode->info=num;
	if(root==NULL)
	{
		root=newnode;
		return root;
	}
	//else
	while(temp!=NULL)
		{
			parent=temp;
			if(num<temp->info){
				temp=temp->left;
			}
			else
			{
				temp=temp->right;
			}
		}
		if(num<parent->info)
		{
			parent->left=newnode;
		}
		else
		parent->right=newnode;
	
/*	if(num<temp->info)
	temp->left=insert(temp->left,num);
	else
	temp->right=insert(temp->right,num);
*/	
	return root;
	}
	int count(NODE *root)
	{
		NODE *temp=root;
		int static count1;
		if(temp!=NULL)
		{
			count1++;
			count(temp->left);
			count(temp->right);
			
		}
		return count1;
	}
int leaf(NODE *root)
{
	NODE *temp=root;int static leaf1;
	if(temp!=NULL)
	{ if(temp->left==NULL&&temp->right==NULL)
	{
		leaf1++;
		
	}
	leaf(temp->left);
	leaf(temp->right);
		
	}
	return leaf1;
}
int main()
{
	NODE *root=NULL;int ele2;int i;
	root=BST(root);
	inorder(root);
	int key;
	printf("enter key :");
	scanf("%d",&key);
	insert(root,key);
	inorder(root);
	/*	i=count(root);
	printf("total no of nodes is %d :",i);
	int j;
	j=leaf(root);
		printf("total no of leaf nodes is %d :",j);
*/	return 0;
}
