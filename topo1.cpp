#include<stdio.h>
int main()
{
	int i,j,count=0 ;int m[10][10];int n;int k;
	int flag[10]={0},indeg[10]={0};
	printf("hpow many vertices:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{  printf("eneter row:");
		for(j=0;j<n;j++)
		{
			scanf("%d",&m[i][j]);
		}
	}
	//
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			indeg[i]+=m[j][i];
		}
	}
	printf("topological order is:\n");
	while(count<n)
	{
		for(i=0;i<n;i++)
		{
			if(indeg[i]==0&&flag[i]==0)
			{
				printf("V%d\t",i+1);
				flag[i]=1;
				
			}
			for(k=0;k<n;k++)
			{
				if(m[k][i]==1)
				{
					indeg[i]--;
				}
			}
		}
		count++;
	}
}
