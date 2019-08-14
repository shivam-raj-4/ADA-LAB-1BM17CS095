#include <stdio.h>
int b_sqrt(int n)
{
	int end=n;
	int beg=0;
	int sqrt=0;
	int mid=0;
	while(beg<=end)
	{
		mid=(beg+end)/2;
		if(mid*mid==n)
		{
			return mid;
		}
		else if(mid*mid<n)
		{
			beg=mid+1;
			sqrt =mid;
		}
		else{
			end =mid-1;
		}
	}
	return sqrt;
}
int main()
{
	int n=0;
	printf("Enter the number : ");
	scanf("%d",&n);
	printf("Square root of the given number is  :%d ",b_sqrt(n));
	return(0);
}