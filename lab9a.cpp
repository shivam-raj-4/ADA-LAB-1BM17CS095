#include <bits/stdc++.h>  
int minCoins(int coins[], int m, int V) 
{ 
	int table[V+1]; 
	table[0] = 0; 	
	for (int i=1; i<=V; i++) 
		table[i] =INT_MAX; 
	for (int i=1; i<=V; i++) 
		for (int j=0; j<m; j++) 
			if (coins[j]<=i) 
			{ 
				int sub_res = table[i-coins[j]]; 
				if (sub_res!=INT_MAX && sub_res+1<table[i]) 
					table[i] = sub_res + 1; 
			} 
	return table[V]; 
} 
int main() 
{ 
	int m,V;
	printf("Enter the no of coins : ");
	scanf("%d",&m);
	int coins[m];
	printf("Enter the denominations : \n");
	for(int i=0;i<m;i++)
		scanf("%d",&coins[i]);
	printf("Enter the value : ");
	scanf("%d",&V);
	printf("Minimum coins required is %d ",minCoins(coins, m, V)); 
	return 0; 
} 