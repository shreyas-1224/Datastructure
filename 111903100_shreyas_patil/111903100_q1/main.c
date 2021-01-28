#include<stdio.h>
#include<stdlib.h>
#include "sll.h"

int main(){

	list head;
	init(&head);
	int n;
	//even(&head);
	printf("type numbers you want to append\n");
	while(scanf("%d",&n)!= -1){
		append(&head,n);
	}
	traverse(head);
	reverse_even(&head);
	traverse(head);
	
	
}
