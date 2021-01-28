#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include "queue.h"

void init(queue *q,int length){
	q->a=(int*)malloc(sizeof(int)*length);
	q->size=length;
	q->front=-1;q->rear=-1;
}

int isempty(queue q){
	if(q.rear==q.front){
		return 1;
	}
	return 0;
}

int isfull(queue q){
	if(q.front==(q.rear+1)%q.size){
		return 1;
	}
	return 0;

}

void enque(queue *q,int n){
	if(isfull(*q)){return ;}
	else if (isempty(*q)){
		q->front=0;
		q->rear=0;
		q->rear=n;
		return;
	}
	q->rear=(q->rear+1)%q->size;
	return ;
}

int deque(queue* q){
	if(isempty(*q)){return INT_MIN;}
	if(q->front==q->rear){
		int p=q->a[q->front];
		q->front=-1;
		q->rear=-1;
		return p;
	}
	int p=q->a[q->front];
	q->front=(q->front+1)&q->size;
	return p;

}









