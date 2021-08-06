#include<stdio.h>
#include<stdlib.h>
#include "graph.h"
#include "stack.h"
#include "queue.h"

void init_graph( graph* g , int n ){

	g->no_of_vertices = n ;
	g->adj_list =(struct node**)malloc(sizeof(struct node*) * n);
	for(int i = 0 ; i < n ; i++){
		g->adj_list[i] = NULL ;
	}
	return  ;

}

struct node* create_node(char n , int w){

	node *newnode =(struct node*)malloc(sizeof(node));
	newnode->next = NULL;
	newnode->vertex = n ;
	newnode->weight = w ;
	return newnode ;			// returning pointer to the node ;
		
}

void add_edge(graph* g , char s , char d , int w){	// w is weight ;
	
	// create edge from source to destination .
	
	node* temp = create_node( d , w);
	int i = s - 97 ;
	temp->next = g->adj_list[i];
	g->adj_list[i]  = temp ;
	
	// create edge from the destination to source .
	
	node* temp2 = create_node(s , w);
	i = d - 97 ;
	temp2->next = g->adj_list[i];
	g->adj_list[i] = temp2 ;	
	
	return ;
}


void display(graph g ){
	
	for(int i = 0 ; i < g.no_of_vertices ; i++){
		
		node *temp = g.adj_list[i] ;
		while(temp != NULL){
			
			printf("%c---%c weight : %d\n",i + 97,temp->vertex ,temp->weight);
			temp = temp->next ;
		}
	}	
}



void bfs(graph g , char v){
	
	int m ;
	node* temp = NULL ;
	int visited[g.no_of_vertices];
	queue q;
	q_init(&q , g.no_of_vertices);
	int j = v - 97;
	enqueue(&q,j);
	
	while(!(q_isempty(q))){
		
		m = dequeue(&q);
		temp = g.adj_list[m];
		
		if(visited[m] != 1){
		
			
			visited[m] = 1;
			while(temp != NULL  ){
				j = temp->vertex - 97 ;
				if(visited[j] != 1){
				
					printf("%c---%c , weight : %d\n",m + 97,temp->vertex ,temp->weight);
					
					enqueue(&q,j);	
				}
				temp = temp->next ;
			
			}
		 
		}
		else{
			m = dequeue(&q);
		}
		
		
	}
}



void dfs(graph g , char v){

	node* temp = g.adj_list[v];
	stack s ;
	init(&s , g.no_of_vertices);
	int visited[g.no_of_vertices];
	int j = v - 97 ;
	push(&s,j);
	int m ;
	
	while(!(isempty(s))){
		
		m = peek(s);
		temp = g.adj_list[m];
		if(visited[m] != 1)	printf("%c---",m + 97);
		visited[m] = 1;
			
		while(temp != NULL){
			j = temp->vertex - 97 ;
			if(visited[j] != 1){
			
				push(&s,j);
				break ;	
			}
			else
				temp = temp->next ;
		}
	
		if(temp == NULL){
			int n = pop(&s);
		}			
	
	
					
	
	}
}



















