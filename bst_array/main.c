#include<stdio.h>
#include<limits.h>
#include "bst_array.h"

int main(){
	bst_arr t ; 
	init(&t , 50); 
	int_max(&t);
	insert(&t , 100); insert(&t , 200); insert(&t , 50); 
	insert(&t,25); insert(&t,75);//insert(&t,150);
	insert(&t,300);

	
	
}



