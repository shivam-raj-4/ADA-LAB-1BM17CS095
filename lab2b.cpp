#include <stdio.h>
int main()
{
	int i,j,n,t,k;
	printf("Enter the no. of element:");
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	{
		printf("Enter the element:");
		scanf("%d",&a[i]);
	}
	printf("\nEnter the value of k :");
	scanf("%d",&k);
	for(i=0;i<=k-1;i++)
	{
		for(j=i+1;j<=n-1;j++)
		{
			if(a[i]<a[j])
			{
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
	
		}
	}
	for(i=0;i<k;i++)
	{
		printf("%d ",a[i]);
	}
	return(0);
}