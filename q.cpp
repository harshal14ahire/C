#include<stdio.h>
int main()
{
	int A[100];
	int i;
	int n;
	printf("\n entar how many number want to store=");
	scanf("%d",&n);
	for(i=0;i<=n;i++);
	{
	printf("\n enter no %d=",i);
	scanf("%d",&A[i]);
    }
    printf("\n number are follows=");
    for(i=0;i<=n;i++);
    {
    	printf("\n%d",A[i]);
	}
	return 0;
}


