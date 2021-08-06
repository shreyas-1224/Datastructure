
typedef struct node{
	char* data;
	int bf;
	struct node *left;
	struct node *right;
	struct node *parent;
}node;


typedef node* avl;


void init(avl* );
void insert(avl* , char* );
void inorder_traverse(avl);  
void LL_rotation(avl* , avl);
void RR_rotation(avl* , avl);
void RL_rotation(avl* , avl);
void LR_rotation(avl* , avl);
void rotation(avl*, avl);
int height(avl) ;
void delete_node(avl* , char*);
void destroy(avl*);
void destroy_all(avl);









