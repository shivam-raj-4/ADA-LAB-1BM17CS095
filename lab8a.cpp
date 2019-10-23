#include<stdio.h>
using namespace std;
int a[10];
int n;
int max(int a,int b)
{
	return ((a>b)?a:b);
}
bool check()
{
	for(int i=0;i<n/2;i++)
	{
		if(!(a[i]>=max(a[2*i+1],a[((2*i+2)>n)?(2*i+1):(2*i+2)])))
			return false;
	}
	return true;
}
int main()
{
	printf("Enter the number of elements :  ");
	scanf("%d",&n);
	printf("\nEnter the elements of the array :\n");
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	if(check())
		printf("\nTrue\n");
	else
		printf("\nFalse\n");
	return 0;
}
