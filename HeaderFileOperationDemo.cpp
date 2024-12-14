#include<TwoNumMathOperation.h>
#include<stdio.h>
 int main()
 {
 	 int a,b;
 	 printf("Enter value Of A|B:");
 	 scanf("%d%d",&a,&b);
 	 printf("\nAddition:%d",sum(a,b));
 	 printf("\nSubstraction:%d",sub(a,b));
 	 printf("\nMultiplication:%d",mul(a,b));
 	 printf("\n Division is :%f",div(a,b));
 	 printf("\n Absolute value:%d  | %d",pos(a),pos(b));
 	 
 	 return 0;
 }
