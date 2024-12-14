#include <stdio.h>
#include <stdlib.h>
struct node 
{
    int info;
    struct node *left, *right;
};
typedef struct node  NODE;
NODE   *root;

NODE * create(NODE *);
void inorder(NODE *);
void preorder(NODE *);
void postorder(NODE *);
int main()
{
    root = NULL;

    root = create(root);

    printf(" Inorder Traversal \n"); 
     inorder(root);
    printf("\n Pre order traversal \n");
     preorder(root);

    printf("\n Post order traversal \n");
     postorder(root);

return 0;
}

NODE * create(NODE *root)
{
    NODE *newnode, *temp;
    int i,n;

    printf("How many nodes?");
    scanf("%d",&n);
    for(i=1;i<=n;i++)      // 8,5,10,4,6
    {
       newnode = (struct node *) malloc(sizeof(struct node));
       printf("Enter info ");
       scanf("%d",&newnode->info);
       newnode->left = newnode->right = NULL;
            // connection
       if(root == NULL)
           root = newnode;                    
       else                                     
       {
            temp = root;                          
            while(temp!=NULL)
            {
                if(newnode->info < temp->info)
                {
                    if(temp->left == NULL)
                    {
                       temp->left = newnode;
                       break;
                    }
                    else
                        temp=temp->left;
                 }   
                else
                  if(newnode->info >= temp->info)
                  {
                    if(temp->right == NULL)
                    {
                       temp->right = newnode;
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
    temp = root;
    if(temp!=NULL)
    {
       inorder(temp->left);
       printf("%d\t",temp->info);
       inorder(temp->right);
     }
}
void preorder(NODE *root)
{
    // root --- >  left -----> right
  NODE *temp;
  temp = root;
  if(temp!=NULL)
  {
     printf("%d\t",temp->info);
     preorder(temp->left);
     preorder(temp->right);
  }
}
void postorder(NODE *root)
{
    // left  ----> right   ---> root
  NODE *temp;
  temp = root;
  if(temp!=NULL)
  {
     postorder(temp->left);
     postorder(temp->right);
     printf("%d\t",temp->info);
  }
}

