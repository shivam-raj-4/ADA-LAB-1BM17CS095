#include <stdio.h>

int main()
{
	int n,max;
	max=0;
	printf("Enter the Value of N=");
	scanf("%d",&n);
	int i,a[n];
	for(i=0;i<n;i++)
	{
		printf("Enter the Value of array:-");
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		if(a[i]>max)
			max=a[i];
	}
	printf("Maximum=%d\n",max);
	return 0;
}
