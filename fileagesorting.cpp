#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef	struct employee
	{
		
		char name[50];
		int age;
	}Emp;
	
	
Emp E[50];
	void sort_on_eage( Emp E[50] ,int n);
	int main()
{
	int i;
	 FILE *fp;
	  fp=fopen("Employee.txt","r");
	  if(fp==NULL)
	  {
	  	printf("error opening file");
	  }
	  for(i=0;i<3;i++)
	  { 
	  	fscanf( fp ,"%s %d",E[i].name,&E[i].age);
	  	
	  }
	  sort_on_eage(E,3);
	  
	   for(i=0;i<3;i++)
	  {
	  	printf( "%s %d \n",E[i].name,E[i].age);
	  	
	  	
	  }
	 // fclose(fp);
	  return 0;
}
	  
	  void sort_on_eage(Emp E[50] ,int n)
	  {
	  	int i,j;
	  	Emp temp;
	  	
	  
	  
    for(i=1;i<n;i++)
    {
    	for(j=0;j<n-i;j++)
    	{
    		if(E[j].age>E[j+1].age)
    		{
    			temp=E[j];
    			E[j]=E[j+1];
    			E[j+1]=temp;
    			
			}
		}
	}
	
}
