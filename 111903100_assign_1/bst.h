
typedef struct node{
	int mis;
	char *name;
	struct node *left;
	struct node *right;
	struct node *parent;
}node;


typedef node* bst;


void init(bst* );
void insert(bst* ,bst* , int, int ,char* );
void postorder_traverse(bst);
char* search(bst,int);
void level_i(bst,int);
void remove_node(bst*,int);
void destroy(bst );
void inorder_traverse(bst );
void destroy_all(bst *);
void copy(char**,char*);
//_____________________________________________________________

//queue that can include the nodes.

typedef struct queue{
	bst *a;
	int size;
	int rear,front,count;
}queue;

void q_init(queue*,int);
void enqueue(queue* , bst);
int is_empty(queue);
int is_full(queue);
bst dequeue(queue*);

//stack that includes nodes.

typedef struct stack{
    int top;
    int size;
    bst *arr;
}p_stack;

void p_init(p_stack *,int );
int p_isempty(p_stack );
void p_push(p_stack *,bst );
int p_isfull(p_stack );
bst p_pop(p_stack *);
bst p_peek(p_stack);



























