#include<stdio.h>
int m=0,s=0,bu=0;
void selectionsort(int a[],int n)
{
	int i,j,min,t;
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			s++;
			if(a[j]<a[min])
				min=j;
		}
	   	t=a[i];
    	a[i]=a[min];
	    a[min]=t;
	}
}
void bubblesort(int a[],int n)
{
	int i,j,t;
	for(i=0;i<n-1;i++)
	for(j=0;j<n-i-1;j++)
	{
		bu++;
		if(a[j]>a[j+1])
			t=a[i];
			a[i]=a[j];
			a[j]=t;
	}
}
void sort(int a[],int low,int mid,int high)
{
    int i=low;
    int j=mid+1;
    int k=0;
    int c[high-low+1];
    while(i<=mid&&j<=high)
    {
        m++;
        if(a[i]<a[j])
            c[k++]=a[i++];
        else
            c[k++]=a[j++];
    }
    if(i>mid)
        while(j<=high)
            c[k++]=a[j++];
    if(j>high)
        while(i<=mid)
            c[k++]=a[i++];
    for(i=0;i<high-low+1;i++)
        a[i+low]=c[i];
}
void ms(int a[],int low,int high)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        ms(a,low,mid);
        ms(a,mid+1,high);
        sort(a,low,mid,high);
    }
}
int main()
{
	int n,i;
	printf("Enter the size of array: ");
    scanf("%d",&n);
    int a[n],b[n],c[n];
    printf("Enter the Element:\n");
    for(i=0;i<n;i++)
	{
	    scanf("%d",&a[i]);
		b[i]=a[i];
        c[i]=a[i];
    }
	selectionsort(b,n);
	bubblesort(c,n);
	ms(a,0,n-1);
	printf("\nselectionsort: %d\nbubblesort: %d \nmergesort: %d\n",s,bu,m);
	return 0;
}
