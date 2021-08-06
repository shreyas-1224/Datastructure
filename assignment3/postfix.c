/*
Algorithm to convert infix expression to postfix
1. Declare a char cstack and initialize it
2. Read the infix expression from L-R char by char

3. if operand is encountered - append it to output string
4. if '(' is encountered - push it in the cstack
5. if ')' pop all characters and appeend to output string till
    '(' is encountered. DO not append '('
6. if operator is encountered pop all operators of higher or equal precedence and append to o/p
    or till cstack is not empty or ')' is encountered. drop ')'
7. push the operator of step 6.
8  repeat 2 - 6 till end of expression
9 pop all characters and append.


*/


#include"tree.h"
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>


char* infixtopostfix(char* ch) {
// 
    char *c;
    c =(char *)malloc(sizeof(char)*50);
    stack s;
    i_init(&s,50);
    int i =0 , j = 0;
    char m ;
    
    while(ch[i] != '\0'){
    	
    	if(isdigit(ch[i])){
    		
    		while(isdigit(ch[i])){
    			c[j] = ch[i];
    			j++;
    			i++; 
    		
    		}
    		if(ch[i] == ' ') c[j++] = ' ';
    	}	
    	
    	else if(ch[i] == '('){
    		i_push(&s , '(');
    	}
    	
    	else if(ch[i] == ')'){
    		while(i_peek(s) != '(' && !(isempty(s)))
    			c[j++] = i_pop(&s);
    			c[j++] = ' ';
    			
    		
    		if(i_peek(s) == '(')	 m = i_pop(&s);
    	}
    	
    	else if(isoperator(ch[i])){
    		
    		while(!isempty(s) && precedence(i_peek(s)) >= precedence(ch[i])){
    			c[j++] = i_pop(&s);
    			c[j++] = ' ';
    		}
    		i_push(&s ,ch[i]);
    	
    	}
    	i++;
    	
    }    

    while(!(isempty(s))){
    	c[j++] = i_pop(&s);
    	c[j++] = ' ';
    	
    }
    c[j] = '\0';
    return c ;
 }
 
 
 
