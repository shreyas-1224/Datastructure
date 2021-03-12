#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include "bst.h"

// bst is node * ... node is stucture of tree.
void q_init(queue *q,int length){
	
	// q->a =(type(element) *) malloc(sizeof(element)* number_elements)
	q->a=(bst *)malloc(sizeof(node*)*length);
	q->size=length;
	q->front=-1;q->rear=-1;
}

int is_empty(queue q){
	if(q.rear==-1 && q.front==-1){
		return 1;
	}
	return 0;
}

int is_full(queue q){
	if(q.front==(q.rear+1)%q.size){
		return 1;
	}
	return 0;

}

void enqueue(queue *q,bst n){
	if(is_full(*q)){return ;}
	else if (is_empty(*q)){
		q->front=0;
		q->rear=0;
		q->a[q->rear]=n;
		return;
	}
	q->rear=q->rear+1;
	q->a[q->rear]=n;
	return ;
}

bst dequeue(queue* q){
	if(is_empty(*q)){return NULL;}
	if(q->front==q->rear){
		bst p=q->a[q->front];
		q->front=-1;
		q->rear=-1;
		return p;
	}
	return q->a[q->front++];

}









