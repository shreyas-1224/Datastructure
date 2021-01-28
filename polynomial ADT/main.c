#include<stdio.h>
#include<limits.h>
#include "list.h"

int main(){
	list a,b;
	init(&a);init(&b);
	append(&a,10,5);
	append(&a,9,4);
	append(&a,3,1);
	append(&a,6,0);
	printf("a appended");
	append(&b,12,6);
	append(&b,10,4);
	append(&b,3,3);
	append(&b,2,2);
	append(&b,6,1);
	append(&b,9,0);
	printf("b appended");
	list head;init(&head);head=poly_add(a,b);
	printf("a appended");
	head->next=NULL;
	traverse(head);
	return 0;
}
