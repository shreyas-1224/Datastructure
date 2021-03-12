#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include "bst_array.h"

void init(bst_arr* t , int size){
	
	t->size = size;
	t->arr = (int *)malloc(sizeof(int)*size);
	t->arr[0] = INT_MIN;
	return ; 

}

void int_max(bst_arr *t){
	
	int i = 0;
	while(i < t->size){
		
		t->arr[i] = INT_MAX;
		i++;
	}
	return ;

}
void insert(bst_arr* t, int data){
	
	if(t->arr[0] == INT_MIN){
		t->arr[0] = data;
		return ;
	}
	
	int i = 0;
	
	while(t->arr[i] && t->arr[i] != INT_MAX  && i < t->size){
	
		if(data == t->arr[i])	return ;		// element already present. 
		
		else if( data < t->arr[i])	i = i*2 + 1;
		
		else	i = i*2 + 2;
		
	}
	
	if( i < t->size){
		
		t->arr[i] = data ;
	
	}
	
	return ;
	
	
}


void inorder_traverse(bst_arr t, int i){
	
	if(i >= t.size || t.arr[0] == INT_MIN)	return ;
	
	inorder_traverse(t , 2*i + 1);
	if(t.arr[i] != INT_MAX)	printf("%d ",t.arr[i]);
	inorder_traverse(t , 2*i + 2);
	return ;

}

void preorder_traverse(bst_arr t, int i){
	
	if(i >= t.size || t.arr[0] == INT_MIN)	return ;
	
	if(t.arr[i] != INT_MAX)	printf("%d ",t.arr[i]);
	inorder_traverse(t , 2*i + 1);
	inorder_traverse(t , 2*i + 2);
	return ;

}

void postorder_traverse(bst_arr t, int i){
	
	if(i >= t.size || t.arr[0] == INT_MIN)	return ;
	
	inorder_traverse(t , 2*i + 1);	
	inorder_traverse(t , 2*i + 2);
	if(t.arr[i] != INT_MAX)	printf("%d ",t.arr[i]);
	return ;

}

void traverse(bst_arr t){
	
	int i = 0;
	while(i < t.size){
		if(t.arr[i] != INT_MAX)	printf("%d ", t.arr[i]);
		i++;
	}
	return ;

}

void delete(bst_arr* t , int data){
	
	int i = 0 ;
	int k  ; 
	
	while(i < t->size && t->arr[i]!= data){
		
		if(data < t->arr[i])	i = i*2 + 1 ;
		else			i = i*2 + 2 ;
		
	} 
	
	int m = i ; 		// index to delete ;
	if(i >= t->size){
		printf("no data found");
		return ;
	}
	// node with no child ; 
	t->arr[i] = INT_MAX;

	// node with one child ;
	if(t->arr[2*i + 2] == INT_MAX && t->arr[2*i + 1] != INT_MAX){			// only left child;
		
		k = t->arr[2*i + 1];
		t->arr[2*i + 1] = INT_MAX ;
		t->arr[i] = k ;
	}
	
	if(t->arr[2*i + 1] == INT_MAX && t->arr[2*i + 2] != INT_MAX){			// only left child;
		
		k = t->arr[2*i + 2];
		t->arr[2*i + 2] = INT_MAX ;
		t->arr[i] = k ;
	}
	
	// node with 2 childs ; 
	
	while(t->size > (2*i + 1) && t->arr[2*i + 1] != INT_MAX)	i = 2*i + 1 ;
	while(t->size > (2*i + 2) && t->arr[2*i + 2] != INT_MAX)	i = 2*i + 2 ;
	
	t->arr[m] = t->arr[i] ;
	t->arr[i] = INT_MAX ;
	return ;
	
	
	
	

}





