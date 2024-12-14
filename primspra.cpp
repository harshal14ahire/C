#include<stdio.h>
//prims algorithmin
int main()
{
	int a,b,i,j,eno=1,min,mincost=0;
	int cost[10][10];
	int visited[10]={0};
	visited[0]=1;
	int n;
	printf("how many no:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{for(j=0;j<n;j++)
	{
		scanf("%d",&cost[i][j]);
	}
	}
	while(eno<n)
	{
		min=100;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(cost[i][j]==0)
				{
					cost[i][j]=100;
				}
				if(cost[i][j]<min)
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
			printf("\nEdge:%d(%d to %d):cost:%d",eno,a+1,b+1,min);
			mincost+=min;
			eno++;
			
		}
		visited[b]=1;
		cost[a][b]=cost[b][a]=100;
	}
	printf("\n min cost is:%d",mincost);
	
}
