#include<stdio.h>
void display(int a[],int n);
void buildheap(int a[],int n);
void heapsort(int a[],int n);
void display(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
		
	}
}
void heapify (int a[], int top, int last)
{
	///convert tree having root nodekey
	int key =a[top];
	int j=2*top+1;//j point to left child
	if((j<last)&&(a[j]<a[j+1]))//compare left and right childrens
	j=j+1;
	if((j<last)&&(key<a[j]))
	{
	temp=a[top];
	a[top]=a[j];
	a[j]=temp;
	heapify(a,j,last);
}
}
void buildheap(int a[],int n)
{
	int i;
	for(i=(n/2)-1;i>=0;i--)
	heapify(a,i,n-1);
	
}
void heapsort(int a[],int n)
{
	int i,temp,top=0,last;
	buildheap(a,n);
	printf("initial heap is :");
	display(a,n);
	for(last=n-1;last>=1;last--)
	{
		temp=a[top];
		a[top]=a[last];
		a[last]=temp;
		printf("\n afther iteration %d:",n-last);
		display(a,n;
		heapify(a,top,last-1);
		
	}
}
int main()
{
	int a[8]={26,5,77,1,61,11,59,15};
	heapsort(a,n);
	printf("sortead element:are\n";
	display(a,n);
	
}
