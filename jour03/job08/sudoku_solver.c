#include <stdio.h>
#include <stdlib.h>
 
void print(int grid[9][9]){
    int i,j;
    for(i=0; i<9; ++i){
        for(j=0; j<9; ++j)
            printf("%d ",grid[i][j]);
        printf("\n");
    }
    printf("\n");
}



int is_safe(int grid[9][9], int row, int col, int num){
    int i,j;
    for(i=0; i<9; ++i)
        if(grid[row][i] == num)
            return 0;
    for(i=0; i<9; ++i)
        if(grid[i][col] == num)
            return 0;
    int start_row = row - row%3, start_col = col - col%3;
    for(i=0; i<3; ++i)
        for(j=0; j<3; ++j)
            if(grid[i+start_row][j+start_col] == num)
                return 0;
    return 1;
}

int check_starting_grid(int grid[9][9]){
    int i,j;
    for(i=0; i<9; ++i){
        for(j=0; j<9; ++j){
            if(grid[i][j] != 0){
                int num = grid[i][j];
                grid[i][j] = 0;
                if(!is_safe(grid, i, j, num)){
                    grid[i][j] = num;
                    return 0;
                }
                grid[i][j] = num;
            }
        }
    }
    return 1;
}

int sudoku_solver(int grid[9][9]){
    if(!check_starting_grid(grid))
        return 0;
    int row,col;
    for(row=0; row<9; ++row){
        for(col=0; col<9; ++col){
            if(grid[row][col] == 0){
                int num;
                for(num=1; num<=9; ++num){
                    if(is_safe(grid, row, col, num)){
                        grid[row][col] = num;
                        if(sudoku_solver(grid))
                            return 1;
                        grid[row][col] = 0;
                    }
                }
                return 0;
            }
        }
    }
    return 1;
}


int main(){
    int grid[9][9] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 0, 8, 0, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 7, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 3, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 0, 0}, 
        {5, 0, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 6, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 0, 7, 0, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 0, 9}
    };
    if (sudoku_solver(grid))
        print(grid);
    else
        printf("No solution exists");
    int grid2[9][9] = { {0, 0, 0, 0, 0, 0, 0, 0, 0}, 
        {5, 0, 8, 0, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 7, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 3, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 0, 0}, 
        {5, 0, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 6, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 0, 7, 0, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 0, 9} };
    if (sudoku_solver(grid2))
        print(grid2);
    else
        printf("No solution exists");
    return 0;
}