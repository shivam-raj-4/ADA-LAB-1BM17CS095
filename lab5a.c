#include <stdio.h> 
#define UNASSIGNED 0 
#define N 4

bool FindUnassignedLocation(int grid[N][N], int &row, int &col); 
bool isSafe(int grid[N][N], int row, int col, int num); 
  
bool SolveSudoku(int grid[N][N]) 
{ 
    int row, col; 
    if (!FindUnassignedLocation(grid, row, col)) 
       return true; // success! 

    for (int num = 1; num <= 9; num++) 
    { 
       if (isSafe(grid, row, col, num)) 
        { 
          grid[row][col] = num; 
          if (SolveSudoku(grid)) 
            return true; 
          grid[row][col] = UNASSIGNED; 
        } 
    } 
    return false; // this triggers backtracking 
} 
bool FindUnassignedLocation(int grid[N][N], int &row, int &col) 
{ 
    for (row = 0; row < N; row++) 
        for (col = 0; col < N; col++) 
            if (grid[row][col] == UNASSIGNED) 
                return true; 
    return false; 
} 
bool UsedInRow(int grid[N][N], int row, int num) 
{ 
    for (int col = 0; col < N; col++) 
        if (grid[row][col] == num) 
            return true; 
    return false; 
} 
bool UsedInCol(int grid[N][N], int col, int num) 
{ 
    for (int row = 0; row < N; row++) 
        if (grid[row][col] == num) 
            return true; 
    return false; 
} 
bool UsedInBox(int grid[N][N], int boxStartRow, int boxStartCol, int num) 
{ 
    for (int row = 0; row < 2; row++) 
        for (int col = 0; col < 2; col++) 
            if (grid[row+boxStartRow][col+boxStartCol] == num) 
                return true; 
    return false; 
} 
bool isSafe(int grid[N][N], int row, int col, int num) 
{ 
  return !UsedInRow(grid, row, num) && 
           !UsedInCol(grid, col, num) && 
           !UsedInBox(grid, row - row%2, col - col%2, num)&& 
            grid[row][col]==UNASSIGNED; 
} 
void printGrid(int grid[N][N]) 
{ 
    for (int row = 0; row < N; row++) 
    { 
       for (int col = 0; col < N; col++) 
             printf("%d", grid[row][col]); 
        printf("\n"); 
    } 
} 
int main() 
{ 
  
  int grid[N][N]={0};
  printf("Enter the element for sudoku:\n");
   for (int row = 0; row < N; row++) 
       for (int col = 0; col < N; col++) 
             scanf("%d",&grid[row][col]);  
    if (SolveSudoku(grid) == true) 
          printGrid(grid); 
    else
         printf("No solution exists"); 
  
    return 0; 
}