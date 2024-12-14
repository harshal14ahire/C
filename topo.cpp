#include<stdio.h>
int main()
{
	int indeg[10]={0},visited[10]={0};
	int n;int i,j,k;
	int a[10][10];//int n;
	printf("how many vertices:");
	scanf("%d",&n);
	for( i=0;i<n;i++)
	{  printf("enetr row:\n");
		for( j=0;j<n;j++)
		{scanf("%d",&a[i][j]);
			
		}
	}
	for(i=0;i<n;i++)
	{  indeg[i]=0;
		for(j=0;j<n;j++)
		{
			indeg[i]+=a[j][i];
		}
	}
	int count=0;
	while(count<n)
	{
		for( i=0;i<n;i++)
		{
			if(visited[i]==0&&indeg[i]==0)
			{
				printf("V%d",i+1);
				visited[i]=1;
			}
			for(k=0;k<n;k++)
			{
				if(a[k][i]==1)
				{
					indeg[i]--;
				}
			}
		}
		count++;
	}
	return 0;
}
