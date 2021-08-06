typedef struct graph {
		
	int n ;
	int **a ;
}graph ;


struct node{

	int source ;
	int dest ; 
	int weight ;
} ;

void g_init(graph*  , char*);
void print(graph g );
int partition(struct node* ,int,int);
void quicksort(struct node*,int ,int );
int find_parent(int , int*) ;
void kruskal_algo(graph) ;


