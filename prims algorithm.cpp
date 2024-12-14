#include<stdio.h>
int main()
{
	int cost[5][5];//={{0,5,3,100,100,100,100},{5,0,4,6,2,100,100},{3,4,0,5,100,6,100},{100,6,5,0,8,6,100},{100,2,100,8,0,3,5},{100,100,6,6,3,0,4},{100,100,100,100,5,4,0}};
	
int i,j,a,b;
int min,min_cost=0,n=5,no_e=1;
int visited[10]={0};
visited[0]=1;//visite first vertex
printf("enetr cost row wise:\n");
for(i=0;i<n;i++)// traverse cost matrix
	{ printf ("enter cost row:\n"); 
	for(j=0;j<n;j++)
	{
		scanf("%d",&cost[i][j]);
		
	}
}

while(no_e<n)///spanining tree edges =nof vertex - 1

{
	min=100;//set maximum value as min
	for(i=0;i<n;i++)// traverse cost matrix
	{ for(j=0;j<n;j++)
		{    if(cost[i][j]==0)//if each vertex cost 0
			cost[i][j]=100;//set min cost to it
			if(cost[i][j]<min)//find minimum cost among all edges
			{
				if(visited[i]!=0)
				{
					min=cost[i][j];
					a=i;
					b=j;
				}
			}
		}
	}

              if(visited[b]==0)
				{
						printf("\nEdge %d: (%d to %d) cost=%d",no_e,a+1,b+1,min);
						min_cost=min_cost+min;
							no_e++;
	
					}
				visited[b]=1;
				cost[a][b]=cost[b][a]=100;

 }	
printf("\n mincost is %d \n",min_cost);
return 0;

}
