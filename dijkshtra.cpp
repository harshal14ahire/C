#include<stdio.h>
void dijkstra(int [8][8],int n,int v);
int main()
{
int cost[8][8];
printf("enter cost matrix:\n");int i,j;
     for(i=0;i<8;i++)
	 for(j=0;j<8;j++)
	 {
	 scanf("%d",&cost[i][j]);//accept adj matrix
	 }
	dijkstra(cost,4,8);//
	return 0;
    }                              //={{0,100,100,100,100,100,100,100},{30,0,100,100,100,100,100,100},{99,80,0,100,100,100,100,100},{100,2,2,0,2},{100,100,6,2,0}};
void dijkstra(int cost[8][8],int v,int n)//v=source vertex n=noff vertices
{
	int i,j,u,w,count ,min;//min,count
	 int dist[10],visited[20]={0};//dist and visited array;
	 visited[v]=1;//visied first vertex;
	 for(i=0;i<n;i++)//distance[i]=distance from i--->nth vertex
	 {
	 	dist[i]=cost[v][i];//store
	 }
	 count=2;//count 2
	 while (count<n)//connt<n
	 {
	 	min=999;//set min value initially
	 	for(i=0;i<n;i++)//traverse n vertices
	 	if(visited[i]==0&&dist[i]<min)//if ith vertex not visited and 
	 	{
	 		min=dist[i];
	 		u=i;}
	 		visited[u]=1;//mark ith vertex
	 		for(w=0;w<n;w++)//traverse n vertices
	 		if(dist[u]+cost[u][w]<dist[w])//if uth vertex na distance 
	 		dist[w]=dist[u]+cost[u][w];
	 		count++;
	 		
		 }
		 printf("shortest dist is %d are:\n",v);
		 for(i=0;i<n;i++)
		 {
		 	printf("%d\t",dist[i]);
		 	
		 }
		
	 }
/*int main()
{dijkstra(4,8);
	
}*/
