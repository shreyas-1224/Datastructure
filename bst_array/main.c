#include<stdio.h>
#include<limits.h>
#include "bst_array.h"

int main(){
	
	bst_arr t ; 
	init(&t , 50);
	insert(&t , 100); insert(&t , 200); insert(&t , 50); 
	insert(&t , 300);insert(&t , 1000); insert(&t , 20); insert(&t , 5); 
	insert(&t , 3000);insert(&t , 10000); insert(&t , 2); insert(&t , -5); 
	insert(&t , 30000);
	
	traverse(t);

}



