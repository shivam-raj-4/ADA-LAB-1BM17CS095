#include <bits/stdc++.h>
int ptr[501]; 
void findSmallestRange(int **arr, int n, int k) 
{ 
	int i,minval,maxval,minrange,minel,maxel,flag,minind;
	for(i = 0;i <= k;i++) 
		ptr[i] = 0; 
	minrange = INT_MAX; 
	while(1)
	{ 
		minind = -1; 
		minval = INT_MAX; 
		maxval =INT_MIN; 
		flag = 0; 
		for(i = 0;i < k;i++) 
		{
			if(ptr[i] == n) 
			{ 
				flag = 1; 
				break; 
			}
			if(ptr[i] < n && arr[i][ptr[i]] < minval) 
			{ 
				minind=i;
				minval=arr[i][ptr[i]]; 
			} 
			if(ptr[i] < n && arr[i][ptr[i]] > maxval)	 
			{ 
				maxval = arr[i][ptr[i]]; 
			} 
		} 
		if(flag) 
			break; 
		ptr[minind]++; 
		if((maxval-minval) < minrange) 
		{ 
			minel = minval; 
			maxel = maxval; 
			minrange = maxel - minel; 
		} 
	} 
		
	printf("\nThe smallest range is [%d , %d]\n",minel,maxel); 
}	 

int main() 
{
	int k,N;
	printf("\nenter the value of k: \n");
	scanf("%d",&k);
	printf("\nenter the size of arrays\n");
	scanf("%d",&N);
	int **arr=new int*[k];
	for(int i=0;i<k;i++)
		arr[i]=new int[N];
	printf("\nenter the elements\n");
	for(int i=0;i<k;i++)
		for(int j=0;j<N;j++)
			scanf("%d",&arr[i][j]);
	findSmallestRange(arr,N,k); 
	return 0; 
}