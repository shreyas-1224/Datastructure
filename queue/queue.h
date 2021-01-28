typedef struct queue{
	int *a;
	int size;
	int rear,front,count;
}queue;

void init(queue*,int);
void enque(queue* , int);
int isempty(queue);
int isfull(queue);
int deque(queue*);

