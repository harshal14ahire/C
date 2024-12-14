#include<stdio.h>
int main()
{
	int i,j,k,n;
	int a[10][10];//declare adj mat
	int indeg[10]={0};//in deg 0 privi0usly
	int flag[10]={0},count=0;//set count 0

	printf("Enter the no of vertices:\n");
	scanf("%d",&n);

	printf("Enter the adjacency matrix:\n");
	for(i=0;i<n;i++)
	{
		printf("Enter row %d\n",i+1);
		for(j=0;j<n;j++)
		{
		
			scanf("%d",&a[i][j]);
     	}
   }

/*	for(i=0;i<n;i++){
        indeg[i]=0;
        flag[i]=0;
    }*/

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            indeg[i]=indeg[i]+a[j][i];

    printf("\nThe topological order is:");

    while(count<n)
	{
        for(k=0;k<n;k++)
		{
            if((indeg[k]==0) && (flag[k]==0))
			{
                printf("V%d , ",(k+1));
                flag [k]=1;
            }

            for(i=0;i<n;i++)
			{
                if(a[i][k]==1)
                    indeg[k]--;
            }
        }

    count++;
    }

    return 0;
}
