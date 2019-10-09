#include<stdio.h>

int i,j,n,m,p[10],w[10],v[10][10];
int max(int x,int y)
{
	if(x>y)
		return x;
	else
		return y;
}
void knapsack()
{
	int x[10];
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=m;j++)
		{
			if(i==0||j==0)
				v[i][j]=0;
			else if(j-w[i]<0)
				v[i][j]=v[i-1][j];
			else
				v[i][j]=max(v[i-1][j],v[i-1][j-w[i]]+p[i]);
		}
	}
	printf("\n Output is:\n");
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=m;j++)
		{
			printf("%d\t",v[i][j]);
		}
		printf("\n\n");
	}
	printf("the optimal solution is:%d ",v[n][m]);
}
int main()
{
	printf("\nEnter the no. of items:\t");
	scanf("%d",&n);
	printf("\nEnter the weight of the each item:\n");
	for(i=1;i<=n;i++)
		scanf("%d",&w[i]);
	printf("\nEnter the profit of each item:\n");
	for(i=1;i<=n;i++)
		scanf("%d",&p[i]);
	printf("\nEnter the knapsack's capacity:\t");
	scanf("%d",&m);
	knapsack();
	return 0;
}