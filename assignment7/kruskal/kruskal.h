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

void g_init(graph *g , char*);
void quicksort(node* , int , int );
int partition(node * , int , int );
void kruskal(graph );
int find_parent(int , int*);
void swap(node* , node*);

