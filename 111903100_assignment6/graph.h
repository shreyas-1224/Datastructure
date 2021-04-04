
typedef struct node{
	
	int vertex ;
	int weight ;
	struct node *next ;
} node ;

typedef struct graph{
	
	int no_of_vertices ;
	struct node** adj_list;		// array of pointers;
} graph ;
 

void init_graph(graph * , int);
struct node* create_node( int , int );
void add_edge(graph* , int , int , int );
void bfs(graph , int);
void dfs(graph , int); 
void display(graph);
 
 
