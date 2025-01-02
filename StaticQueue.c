/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#define MAXSIZE 5
#include <stdio.h>
// definition structure for queue arr,front,rear;
typedef struct queue
{
    int a[10];
    int front, rear;
}
QUEUE;
//create queue :front=rear=-1;
void create_que(QUEUE *pq)
{
    pq->front =pq->rear=-1;
}

// empty:front=rear
int isempty_que(QUEUE *pq)
{
   return (pq->front==pq->rear);
}
//rear: MAXSIZE-1:
int isfull_que(QUEUE *pq)
{
 return (   pq->rear==MAXSIZE-1);}

// add ele in que :using rear end
void add(QUEUE *pq,int ele)
{  pq->rear++;
    pq->a[pq->rear]=ele;
}
//remove : front
int rem(QUEUE *pq)
{

 int ele;
 pq->front++;
 ele=pq->a[pq->front];
 return (ele);
}



void rev (QUEUE q1,QUEUE q2)
{   int ele;
    while (!isempty_que (&q1))
    {
        add(&q2,rem(&q2));
    }
    while (!isempty_que (&q2))
    {    ele= rem(&q2);
        printf ("%d\t ",ele);
    }
}




int main()
{  int ele,choice;
    QUEUE  q1,q2;
    create_que(&q1);
    create_que(&q2);
    do{
    printf("\n1=push");
    printf ("\n2=pop\n 3=rev que:");
    printf ("\nenter  your choice:\n");
    scanf("%d",&choice);
    switch (choice )
    {  //add ele in que:
        case 1 : printf("\nenter ele you want push:\n");
        scanf("%d",&ele);
         add(&q1,ele);
         break;
         case 2 ://remove element:
                if(isempty_que(&q1))//not empty 
                {
                    printf ("\n queue is empty ");
                }
                else//if que full
                {  while (!isempty_que (&q1))
    
                     printf ("\n%d is  removed element", rem(&q1));
                     
                }
                 break;
                 
                 
        case 3:        rev(q1,q2)  ;
                 break;
    }
    }while (choice!=4);

    return 0;
}




