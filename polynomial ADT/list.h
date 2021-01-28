typedef struct node{
	int coff;
	int power;
	struct node *next;
	struct node *prev;
}node;

typedef node* list;

void init(list *);
void append(list *,int,int);
void traverse(list);
list poly_add(list ,list);
