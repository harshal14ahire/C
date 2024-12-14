
#include<stdio.h>
#include<string.h>

int main(){
	  enum color{red ,green,blue,yellow,pink,white
	  };
	  enum range{six=9,sev,eight,nine,ten};
	  int a;
	  enum range r= (ten);
	 
	  printf("\n las value of enum range() is:%d",r+2);
	enum color mycolr=white;
	printf("\n%d",mycolr);
	

    printf("\nSize of int: %zu bytes\n", sizeof(a));
	printf("\nSize require for enum var mycolr:%zu",sizeof(mycolr));
	
	
return 0;
}
 
