#include <stdio.h>
#include <stdlib.h>
#include "maze.h"

int main(){
    maze m1;
    initMaze(&m1, "mazefile.txt");
    printMaze(&m1);
    printf("\n");
    printPath(&m1, 0, 0 , 4, 4);
    return 0;
}
