#include<stdio.h>
typedef struct
{
  int src,dest,weight;
}edge;
edge graph[12]={1,2,5,  1,3,3,   2,3,4,  2,4,6,  2,5,2,  3,4,5,  3,6,6,  4,5,8,  4,6,6,  5,6,3,  5,7,5,  6,7,4};
int MSTvertices[10];
void sort(edge graph[], int nE)
{
  int i,pass;
  edge temp;
  for(pass=1;pass<=nE-1;pass++)
     if(graph[i].weight>graph[i+1].weight)
     {
        temp=graph[i];
        graph[i]=graph[i+1];
        graph[i+1]=temp;
     }
}

int find(int v,int nV)
{
//reurn 1 if vertex v is in the selected vertices list
   for(int k=0;k<nV;k++)
   if(MSTvertices[k]==v)
      return 1;
      return 0;
}

 int kruskalMST(int nV,int nE)
{
   edge mst[14];
   int i=1,j=2,k=1;
   int count=1,mincost=0,first=0,second=0;
   //Arrange edges in ascending order
   sort(graph,nE);
   mst[0]=graph[0];  //add first edge  to MST
   MSTvertices[0]=graph[0].src;
   MSTvertices[1]=graph[0].dest;
   mincost=graph[0].weight;
   while(count<nV-1)
   { 
      first=find(graph[i].src,nV);
      //check if first vertex  is in selected list
      second=find(graph[i].dest,nV);
      //check if second vertex  is in selected list
      if(!(first&&second))        //if it does not form a cycle
      { 
         mst[k++]=graph[i];
         //add edge to MST
          count++;
         mincost=mincost+graph[i].weight;
         if(first)
            MSTvertices[j++]=graph[i].dest;
          else
            MSTvertices[j++]=graph[i].src;
         }
         i++;         //next edge
     }
  printf("\n The edges in the minimum spanning tree are:");
  for(i=0;i<nV-1;i++)
  printf("%d--%d ==%d\n", mst[i].src,mst[i].dest,mst[i].weight);
  printf("Minimum cost of Spanning tree :%d",mincost);
 }
 void main()
 {
   int nV=7,nE=12;
   kruskalMST(nV,nE);
   }   
         
  
