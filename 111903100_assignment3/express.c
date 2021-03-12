#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "tree.h"
#include<math.h>
#include<ctype.h>

void create_node(bst *t , char c ){
	
	*t = (struct node *)malloc(sizeof(struct node));
	(*t)->left = NULL;
	(*t)->right = NULL;	
	(*t)->data.symbol = c;
}

void create_opnode(bst *t , int c ){
	
	*t = (struct node *)malloc(sizeof(struct node));
	(*t)->left = NULL;
	(*t)->right = NULL;	
	(*t)->data.number = c;
}

bst construction( char* line){
	
	int i = 0 ;
	int number = 0 ;
	p_stack s ; p_init(&s , 200);
	bst p =  NULL , q = NULL , r = NULL, root = NULL;
	
	
	while(line[i] != '\0'){
		
		if(isdigit(line[i])){
			
			char op[10] ; int x = 0;
			while(isdigit(line[i])){
			
				op[x] = line[i];
				i++;
				x++;
			}
			number = convert(op , x);
			create_opnode(&r ,number);
			p_push(&s , r);
		}
		else if (isoperator(line[i])){
			
			p = p_pop(&s);
			q = p_pop(&s);
			
			create_node(&root , line[i]);
			root->right = p;
			root->left = q;
			
			p_push(&s , root);
		}
		i++;
		
	}
	
	root = p_pop(&s);
	return root ;
	
}








int convert(char* a , int size){
	
	int j = size;
	int k = 0 ;
	int number = 0; 
	
	for(int i = j-1 ; i>=0 ; i--){
		
		int m = a[i] - '0';
		number = number + m * (int)(pow(10, k) + 0.5);
		k++;		
	}
	return number;
	
}


void inorder_traverse(bst t){
	
	if(t == NULL) return ;
	inorder_traverse(t->left);
	
	if(t->left == NULL && t->right == NULL)
		printf("%d ",t->data.number);
	else
		printf("%c ",t->data.symbol);
		
	inorder_traverse(t->right);
}




int precedence(char c){
    if(c=='+' || c=='-'){return 10;}
    else if( c == '(') return 0 ;
    else if(c=='*' || c=='/' || c=='%') return 20;
    else if (c=='^'){return 50;}
}



int isoperator(char b){
	
	if(!(b=='+' || b=='-' || b=='*' || b=='/' || b=='^' || b=='%')){
		return 0;
	}
	else{
		return 1;
	}
}

int compute(bst root){
	
	if(root->left == NULL && root->right == NULL)	
		return root->data.number ;
	
	int left = compute(root->left);
	int right = compute(root->right);
	
	switch(root->data.symbol){
		
		case '+': return left + right ;
		case '-': return left - right ;
		case '*': return left * right ;
		case '/': return left / right ;
		case '%': return left % right ;
	}
	
	
}














