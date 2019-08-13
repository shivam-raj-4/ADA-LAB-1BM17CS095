#include <stdio.h>

int main()
{
FILE *f;
f=freopen("input.txt","r",stdin);
int t;
int n,k,c;
c=0;
//no. of testcases
scanf("%d",&t);
while(t--)
{
//printf("Enter the Value of N=");
scanf("%d",&n);
//printf("Enter the value of k=");
scanf("%d",&k);
int i,a[n];
for(i=0;i<n;i++)
{
//printf("Enter the Value of array:-");
scanf("%d",&a[i]);
if(a[i]==k)
c++;
}
if(c==0)
printf("-1\n");
else
printf("1\n");
c=0;
}
return 0;
}
