typedef struct stack{
	int * a;
	int top,size;
}stack;

void init(stack *,int);
void push(stack *,int);
int pop(stack*);
int isempty(stack);
int isfull(stack);
int peek(stack);

