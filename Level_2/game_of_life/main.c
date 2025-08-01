#include "life.h"

int main(int argc, char **argv) {
    if (argc != 4) return 1;
    
    int width = atoi(argv[1]);
    int height = atoi(argv[2]);
    int iterations = atoi(argv[3]);

    if (width <= 0 || height <= 0 || iterations < 0) return 1;

    game_of_life(width, height, iterations);
    return 0;
} 