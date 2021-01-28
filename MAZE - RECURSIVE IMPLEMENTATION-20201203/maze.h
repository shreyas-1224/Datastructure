
typedef struct maze{
    int a[10][10];
    int n;
}maze;

void initMaze(maze *m, char *filename1);
void printMaze(maze *m);
void printPath(maze *m,int x1, int y1, int x2, int y2);
