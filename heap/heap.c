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
	int j = (i- 1) / 2 ;

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
		printf("empty heap");
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
	
				



























