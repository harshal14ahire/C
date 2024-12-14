#include<stdio.h>
int main()
{
	int count=0;int visited[10]={0},indeg[10]={0};
	int i,j,m[10][10],n;int k,u;
	printf("how many nodes:");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{  
		for(int j=0;j<n;j++)
		{
			scanf("%d",&m[i][j]);
			indeg[i]+=m[j][i];
		}
	}
	while(count<n)
	{
		for(i=0;i<n;i++)
		{
			if(visited[i]==0&&indeg[i]==0)
			{
				printf("V%d\t",i+1);
				visited[i]=1;
				u=i;
			}
			for(k=0;k<n;k++)
			
			{
				if(m[k][u]==1)
				{
					indeg[u]--;
				}
			}
		}
		count++;
	}
	return 0;
}
