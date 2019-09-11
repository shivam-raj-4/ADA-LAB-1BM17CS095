#include<stdio.h>
int a[10][10],n;
void bfs(int src)
{
  int q[10],f=0,r=-1;
  int vis[10],i,j;
  //visit first and print and enqueue
  for(j=0;j<n;j++)
    vis[j] = 0;
  vis[src]=1;
  q[++r]=src;
  printf("%d ",src+1);
  while(!(r<f)) //while not empty
  {
    i=q[f++];
    for(j=0;j<n;j++)
    {
      if(a[i][j]&&!vis[j])
      {
        vis[j]=1;
        q[++r]=j;
        printf("%d ",j+1);
      }
    }
  }
}
int main()
{
  int i,j,src;
  printf("Enter the no. of nodes: ");
  scanf("%d",&n);
  printf("Enter the adjacency matrix: \n");
  for(i=0;i<n;i++)
    for(j=0;j<n;j++)
      scanf("%d",&a[i][j]);

  printf("\n Enter the source node: ");
  scanf("%d",&src);
  bfs(src-1);
  return 0;
}