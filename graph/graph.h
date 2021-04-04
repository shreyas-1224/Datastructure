

typedef struct graph{
	int a[8][8];
	int n;
	int visited[8];
}graph ;

void g_init(graph* , char*);
void g_insert(graph*);
void print(graph);
void DFS(graph , int);
void BFS(graph , int);
void DFS_loop(graph , int);
void prims(graph, int);
