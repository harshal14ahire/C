#include<stdio.h>
int main()
{
	int n;
	printf("enter no to find factorial:");
	scanf("%d",&n);
	int f=1;
	for(int i=1;i<=n;i++)
	{
		f*=i;
	}
	printf("factorial of %d is +++= %d",n,f);
	
	printf("eneter power and exponent :xy:");
	int a,b;
	scanf("%d%d",&a,&b);
	int s;
	for(int i1=1;i1<=b;i1++)
	{
		s=a*a;
		
		
	}
	printf("power is:%d",s);
}
