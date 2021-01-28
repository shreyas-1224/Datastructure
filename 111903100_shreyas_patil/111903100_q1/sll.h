typedef struct node{
	int data;
	struct node * next;
}node;

typedef node* list;

void init(list *);
void append(list *,int);
void traverse(list);
void reverse_even(list*);
