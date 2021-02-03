#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include "bst_array.h"

void init(bst_arr* t , int size){
	
	t->size = size;
	t->arr = (int *)malloc(sizeof(int)*size);
	t->arr[0] = INT_MIN;
	t->total = 0;
	return ; 

}

void insert(bst_arr* t, int data){

	if( t->total == t->size ) return ;   // array is full.
	
	if(t->arr[0] == INT_MIN){
		t->arr[0] = data;
		t->total = t->total + 1;
		return ;
	}
	
	int i = 0;
	
	while(t->arr[i] && i < t->size){
	
		if(data == t->arr[i])	return ;		// element already present. 
		
		else if( data < t->arr[i])	i = i*2 + 1;
		
		else	i = i*2 + 2;
		
	}
	
	if( i < t->size){
		
		t->arr[i] = data ;
		t->total = t->total + 1;
	
	}
	
	return ;
	
	
}



void traverse(bst_arr t){
	
	int i = 0;
	while(i < t.size){
	if(t.arr[i] != 0)	printf("%d ", t.arr[i]);
		i++;
	}
	return ;

}







