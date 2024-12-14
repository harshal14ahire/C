#include<stdio.h>
#define MAXSIZE 20
typedef struct queue
{
	int data[MAXSIZE];
	int front,rear;
}QUEUE;
void init(QUEUE *pq)
{
	pq->front=pq->rear=-1;
}
void add(QUEUE *pq,int ele)
{
	//pq->rear++;
	//pq->data[pq->rear]=ele;
		pq->data[++pq->rear]=ele;

}
int remove(QUEUE *pq)
{
	pq->front++;
	int ele;
	ele=pq->data[pq->rear];
	return ele;
}
int isempty(QUEUE *pq)
{
	return(pq->front==pq->rear);
	
}
void bsf(int m[5][5],int n)
{
	int v=0;
	
	int visited[20]={0};
	visited[v]=1;
	//printf("V%d",v+1);
	QUEUE q;
	init(&q);
	add(&q,v);
	while(!isempty(&q))
	{
		v=remove(&q);
			printf("V%d",v+1);

		for(int i=0;i<n;i++)
		{
			if(visited[i]==0&&m[v][i]==1)
			{ 				visited[i]=1;

			add(&q,i);
			}
		}
	}
}





int main()
{
	int m[5][5]={{0,0,1,1,0},{0,0,1,0,1},{0,1,0,0,0},{0,0,0,0,1},{0,0,0,0,0}};
	bsf(m,5);
}
