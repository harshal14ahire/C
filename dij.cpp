#include<stdio.h>

//int cost[8][8]={{0,999,999,999,999,999,999,999},{30,0,999,999,999,999,999,999},{100,80,0,999,999,999,999,999},{999,999,120,0,999,999,999,999},{999,999,999,150,0,25,999,999},{999,999,999,100,999,0,90,140},{999,999,999,999,999,999,0,100},{170,999,999,999,999,999,999,0}};
int cost[5][5]={{0,1,2,100,100},{1,0,100,100,3},{2,100,0,5,100},{100,3,5,0,4},{2,100,100,4,0}};
void dij(int cost[5][5],int v,int n);
void dij(int cost[5][5],int v,int n)
{ int count,i,u,w,dist[10],visited[10]={0};int min;
 visited[v]=1;
 for(i=0;i<n;i++)
 {
 	dist[i]=cost[v][i];
 	
 }
 count=2;
 while(count<n)
 {
 	min =100;
 	for(i=0;i<n;i++)
 	
 		if(visited[i]==0&&dist[i]<min)
 	{
		 	min=dist[i];
 		u=i;}
		 	 
		 	 visited[u]=1;
		 	 for(w=0;w<n;w++)
		 	     if(dist[u]+cost[u][w]<dist[w])
		 	 	dist[w]=dist[u]+cost[u][w];
			  
			  count++;
			  
 }
 printf("shortest distance from vertx %d:",v+1);
 for(i=0;i<n;i++)
 {
 	printf("%4d ",dist[i]);
 }

}
int main()
{ dij(cost,0,5);
	
}
