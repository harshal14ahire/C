#include<stdio.h>
typedef struct edge Edge;
void sort(Edge   graph,int nE);
//structure for edges
struct edge 
{ 
	int src,dest,weight;
	
};
typedef struct edge Edge;
Edge   graph[12]={1,2,5,  1,3,3,  2,3,4, 2,4,6, 2,5,2, 3,4,5, 3,6,6, 4,5,8, 4,6,6, 5,6,3, 5,7,5, 6,7,4};
int MST[10];//
void sort(Edge graph[],int nE)//ne =no of edges
{
	int i,pass;
	Edge temp;//passs from 1
	for(pass=1;pass<nE-1;pass++)
	{
		for(i=0;i<nE-pass;i++)
		{
			if(graph[i].weight>graph[i+1].weight)
			{
				temp=graph[i];
				graph[i]=graph[i+1];
				graph[i+1]=temp;
				
			}
		}
	}
}
int find(int v,int nV)//check that vertexsent or not
{
	for(int k=0;k<nV;k++)
	{
		if(MST[k]==v)//check pass vertex is in mst or not
		{
			return 1;//if yes return 1;
		}
		return 0;//else return 0;
		
		
	}
}
int kruskal(int nV,int nE)//
{
	Edge mst1[14];//smalll mst for =store first edge 
	int i=1,j=2,k=1;///
	int count=1,mincost=0,fi=0,se=0;//fi=first vertex an se second vertex
	sort(graph,nE);//sort edges fist weight wise
	mst1[0]=graph[0];// add first edge in mst
	MST[0]=graph[0].src;
	MST[1]=graph  [0].dest;
	mincost=graph[0].weight;
	while(count<nV-1)
	{
		fi=find(graph[i].src,nV);//find source or first vertex or 1
		se=find(graph[i].dest,nV);//find destination vertex
		if(!(fi&&se))
		{
			mst1[k++]=graph[i];
			count++;
			mincost=mincost+graph[i].weight;
			if(fi)
			{
				MST[j++]=graph[i].dest;
			}
			else
			{
				MST[j++]=graph[i].src;
			}
		}
		i++;
		
	}
	printf("no egdes in minimum spanning tree\n");
	for(i=0;i<nV-1;i++)
	{
		printf("%d<--->%d==%d\n",mst1[i].src,mst1[i].dest,mst1[i].weight);
		
		
	}	printf("min cost of spanning tree:--%d",mincost);
}
	int main()
	{
		int nV=7,nE=12;
		kruskal(nV,nE);
		
	}
	

