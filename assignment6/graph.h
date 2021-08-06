
typedef struct node{
	
	char vertex ;
	int weight ;
	struct node *next ;
} node ;

typedef struct graph{
	
	int no_of_vertices ;
	struct node** adj_list;		// array of pointers;
} graph ;
 

void init_graph(graph * , int);
struct node* create_node( char , int );
void add_edge(graph* , char , char , int );
void bfs(graph , char);
void dfs(graph , char); 
void display(graph);
 
 
