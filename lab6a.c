#include<stdio.h>
int n;
int board[10][10]={0};
bool place(int row, int col)
{
    int i, j;
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;
    for (i=row, j=col; i>=0 && j>=0; i--, j--)
        if (board[i][j])
            return false;
    for (i=row, j=col; j>=0 && i<n; i++, j--)
        if (board[i][j])
            return false;
    return true;
}
bool nQueens(int col)
{
    if (col == n)
    {
        printf("\n");
    	for (int i = 0; i < n; i++)
   		{
       		for (int j = 0; j < n; j++)
            	printf("%d ",board[i][j]);
			printf("\n");
   		 }
        return true;
    }
    bool res = false;
    for (int i = 0; i < n; i++)
        if(place(i, col))
        {
            board[i][col] = 1;
            res = nQueens(col+1)||res;
            board[i][col] = 0;
        }
    return res;
}
int main()
{
	printf("Enter the no of Queens : ");
	scanf("%d",&n);

	if(!nQueens(0))
        printf("Solution does not exist");
    return 0;
}
