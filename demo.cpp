#include<stdio.h>
int main()
{

	double i=20.580280;
	while(i<=20.580320)
	{
		printf("\n %1f" ,i);
			i=i+0.000001;
	}
	return 0;
}
