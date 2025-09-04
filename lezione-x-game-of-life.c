#include <stdio.h>

#define GRID_COLS 25
#define GRID_ROWS 25
#define ALIVE '*'
#define DEAD '.'

/* Translate a specified X,Y grid point into the correct index.
this will tanslate both overflow and negative coordinates in the range of valid indexes
wrapping around the screen.*/
int cell_to_index(int x, int y) {
    int inRange = 0;
    
iterate:
    if (x < 0)
        x = GRID_COLS - x;
    else if (x >= GRID_COLS)
        x = x - GRID_COLS;
    
    if (y < 0)
        y = GRID_ROWS - y;
    else if (y >= GRID_ROWS)
        y = y - GRID_ROWS;
    
    if (x >= 0 && x < GRID_COLS && y >=0 && y < GRID_ROWS)
        inRange = 1;
        
    if (!inRange)
        goto iterate;
    
    return y*GRID_COLS+x;
}

void setCell(char *grid, int x, int y, char state) {
    grid[cell_to_index(x,y)] = state;
}

char getCell(char *grid, int x, int y) {
    return grid[cell_to_index(x,y)];
}

int count_living_neighbors(char *grid, int x, int y) {
    
}

void clear_grid(char *grid) {
    for (int y=0; y < GRID_ROWS; y++)
        for (int x=0; x < GRID_COLS; x++)
            setCell(grid, x, y, DEAD);
}

void print_grid(char *grid) {
    printf("\x1b[3J\x1b[H\x1b[2J");
    for (int y=0; y < GRID_ROWS; y++){
        for (int x=0; x < GRID_COLS; x++)
            printf("%c ", getCell(grid, x, y));
        printf("\n");
    }
}

int main(void) {

    char old_grid[GRID_COLS*GRID_ROWS];
    char new_grid[GRID_COLS*GRID_ROWS];

    clear_grid(old_grid);
    print_grid(old_grid);
    setCell(old_grid, 10, 4, ALIVE);
    print_grid(old_grid);
}


