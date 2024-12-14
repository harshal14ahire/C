#include<stdio.h>
void heapsort(int a[5],int n);
void buildheap(int a[5], int n);
void display(int a,int n);
void heapify(int a[5],int top,int last);
void display(int a[5],int n)
{  int i; 
	for(i=0;i<n;i++)
	
		printf("%d\t ",a[i]);
}
void heapify(int a[],int top,int last)
{
	int temp,j;
	int key=a[top];
	j=2*top+1;
	if((j<last)&&(a[j]<a[j+1]))
	{
		j=j+1;
	}
	if(j<=last&&key<a[j])
	{
		temp=a[top];
		a[top]=a[j];
		a[j]=temp;
		heapify(a,j,last);
	}
}
void buildheap(int a[], int n)
{
for(int i=(n/2)-1;i>=0;i--)
{
	heapify(a,i,n-1);
	
}
}
void heapsort(int a[5], int n)
{
	int last,top=0,temp;
	buildheap(a,n);
	printf("e=initial heap is:");
	display(a,n);
	for(last=n-1;last>=1;last--)
	{
		temp=a[top];
		a[top]=a[last];
		a[last]=temp;
		printf("\n\nAfter iteration %d : ", n-last);

		display(a,n);
		heapify(a, top ,last-1);
		
		
	}
}
int main()
{
	int a[5]={33,12,3,89,6};
	heapsort(a,5);
}
