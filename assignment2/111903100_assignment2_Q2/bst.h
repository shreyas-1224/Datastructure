
typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}node;


typedef node* bst;


void postorder_to_tree(bst* , int , int , int*);
void inorder_traverse(bst );
void preorder_traverse(bst );
void postorder_traverse(bst);

























