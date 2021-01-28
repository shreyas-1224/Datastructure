#include <stdio.h>
#include <stdlib.h>
#include<limits.h>
#include "cqueue.h"

void init(que *q,int len){
    q->queue=(int*)malloc(sizeof(int)*len);          //initialize
    q->size=len;
    q->rear=q->front= -1;
    return ;
}

int isempty(que q){
    if(q.front== -1 && q.rear == -1){
       
        return 1;
    }
    else 
        return 0;
}

int isfull(que q){
    if(q.front == ((q.rear+1)%(q.size)) && q.front!= -1){
        
        return 1;
    }
    else
    {
            return 0;
    }
    
}

void enque(que * q,int x){
    if(isfull(*q)){
    	printf("queue full");
        return ;
    }
   else if(isempty(*q)){
       q->front=q->rear=0;
       q->queue[q->rear]=x;
       return ;
   }
   else{
       q->rear=(q->rear+1)%q->size;
       q->queue[q->rear]=x;
       return ;
    }
}

int deque(que *q){
    if(isempty(*q)){
        printf("queue is empty\n");
        return INT_MIN;
    }
    else if(q->rear == q->front && q->rear!= -1){   //if its a last node;
        int p=q->queue[q->front]; 
        q->front=q->rear=-1;
        return p;
    }
    
    else{
        int p=q->queue[q->front];    //general dequeue;
        q->front=(q->front + 1)%q->size;
        return p;


    }
}

void peek(que q){                  //give the front element.
    if(!(isempty(q)))
        printf("%d",q.queue[q.front]);
    else
        printf("nothing to peek\n");
    
}

void display(que q){          
    if(!(isempty(q))){
        int i=q.front;
        while(i!=q.rear){
            printf("%d  ",q.queue[i]);              
            i=(i+1)%q.size;

        }
        printf("%d",q.queue[q.rear]);
    }
    else{
        printf("queue is empty");
    }
}
