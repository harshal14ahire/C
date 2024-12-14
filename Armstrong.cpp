#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int main()
{   int n;
	printf("Enter String ");
	scanf("%d",&n);
	if(n<10)
	{
		printf("Number is Armstrong...");
		exit(0);
	}
	
	int n1=n;
	int cnt=0;
	
	while(n1!=0)
	{
		cnt++;
		n1/=10;
	}
	n1=n;
	
    int sum=0;
    while(n1!=0)
    {
    	sum+=pow(n1%10,cnt);
    	n1/=10;
    	
	}
	if(sum==n)
	printf("Number is Armstrong...");
	else
	printf("Number is Not Armstrong");
	return 0;
}
 	
 	
  
