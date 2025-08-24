#include "life.h"

// Create an empty board
char **create_board(int width, int height) {
    char **board = calloc(height, sizeof(char *));
    if (!board) return NULL;
    
    for (int i = 0; i < height; i++) {
        board[i] = calloc(width + 1, sizeof(char));
        if (!board[i]) {
            free_board(board, i);
            return NULL;
        }
        for (int j = 0; j < width; j++) {
            board[i][j] = DEAD_CELL;
        }
        board[i][width] = '\0';
    }
    return board;
}

// Free board memory
void free_board(char **board, int height) {
    if (!board) return;
    for (int i = 0; i < height; i++) {
        free(board[i]);
    }
    free(board);
}

// Print the board
void print_board(char **board, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            putchar(board[i][j]);
        }
        putchar('\n');
    }
}

// Initialize board with living cells from stdin
char **initialize_board(int width, int height) {
    char **board = create_board(width, height);
    if (!board) return NULL;
    
    char buf;
    int x = 0, y = 0;
    bool drawing = false;
    
    while (read(0, &buf, 1) > 0) {
        switch (buf) {
            case 'x':
                drawing = !drawing;
                break;
            case 'w':
                if (y > 0) y--;
                break;
            case 'a':
                if (x > 0) x--;
                break;
            case 's':
                if (y < height - 1) y++;
                break;
            case 'd':
                if (x < width - 1) x++;
                break;
        }
        
        if (drawing) {
            board[y][x] = LIVE_CELL;
        }
    }
    
    return board;
}

// Count live neighbors for a cell
int count_neighbors(char **board, int x, int y, int width, int height) {
    int count = 0;
    
    for (int dy = -1; dy <= 1; dy++) {
        for (int dx = -1; dx <= 1; dx++) {
            if (dx == 0 && dy == 0) continue;
            
            int nx = x + dx;
            int ny = y + dy;
            
            if (nx >= 0 && nx < width && ny >= 0 && ny < height) {
                if (board[ny][nx] == LIVE_CELL) {
                    count++;
                }
            }
        }
    }
    
    return count;
}

// Determine if a cell should live based on Conway's rules
bool should_live(bool is_alive, int neighbors) {
    if (is_alive) {
        return neighbors == 2 || neighbors == 3;
    } else {
        return neighbors == 3;
    }
}

// Update board for one generation
char **update_board(char **board, int width, int height) {
    char **new_board = create_board(width, height);
    if (!new_board) return NULL;
    
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int neighbors = count_neighbors(board, x, y, width, height);
            bool is_alive = (board[y][x] == LIVE_CELL);
            
            if (should_live(is_alive, neighbors)) {
                new_board[y][x] = LIVE_CELL;
            }
        }
    }
    
    free_board(board, height);
    return new_board;
}

// Main game function
void game_of_life(int width, int height, int iterations) {
    char **board = initialize_board(width, height);
    if (!board) return;
    
    for (int i = 0; i < iterations; i++) {
        board = update_board(board, width, height);
        if (!board) return;
    }
    
    print_board(board, width, height);
    free_board(board, height);
}
