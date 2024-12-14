#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *left;
	struct node *right;
	
};
typedef struct node NODE;
NODE *root;
NODE *create(NODE*);
void inorder(NODE*);
int main()
{
	root=NULL;
	root=create(root);
	printf("Inorder traversal....\n");
	inorder(root);
	return 0;
}
NODE *create(NODE *root)
{
	int i,n;
	NODE *newnode,*temp;
	printf("how many nodes?");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("Enter info");
		scanf("%d",&newnode->info);
		newnode->left=newnode->right=NULL;
		if(root==NULL)
		   root=newnode;
		else
		{
			temp=root;
			while(temp!=NULL)
			{
				if(newnode->info<temp->info)
				{
					if(temp->left==NULL)
					{
						temp->left=newnode;
						break;
						
					}
					else
					temp=temp->left;
					
				}
				else
				    if(newnode->info>temp->info)
				    {
				    	if(temp->right==NULL)
				    	{
				    		temp->right=newnode;
				    		break;
				    		
						}
						else
						temp=temp->right;
					}
			}
       }
    }
    return(root);
}
void inorder(NODE *root)
{
	NODE *temp;
	temp=root;
	if(temp!=NULL)
	{
		inorder(temp->left);
		printf("%d\t",temp->info);
		inorder(temp->right);
	}
}
