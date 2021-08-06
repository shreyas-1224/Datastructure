#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include "heap.h"
void init_heap(heap *h , int length){
	
	h->arr = (int *)malloc(sizeof(int )*length);
	if(h->arr == NULL ){
		printf("memory could not be allowed");
	}
	h->size = length ;
	h->rear = -1;
}



void insert_heap(heap *h , int data){
	
	h->rear++ ;
	if(h->rear == h->size){
		
		printf("heap is full");
		return ;
	}
	
	h->arr[h->rear] = data ; 	// data inserted at leaf nodes , now just compare and swap the nodes . 
	
	int i = h->rear ; 
	int j = (i- 1) / 2 ;		// gives parent node.
	

	while(j >= 0 && (h->arr[j] < h->arr[i])){
			
		int temp = h->arr[i] ;
		h->arr[i] = h->arr[j] ;
		h->arr[j] = temp ;
			 		
		i = j ; 
		j = (j - 1) / 2 ;
			
	}
	
	return ;
	
}


void traverse_heap(heap h){

    int i = 0;
    while(i <= h.rear){
        printf("%d\t",h.arr[i++]);
    }
    return;
}

void delete_heap(heap *h ){		// deletion from the front only . 
	
	if(h->rear == - 1){
		//printf("empty heap");
		return ;
	}	
	
	int temp = h->arr[0], i = 0 ;
	h->arr[0] = h->arr[h->rear] ;
	int temp2 ;
	
	h->rear-- ;
	while(i <= h->rear && (2*i + 1 <= h->rear )){
		
		if((2*i + 2 > h->rear && 2*i + 1 <= h->rear)|| (h->arr[2*i + 1 ] > h->arr[2*i + 2] )){
			
			if(h->arr[i] < h->arr[2*i + 1]){
				
				temp2 = h->arr[i] ;
				h->arr[i] = h->arr[2*i + 1] ; 
				h->arr[2*i + 1] = temp2 ;
				
				i = 2*i + 1 ;
			}
			else 	break ;
		}
		
		else{
			if(h->arr[i] < h->arr[2*i + 2]){
				
				temp2 = h->arr[i] ;
				h->arr[i] = h->arr[2*i + 2] ; 
				h->arr[2*i + 2] = temp2 ;
				
				i = 2*i + 2 ;
			}
			else 	break ;	
			
		}
		
	}
	h->arr[h->rear + 1] = temp ;
	return ;
} 
	
void heapify_min(heap* h, int i ){
	
	int l = 2*i + 1 ; 
	int r = 2*i + 2 ;
	int min = i ;
	
	if(l <= h->rear  && h->arr[l] < h->arr[min]){
		min = l ;
	}
	
	if(r <= h->rear  && h->arr[r] < h->arr[min]){
		min = r ;
	}
	
	if(min != i)	{
		swap(&(h->arr[i]),&(h->arr[min]));
		heapify_min(h , min);
	}
	
	else 		return ;
}

void max_to_min(heap* h){
	
	int i = (h->rear - 1) / 2 ;
	while(i >= 0){
		heapify_min(h , i);
		i-- ;
	}	
	traverse_heap(*h);
}	

void swap(int *a,int *b){
   
   int temp = *a;
   *a = *b;
   *b = temp;
}		



























