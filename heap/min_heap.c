#include<stdio.h>
#include<stdlib.h>
#include "heap.h"

void init_heap(heap *h, int length){
	
	h->arr =(int *)malloc(sizeof(int)*length) ;
	h->rear = -1 ; 
	h->size = length ;
}

void insert_heap(heap* h , int data){
		
	if(h->rear == h->size - 1){
		printf("heap is full");
		return ;
	}
	
	h->rear++ ;
	h->arr[h->rear] = data ;
	//  now check for heap condition ; 
	
	int i , j ;
	i = h->rear ;
	
	while(i > 0){
		
		j = (i-1)/ 2 ;
		if(h->arr[i] < h->arr[j] )
		{
			swap(&(h->arr[i]) , &(h->arr[j])) ;
		}
		else break ;
		
		i = j;
	}
	
	return ;
}

void swap(int *a,int *b){
   
   int temp = *a;
   *a = *b;
   *b = temp;
}

void traverse_heap(heap h){
	
	int i = 0;
	while(i <= h.rear){
		printf("%d ",h.arr[i]);
		i++;
	}
}


void delete_heap(heap* h){
	
	if(h->rear == -1){
		printf("heap is empty");
		return ;
	}
	
	int i , j ;
	i = 0 ;
	swap(&(h->arr[h->rear]),&(h->arr[0]));
	h->rear-- ;
	
	while(i <= h->rear && (2*i + 1 <= h->rear )){
		
		if((2*i + 2 > h->rear && 2*i + 1 <= h->rear)|| (h->arr[2*i + 1 ] < h->arr[2*i + 2] )){
			
			if(h->arr[i] > h->arr[2*i + 1]){
				
				swap(&(h->arr[2*i+1]),&(h->arr[i]));
				
				i = 2*i + 1 ;
			}
			else 	break ;
		}
		
		else{
			if(h->arr[i] > h->arr[2*i + 2]){
				
				swap(&(h->arr[2*i+2]),&(h->arr[i]));
				
				i = 2*i + 2 ;
			}
			else 	break ;	
			
		}
		
	}
	 
}

void heapify(heap* h, int i ){
	
	int l = 2*i + 1 ; 
	int r = 2*i + 2 ;
	int max = i ;
	
	if(l <= h->rear  && h->arr[l] > h->arr[max]){
		max = l ;
	}
	
	if(r <= h->rear  && h->arr[r] > h->arr[max]){
		max = r ;
	}
	
	if(max != i)	{
		swap(&(h->arr[i]),&(h->arr[max]));
		heapify(h , max);
	}
	
	else 		return ;
}

void min_to_max(heap* h){
	
	int i = (h->rear - 1) / 2 ;
	while(i >= 0){
		heapify(h , i);
		i-- ;
	}	
	traverse_heap(*h);
}




//

// t is a binary tree .

// bt is a binary tree . q is the queue to fill the tree elements . and total_elements is total number of elements function . 

void CopyTreeToHeap(heap *h , bt t){

	
	if(t == NULL) return ;
	queue q; 
	q_init(&q,total_elements(t));
	enqueue(&q,t);
	bt l; init(&l);
	
	while(!(is_empty(q))){
		
		l = dequeue(&q);
		insert(h , l->data);					// passing adress.
		//adjust(*h) ; 						// heapify .
		if(l->left != NULL){enqueue(&q,l->left);}
		if(l->right != NULL){enqueue(&q,l->right);}	
		
	}
	return ;
	
	
	
	     

}

void insert(heap* h , int data){
	if(h->rear == h->size - 1) return ;
	h->rear ++ ;
	h->arr[h->rear] = data ;
	adjust(h)			// this will heapify the heap . 
	return ;
}







