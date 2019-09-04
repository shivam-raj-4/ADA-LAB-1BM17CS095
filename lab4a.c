#include<stdio.h>
#define n 5
int visited[n]={0};
int adjacent[n][n];
void dfs(int v)
{
	printf("->%d",v+1);
	visited[v]=1;
	for(int i=0;i<n;i++)
	{
		if((adjacent[v][i]==1)&&(visited[i]==0))
			dfs(i);
	}
}
int main()
{
	printf("Enter the adjacency matrix : %d\n",n);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&adjacent[i][j]);

	for(int i=0;i<n;i++)
	{
		if(visited[i]==0)
		{
			dfs(i);
			printf("\n");
		}
	}
	return 0;
}