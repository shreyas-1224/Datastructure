typedef struct queue{
	int *a;
	int size;
	int rear,front,count;
}queue;

void q_init(queue*,int);
void enqueue(queue* , int);
int q_isempty(queue);
int q_isfull(queue);
int dequeue(queue*);

