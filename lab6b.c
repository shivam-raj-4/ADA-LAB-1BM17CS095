#include<stdio.h>

const int n=4;
int indegree[n];
int a[n][n]={0};
void topo_order()
{
	for(int i=0;i<n;i++)
	{
		indegree[i]=0;
		for(int j=0;j<n;j++)
			indegree[i] += a[j][i];
	}
	for(int j=0;j<n;j++)
		if(indegree[j]==0)
		{
			indegree[j]=-1;
			printf("%d",j+1);
			for(int k=0;k<n;k++)
			{
				if(a[j][k]==1)
				indegree[k]=indegree[k]-1;
			}
		}
}
int main()
{
	printf("\nEnter the adjacency matrix : \n");
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	topo_order();
	return 0;
}
