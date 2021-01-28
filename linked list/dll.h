typedef struct node{
    struct node* next;
    struct node* prev;
    int length,data;
}node;

typedef node* list;

void init(list*);
void append(list*,list*,int);
void traverse(list);
void number(list *,int );
int addition(list ,list);
void _traverse(list );