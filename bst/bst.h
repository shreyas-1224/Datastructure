
typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}node;


typedef node* bst;


void init(bst* );
void insert(bst* , int );
void inorder_traverse(bst);  
void preorder_traverse(bst);
void postorder_traverse(bst);
int search(bst,int);
int max_element(bst);
int height(bst t);
int total_elements(bst );
int leaf_nodes(bst);
int min_element(bst);
int isfull(bst );
int iscomplete(bst);
void level_order(bst);
int diameter(bst);
int isbalanced(bst);
void remove_node(bst*,int);
void right_view(bst );
void left_view(bst);
void bottom_view(bst);
void top_view(bst);
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



























