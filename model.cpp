#include<stdio.h>
typedef struct node
{
	int day;
	int month;
	int year;
	
}DATE;
int main()
{	
	char Class[20];
	int n;
	char subname[10][10];
	int hrs;
	DATE a;
	printf("enter your class in you studing: ");
	scanf("%s",Class);
	printf("your class is:\n");
		printf("\n %s",Class);
    printf("\n how many subject in your co-cirriculam:= ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
    	printf("enter %d subject:",i+1);
    	scanf("%s",subname[i]);
	}
	printf("enter your self study hrs: ");
	scanf("%d",&hrs);
	DATE b;
	printf("enter todays date:");
	scanf("%d%d%d",&b.day,&b.month,&b.year);// 18 5
	printf("enter approximate date of exam :");// 6 6
	scanf("%d%d%d",&a.day,&a.month,&a.year);
   int countday;
  int diffmon=(a.month-b.month);
  int diffday=a.day-b.day;
    //printf("\n diff bet mon=%d",diffmon);
   // printf("\n diff bet day=%d",diffday);

  if (diffmon<0)
  {
  	diffmon =diffmon*(-1);
  }
  //printf("\n diff bet mon=%d",diffmon);
  
  if(diffday<0)
  {
  diffday=	diffday*(-1);
  }
    //printf("\n diff bet day=%d",diffday);
if(diffmon<2) {
  countday=(30*diffmon)-diffday;
  printf("\n |%d|  days are remaining for your exam :",countday);  
}
else
{countday=(30*diffmon)+diffday;
  //printf("\n no of days bet to dates :%d",countday);
    printf("\n |%d|  days are remaining for your exam :",countday);  
  
}

float nohrs=(countday*hrs)/countday;
  float m=nohrs/n;
printf("\nyou have  are: %f hours  per day for each subject for study: ",m);

}

