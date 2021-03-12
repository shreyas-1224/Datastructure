
typedef struct node{
	int data;
	int bf;
	struct node *left;
	struct node *right;
	struct node *parent;
}node;


typedef node* avl;


void init(avl* );
void insert(avl* , int );
void inorder_traverse(avl);  
void preorder_traverse(avl);
void postorder_traverse(avl);
avl search(avl,int);
int max_element(avl);
int height(avl t);
int total_elements(avl );
int leaf_nodes(avl);
int min_element(avl);
int isfull(avl );
int iscomplete(avl);
void level_order(avl);
int diameter(avl);
int isbalanced(avl);
void remove_node(avl*,int);
void right_view(avl );
void left_view(avl);
void bottom_view(avl);
void top_view(avl);
void LL_rotation(avl* , avl);
void RR_rotation(avl* , avl);
void RL_rotation(avl* , avl);
void LR_rotation(avl* , avl);
void rotation(avl*, avl);












