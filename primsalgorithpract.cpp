#include<stdio.h>
int main()
{
	int cost[7][7],n=7;
	int i,j,a,b,min ,mincost=0,eno=1;
	int visited[10]={0};
	visited[0]=1;
	for(i=0;i<n;i++)
	{ printf("enter %d row:\n",i+1);
	for(j=0;j<n;j++)
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
	   			cost[i][j]=100;
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
		   	printf("\nEdge:%d(%d-->%d):cost:%d",eno,a+1,b+1,min);
		   	mincost=mincost+min;
		  eno++; }
		   visited[b]=1;
		   cost[a][b]=cost[b][a]=100;
		   
		   }
		   printf("\n minimum cost of spanning tree is :=%d\n",mincost);
		   return 0;
}
