/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include<stdio.h>

#include<stdlib.h>

typedef struct node{
int info;
struct node *next;
}NODE;

NODE* create(NODE *list)
{
        int i,n;
        NODE *newnode,*temp;
        printf("enter how many list\n");
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
                newnode=(NODE*)malloc(sizeof(NODE));
                printf("enter the data\n");
                scanf("%d",&newnode->info);
                newnode->next=NULL;
                if(list==NULL)
                {
                        list=temp=newnode;

                }
                else
                {
                        temp->next=newnode;
                        temp=newnode;

                }

        }
        return (list);

}
int display(NODE *list)
{
        NODE *temp;
        for(temp=list;temp!=NULL;temp=temp->next)
        {
                printf("%d---->",temp->info);
        }
}




 NODE * merge(NODE  * list1 ,NODE *list2,NODE  *list3)
{
NODE  *t1,*t2,*t3,*newnode;
t1=list1;
t2=list2;
t3=list3;
while(t1!=NULL && t2!=NULL)
{
newnode =(NODE  *) malloc(sizeof (NODE));
newnode->next =NULL;
if((t1->info) < (t2->info))
{
    newnode->info=t1->info;
    t1=t1->next;
    
}
else
{
    newnode->info=t2->info;
    t2=t2->next;
}
newnode->next=NULL;
if(list3==NULL )
{
    list3=t3=newnode;
}
else
{
    t3->next =newnode;
    t3=newnode;
}
}
while(t1!=NULL )
{
    newnode =(NODE  *)malloc(sizeof (NODE ));
    newnode->info =t1->info;
    newnode->next=NULL;
    t3->next =newnode;
    t3=newnode;
    t1=t1->next;
    
}
while (t2!=NULL )
{
    newnode =(NODE *)malloc (sizeof (NODE ));
    newnode->info =t2->info;
    newnode->next =NULL;
    t3->next=newnode ;
    t3=newnode;
    t2=t2->next;
    
}
return (list3);
}

int main()
{
NODE  *list1=NULL,*list2=NULL,*list3=NULL;
printf ("we are creating  first list:\n");
    list1=create(list1);
    printf ("we are creating second list:\n");
    list2=create(list2);
    list3=merge(list1,list2,list3);
    printf ("your first list:\n");
    
    display(list1);
    printf ("\nyour second list\n");
    
    display (list2);
    printf ("\nyour  merged  list of list 1,list 2\n");
    display (list3);
    

    return 0;
}

