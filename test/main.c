#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include "bst.h"

int main(){
	bst root;
	init(&root);
	insert(&root,100); insert(&root,50);//insert(&t,70);insert(&t,20);
	//insert(&t,200);//insert(&t,150);insert(&t,300);
	
	bst_arr arr ; 
	ar_init(&arr , 50);
	convert(root,&arr,0 );
	printf("completed");
	
	
	return 0;
}
