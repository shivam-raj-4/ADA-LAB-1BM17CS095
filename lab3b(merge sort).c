#include <stdio.h>
void sort(int a[],int low,int mid,int high)
{
    int i=low;
    int j=mid+1;
    int k=0;
    int c[high-low+1];
    while(i<=mid&&j<=high)
    {
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
    int a[n];
    printf("Enter the Element:\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    ms(a,0,n-1);
    printf("Merge Sort: ");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    return 0;
}
