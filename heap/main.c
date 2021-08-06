#include<stdio.h>
#include<stdlib.h>
#include "heap.h"

int main(){
	
	heap h ;int i=0;
	init_heap(&h,10);
	
	// 3 5 9 6 8 20 10 12 18 9
	
	insert_heap(&h,30);//
	insert_heap(&h,52);//
	insert_heap(&h,9);//
	insert_heap(&h,600);
	insert_heap(&h,-8);//
	insert_heap(&h,20);
	insert_heap(&h,10);
	insert_heap(&h,121);
	insert_heap(&h,181);
	insert_heap(&h,-90);
	traverse_heap(h);	
	printf("\n");
	while(i<10){
		delete_heap(&h);
		i++;
	}
	h.rear = h.size - 1 ;
	traverse_heap(h);
	//printf("\n");
	//min_to_max(&h);
	
}


