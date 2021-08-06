typedef union{
	int number;
	char symbol;
}type;

typedef struct node{
	
	struct node *left;
	struct node *right;
	type data;

}node;


typedef node* bst;


void create_opnode(bst* , int );
void create_node(bst* , char);
void insert(bst* , int );
void inorder_traverse(bst);  
void preorder_traverse(bst);
void postorder_traverse(bst);
bst construction( char*);

typedef struct i_stack{
	char * a;
	int top,size;
}stack;



void i_init(stack *,int);
void i_push(stack *,char);
char i_pop(stack*);
int isempty(stack);
int isfull(stack);
char i_peek(stack);
char* infixtopostfix(char*);

//checking if given expression is valid or not : 
int check(char * );
int isoperator(char );

int precedence(char);

// stack of node pointer ;

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

int calculate(int , int , char);
int compute(bst);
int convert(char* ,int);
