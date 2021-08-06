typedef struct graph{
	
	int n ;
	int **a ;
	int e ;
}graph ;

typedef struct node{
	
	int source ;
	int dest ;
	int weight ;
	int visited;
}node ;


void g_init(graph* , char*);
void g_insert(graph*);
void print(graph);
void DFS(graph , int);
void BFS(graph , int);
void DFS_loop(graph , int);
void prims(graph, int);
void kruskal(graph ) ;
int find_parent( int , int*);
void Dijkstras_algo(graph , int);
void Bellman_Ford(graph , int);
void is_cycle(graph);
int is_bipartite(graph);
