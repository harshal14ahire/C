
#include<stdio.h>
#include<stdlib.h>

typedef struct bst
{
   int info;
   struct bst*left,*right;
}NODE;

NODE*root;
NODE*create(NODE*);
void inorder(NODE*);
void preorder(NODE*);
void postorder(NODE*);
NODE*search(NODE*root,int key);
NODE*create(NODE*root)
{
   NODE*newnode,*temp;
   int i,n;
   printf("Enter how many nodes?");
   scanf("%d",&n);
   for(i=1;i<=n;i++)
      {
        newnode=(NODE*)malloc(sizeof(NODE));
        printf("Enter elements:- ");
        scanf("%d",&newnode->info);
        newnode->left=newnode->right=NULL;
        if(root==NULL)
          {
             root=newnode;
          }
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
                              {
                                  temp=temp->left;
                              }
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
                              {
                                  temp=temp->right;
                              }
                       }
                 } 
          }
      }
return(root);
}

void inorder(NODE*root)
{
   NODE*temp;
   temp=root;
   if(temp!=NULL)
     {
        inorder(temp->left);
        printf("%d\t",temp->info);
        inorder(temp->right);
     }
}

void postorder(NODE*root)
{
   NODE*temp;
   temp=root;
   if(temp!=NULL)
     {
        postorder(temp->left);
        postorder(temp->right);
        printf("%d\t",temp->info);
     }
}

void preorder(NODE*root)
{
   NODE*temp;
   temp=root;
   if(temp!=NULL)
     {
        printf("%d\t",temp->info);
        preorder(temp->left);
        preorder(temp->right);
     }
}

NODE*search(NODE*root,int key)
{
   NODE*temp=root;
 while(temp==NULL || temp->info==key)
{
    if(root->info==key)
      return(temp);
    else  
    if(key<temp->info)
      return search(temp->left,key);
   else
      return search(temp->right,key);
}
return 0;    
}
NODE*insert(NODE*root,int n)
{
   if(root==NULL)
   {
      root=(NODE*)malloc(sizeof(NODE));
      root->info=n;
      root->left=root->right=NULL;
   }
   else
      if(n<root->info)
         root->left=insert(root->left,n);
      else
         root->right=insert(root->right,n);
      return(root);
}
int main()
{
   int key,n,choice;
   NODE*temp;
   root=NULL;
   do
   {
     printf("\n1)CREATE\n2)INSERT \n3)SEARCH \n4)INORDER \n5)PREORDER \n6)POSTORDER \n7)EXIT\n");
     printf("Enter your choice");
     scanf("%d",&choice);
     switch(choice)
        {
            case 1: root=create(root);
                    break;
            case 2: printf("Enter element to insert");
                    scanf("%d",&n);
                    root=insert(root,n);
                    break;
            case 3: printf("Enter key to search");
                    scanf("%d",&key);
                    temp=search(root,key);
                    if(temp==NULL)
                        printf("\n %d is not found\n",key);
                    else
                        printf("\n %d is found",key);
                    break;
            case 4: printf("\nInorder traversal.....\n");
                    inorder(root);
                    break;
            case 5: printf("\npreorder traversal.....\n");
                    preorder(root);
                    break;
            case 6: printf("\npostorder traversal.....\n");
                    postorder(root);
                    break;
            case 7:exit(0);
        }
   }while(choice!=7);
 return 0;
}
   
   
   
   
 

