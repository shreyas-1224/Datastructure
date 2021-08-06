#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "tree.h"

int main(){

	printf("----- put one space after each operand operator and in the end :\n");
	char* expression ;
	scanf("%[^\n]%*c",expression);
	expression = infixtopostfix(expression);
	//printf("%s\n",expression);
	bst l =(struct node*)malloc(sizeof(struct node));
	if(l == NULL)	printf("failed");
	
	l = construction(expression);
	printf("inorder_traverse is : ");
	inorder_traverse(l);
	
	printf("\n Ans is : %d",compute(l));
}
