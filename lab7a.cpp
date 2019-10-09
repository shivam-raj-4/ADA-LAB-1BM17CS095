#include<stdio.h>
#include<string.h>
int max(int a, int b)
{
	return ((a > b)? a : b);
}
void lcs( char *X, char *Y, int m, int n )
{
	int L[m + 1][n + 1];
	int i, j;
	for (i = 0; i <= m; i++)
	{
		for (j = 0; j <= n; j++)
		{
		if (i == 0 || j == 0)
			L[i][j] = 0;
		else if (X[i - 1] == Y[j - 1])
			L[i][j] = L[i - 1][j - 1] + 1;
		else
			L[i][j] = max(L[i - 1][j], L[i][j - 1]);
		}
	}
	int index = L[m][n];
	char s[index+1];
	s[index] ='\0';
	i=m;j=n;
	while (i>0 && j>0)
	{
		if (X[i-1]==Y[j-1])
		{
			s[index-1] = X[i-1];
			i--; j--; index--;
		}
		else if (L[i-1][j]>L[i][j-1])
			i--;
		else
			j--;
	}
	printf("\nThe longest substring is : ");
	i=0;
	while(s[i]!='\0')
		printf("%c",s[i++]);
}
int main()
{
	char X[10];
	char Y[10];
	printf("\nenter the first string:");
	scanf("%s",&X);
	printf("\nenter the second string:");
	scanf("%s",&Y);
	int m =strlen(X);
	int n =strlen(Y);
	lcs( X, Y, m, n );
	return 0;
}
