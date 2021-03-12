// array implementation of binary search tree . 

typedef struct node{

	int *arr;
	int size;
	int total;

}bst_arr;

void init(bst_arr* , int );
void insert(bst_arr* , int);
void traverse(bst_arr);
void inorder_traverse(bst_arr, int);
void preorder_traverse(bst_arr,int);
void postorder_traverse(bst_arr,int);
void int_max(bst_arr*);
void delete(bst_arr* ,int )
;

