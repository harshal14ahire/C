#include<stdio.h>
/*typedef struct node
{
  int vertex;
  struct node *next;
} NODE;
NODE *list[10];
 */
void creatematrix(int m[10][10],int n)
{
  int i,j;
  
  for(i=0;i<n;i++)
  for(j=0;j<n;j++)
  {
    m[i][j]=0;
    if(i!=j)
    {
     printf("\n Is there an edge between %d and %d(1/0)",i+1,j+1);
     scanf("%d",&m[i][j]);
    }
 } 
}
void displaymatrix(int m[10][10],int n)
{
  int i,j;
  printf("\n The adjacency matrix is:\n");
  for(i=0;i<n;i++)
   {
     for(j=0;j<n;j++)
     printf("%5d",m[i][j]);
     printf("\n");
   } 
}


void main()
{
  int m[10][10],n;
  printf("\n How many vertices:");
  scanf("%d",&n);
  creatematrix(m,n);
  displaymatrix(m,n);

}

