#include <bits/stdc++.h> 
int V;
int minKey(int key[], bool mstSet[]) 
{ 
	int min = INT_MAX, min_index; 
	for (int v = 0; v < V; v++) 
		if (mstSet[v] == false && key[v] < min) 
			min = key[v], min_index = v; 
	return min_index; 
}
void printMST(int parent[], int **graph) 
{ 
	printf("Edge \tWeight\n"); 
	for (int i = 1; i < V; i++) 
		printf("%d - %d %d",parent[i],i,graph[i][parent[i]]);
} 
void primMST(int **graph) 
{ 
	int parent[V],key[V]; 
	bool mstSet[V]; 
	for (int i = 0; i < V; i++) 
		key[i] = INT_MAX, mstSet[i] = false; 
	key[0] = 0; 
	parent[0] = -1; 
	for (int count = 0; count < V - 1; count++) 
	{ 
		int u = minKey(key, mstSet); 
		mstSet[u] = true; 
		for (int v = 0; v < V; v++) 
			if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) 
				parent[v] = u, key[v] = graph[u][v]; 
	}
	printMST(parent, graph); 
}
int main() 
{ 
	printf("Enter the no of nodes : ");
	scanf("%d",&V);
	int **graph=new int*[V];
	for(int i=0;i<V;i++)
		graph[i]=new int[V];
	printf("Enter the adjascency matrix : \n");
	for(int i=0;i<V;i++)
		for(int j=0;j<V;j++)
			scanf("%d",&graph[i][j]);
	primMST(graph);
	return 0; 
} 