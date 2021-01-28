typedef struct queue{
    int data;
    int front;
    int rear;
    int size;
    int *queue;
}que;

void init(que*,int );
void enque(que*,int );
int deque(que*);
void display(que);
void peek(que);
int isempty(que);
int isfull(que);
//stack using queue prototype
void stack_push(que *,int);
int stak_pop(que*);




