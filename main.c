#include <stdio.h>
#include <stdlib.h>
#include "terminal.h"
#include <time.h>
#include <unistd.h>
#include<termios.h>
#include <fcntl.h>



void displayGrid(char **grid) {
    int i, j;
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            printf("%c ", grid[i][j]);
        }
            printf("\n");
    }
}
char **createGrid(){

    int i, j;
    char **grid = (char **) malloc(9 * sizeof(char *));
    for (i = 0; i < 9; i++) {
        grid[i] = (char *) malloc(9 * sizeof(char));
        for (j = 0; j < 9; j++) {
            grid[i][j] = ' ';  // fill with space character
        }
    }
    grid[1][1] = '>';
    grid[4][4] = '@';

    // Add border to grid
    for (i = 0; i < 9; i++) {
        grid[0][i] = '-';
        grid[8][i] = '-';
    }
    for (i = 1; i < 8; i++) {
        grid[i][0] = '|';
        grid[i][8] = '|';
    }

    return grid;
}

typedef enum Bool {
    FALSE = 0,
    TRUE = 1
}bool;

void moveSnake(char move, char **grid, int *x, int *y,int *points, int *tail_x, int *tail_y, int *snake_size,bool *endgame) {
    int new_x = *x;
    int new_y = *y;
    int prev_x = *tail_x;
    int prev_y = *tail_y;
    int movecount =0;
    
    
    
    // Update the position based on the move
    if (move == 'w') {
        movecount++;
        new_x--;
    } else if (move == 's') {
        movecount++;
        new_x++;
    } else if (move == 'd') {
        movecount++;
        new_y++;
    } else if (move == 'a') {
        movecount++;
        new_y--;
    } 
    
    // Check for collision with the obstacle or out of bounds
    if (new_x < 0 || new_x > 8 || new_y < 0 || new_y > 8 || grid[new_x][new_y] == '|' || grid[new_x][new_y] == '-' ) {
        *endgame = TRUE;
        // Collision detected, do nothing
        return;
    }
    else if (grid[new_x][new_y] == '@') {
        // Collision detected with '@', randomly place a new one
        (*points)++;
        srand(time(NULL));
        int rand_x = rand() % 7 + 1;
        int rand_y = rand() % 7 + 1;
        while (grid[rand_x][rand_y] != ' ') {
            rand_x = rand() % 7 + 1;
            rand_y = rand() % 7 + 1;
        }
        grid[rand_x][rand_y] = '@';
        (*snake_size)++;
    }
    
    // Update the grid with the new position of the snake
    grid[*x][*y] = ' ';
    // if (*snake_size >1) {
        
    //     grid[*x][*y] = '-';
    //     }

    *x = new_x;
    *y = new_y;
    if (move == 'w') {
        grid[*x][*y] = '^';
    } else if (move == 's') {
        grid[*x][*y] = 'v';
    } else if (move == 'd') {
        grid[*x][*y] = '>';
    } else if (move == 'a') {
        grid[*x][*y] = '<';
    }
}




int main() {
    int i;
    int x=1;
    int y=1;
    char **grid;
    char move='d';
    int tail_x = 1;
    int tail_y = 1;
    int points =0;
    int snake_size = 1;
    grid =createGrid();
    bool endgame=FALSE;

    while(endgame !=TRUE){
        printf("Score: %d\n",points);
        disableBuffer();
        displayGrid(grid);
        while(kbhit()) { // check if there is a new input from the user
            move = getchar();
        }
        moveSnake(move,grid,&x,&y,&points,&tail_x,&tail_y,&snake_size,&endgame);
        usleep(180000);
        system("clear");

    }


    // Free memory used by grid
    for (i = 0; i < 9; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}

