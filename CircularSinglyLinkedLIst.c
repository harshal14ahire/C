#include <stdio.h>
# include <stdlib.h>
typedef struct node
{
    int info;
    struct node *next;
    
}NODE;
NODE *create(NODE *);
void display (NODE * list);
NODE * insert(NODE  *,int,int);
NODE * create (NODE *list)
{
    int n,i;NODE *header,*temp ,*newnode;
    printf("how many nodes in your list:\n");
    scanf("%d",&n);
    
    
    
    header=(NODE *)malloc(sizeof(NODE ));
    
   
    header->info=-1;
    header->next=NULL;
    for(i=1;i<=n;i++)
    {
        
    newnode =(NODE *)malloc (sizeof(NODE ));
    printf("\nenter info:\n");
    scanf("%d",&newnode->info);
    if(list->next==list)
    {
    header->next=newnode;
    newnode->next=header;
        list=header;
        temp=newnode;
    }
    else
    {
        temp->next= newnode;
        newnode->next=list;
        temp=newnode;
    }
    }
    return(list);
}


void display (NODE *list)
{
    NODE * temp;
    for(temp=list->next;temp!=list;temp=temp->next)
    {
        printf("[%d]--->",temp->info);
        
    }
}

int search(NODE * list,int ele)
{
    int pos;NODE *temp;
    for(temp=list->next,pos=1;temp!=list;temp=temp->next,pos++)
    {
        if(temp->info==ele)
        {
            return (pos);
            
            
            
        }
       else 
       return 0;
    
    }
    
}
NODE * insert (NODE *list ,int ele,int pos)
{
    NODE *newnode, *t1,*t2;int i  ,n;
    newnode =(NODE *)malloc (sizeof (NODE ));
    newnode->info=ele;
    newnode->next=NULL;

    if(pos==1)
    {
        t1=list->next;
        list->next=newnode;
        newnode->next=t1;
        
    }
    else
    {
        for(t1=list->next,i=1;t1!=NULL&&i<pos-1;i++)
        
        t1=t1->next;
        t2=t1->next;
        t1->next=newnode;
        newnode->next=t2;
    }
    return(list);
}
NODE *del(NODE *list,int ele,int pos)
{
    NODE  *t1,*t2,*t3;int i;
    if(pos==1)
    {
        t1=list;
        list=t1->next;
        t1->next=NULL;
        free(t1);
        
    }
    else
    {
        for(t1=list->next,i=1;t1!=list &&i<pos-1;i++)
        
            t1=t1->next;
            t2=t1->next;
            t3=t2->next;
            t1->next=t3;
            
            free(t2);
            
        
    }
    return (list);
}
  
int main()

{  NODE * list;
list->next=list;
int ele,pos,choice, ele1,pos1;
    do{
        printf("\n1=create link list\n");
        printf("2=display link list\n");
        printf("3= insert ele into list\n");
        printf("4=delete ele in link list\n");
        printf("5=search ele in list\n");
        printf("6=exit ");
        printf("enter your choice:\n");
        scanf("%d",&choice);
        switch (choice )
        {
            
  case 1 :    list=create(list);
              display(list);
              break;
    
    
case 2 : display(list);
           break;

    case 3 :
    printf("\nenter elements you want to insert in list\n");
    scanf("%d",&ele1);
    printf("\nenter position where  you want insert element\n");
    scanf("%d",&pos1);
    list= insert(list,ele1,pos1);
    
    display(list);
    break;
    case 4 : 
    printf("\nenter  element you want to delete :\n");
    scanf("\n%d",&ele);
    printf("enter position of node you want delete:\n");
    scanf("%d",&pos);
    
    
    
    list=del(list,ele,pos);
    
    break;
    case 5: 
    
    printf("enter  ele to search :\n");
    scanf("%d",&ele);
    search(list,ele);
    if(pos!=0)
    {
        printf("%d is found at position %d",ele,pos);
        
    }
    
    else
    {
        printf("%d is not found",ele);
        
    }
    
    
        }
    }while(choice!=6);
    
    return (0);
}
