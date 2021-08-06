#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include "queue.h"

// int is node * ... node is stucture of tree.
void q_init(queue *q,int length){
	
	// q->a =(type(element) *) malloc(sizeof(element)* number_elements)
	q->a=(int *)malloc(sizeof(int)*length);
	q->size=length;
	q->front=-1;q->rear=-1;
}

int q_isempty(queue q){
	if(q.rear==-1 && q.front==-1){
		return 1;
	}
	return 0;
}

int q_isfull(queue q){
	if(q.front==(q.rear+1)%q.size){
		return 1;
	}
	return 0;

}

void enqueue(queue *q,int n){
	if(q_isfull(*q)){return ;}
	else if (q_isempty(*q)){
		q->front=0;
		q->rear=0;
		q->a[q->rear]=n;
		return;
	}
	q->rear=q->rear+1;
	q->a[q->rear]=n;
	return ;
}

int dequeue(queue* q){
	if(q_isempty(*q)){return INT_MIN;}
	if(q->front==q->rear){
		int p=q->a[q->front];
		q->front=-1;
		q->rear=-1;
		return p;
	}
	return q->a[q->front++];

}



