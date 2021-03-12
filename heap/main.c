#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include "heap.h"

int main(){
	
    heap h;
    init_heap(&h,10);
    insert_heap(&h,10);
    insert_heap(&h,5);
    insert_heap(&h,15);
    insert_heap(&h,2);
    insert_heap(&h,3);
    insert_heap(&h,18);
    insert_heap(&h,16);
    insert_heap(&h,9);
    insert_heap(&h,8);
    traverse_heap(h) ;
    printf("\n");
    for(int i = 0 ; i< 9 ;i++){
    	delete_heap(&h);
    	 traverse_heap(h) ;
    printf("\n");
   }
   h.rear = h.size - 1 ;
    traverse_heap(h);

}
