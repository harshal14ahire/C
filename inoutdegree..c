#include<stdio.h>
void main()
{
  int m[10][10],i,j,v,n,sumin,sumout;
  printf("How many vertices:");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  for(j=0;j<n;j++)
  {
    m[i][j]=0;
    if(i!=j)
    {
      printf("Is there any edge between %d->%d(1/0)",i+1,j+1);
      scanf("%d",&m[i][j]);
    }

  }
 printf("\n\n Vertex Indegree  Oudegree  TotalDegree\n");
 for(v=0;v<n;v++)
  {
    sumin=sumout=0;
    for(i=0;i<n;i++)
    {
      sumin=sumin+m[i][v];
      sumout=sumout+m[v][i];
      printf("%d\t%d\t%d\t%d\n",v+1,sumin,sumout,sumin+sumout);      

    }

  }

}
