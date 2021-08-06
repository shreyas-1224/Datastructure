#include<stdio.h>
#include<limits.h>
#include "bst_array.h"

int main(){
	
	bst_arr t ; 
	init(&t , 50); int_max(&t);
	insert(&t , 100); 
	insert(&t , 200); 
	insert(&t , 50); 
	insert(&t,25);
	insert(&t,-5);
	insert(&t,2);
	insert(&t,255);
	insert(&t , 109);
	insert(&t , 201); 
	insert(&t , 50); 
	insert(&t,104); 
	insert(&t,-53);
	insert(&t,23);
	insert(&t,2557);
	traverse(t);
	printf("\npreorder : ");
	preorder_traverse(t,0);
	printf("\ninorder : ");
	inorder_traverse(t,0);
	printf("\npostorder : ");
	postorder_traverse(t,0);
}



