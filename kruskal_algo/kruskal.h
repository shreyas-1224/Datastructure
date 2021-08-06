typedef struct graph{
	
	int n ;
	int **a ;
	int e ;
}graph ;

typedef struct node{
	
	int source ;
	int dest ;
	int weight ;
}node ;

void g_init(graph *g , char*);
int find_parent(int , int*);
void kruskal(graph );
