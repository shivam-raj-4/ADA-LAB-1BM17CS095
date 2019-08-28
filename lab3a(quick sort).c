#include <stdio.h>
int p,low,high,pp,i,j,t,a[10];
int sort (int a[],int low,int high)
{
    p=a[low];
    i=low+1;
    j=high;
    while(1)
    {
        while(a[i]<=p&&i<=high)
            i++;
        while(a[j]>p&&j>=low)
            j--;
        if(i<j)
        {
            t=a[j];
            a[j]=a[i];
            a[i]=t;
        }
        else
        {
            a[low]=a[j];
            a[j]=p;
            return j;
        }
    }
}
void qs(int a,int low,int high)
{
    if(low<high)
    {
        pp=sort(a,low,high);
        qs(a,low,pp-1);
        qs(a,pp+1,high);
    }
}
int main()
{
    printf("Enter the Element:\n");
    for(i=0;i<5;i++)
        scanf("%d",&a[i]);
    qs(a,0,4);
    printf("Quick Sort: ");
    for(i=0;i<5;i++)
        printf("%d ",a[i]);
    return 0;
}
