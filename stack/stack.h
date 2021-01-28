typedef struct stack{
	int * a;
	int top,size;
}stack,queue;

void init(stack *,int);
void push(stack *,int);
int pop(stack*);
int isempty(stack);
int isfull(stack);
int peek(stack);

void q_init(queue* ,int);
int q_isfull(queue);
int q_isempty(queue);
void q_push(queue *, int );
int q_pop(queue*);
int q_peek(queue);
