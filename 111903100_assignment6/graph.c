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

struct node* create_node(int n , int w){

	node *newnode =(struct node*)malloc(sizeof(node));
	newnode->next = NULL;
	newnode->vertex = n ;
	newnode->weight = w ;
	return newnode ;			// returning pointer to the node ;
		
}

void add_edge(graph* g , int s , int d , int w){	// w is weight ;
	
	// create edge from source to destination .
	
	node* temp = create_node( d , w);
	temp->next = g->adj_list[s];
	g->adj_list[s]  = temp ;
	
	// create edge from the destination to source .
	
	node* temp2 = create_node(s , w);
	temp2->next = g->adj_list[d];
	g->adj_list[d] = temp2 ;	
	
	return ;
}

void display(graph g ){
	
	for(int i = 0 ; i < g.no_of_vertices ; i++){
		
		node *temp = g.adj_list[i] ;
		while(temp != NULL){
			
			printf("%d---%d weight : %d\n",i,temp->vertex,temp->weight);
			temp = temp->next ;
		}
	}	
}


void bfs(graph g , int v){
	
	int m ;
	node* temp = NULL ;
	int visited[g.no_of_vertices];
	queue q;
	q_init(&q , g.no_of_vertices);
	enqueue(&q,v);
	
	while(!(q_isempty(q))){
		
		m = dequeue(&q);
		temp = g.adj_list[m];
		
		if(visited[m] != 1){
			visited[m] = 1;
			while(temp != NULL  ){
				
				if(visited[temp->vertex] != 1){
				
					printf("%d---%d , weight : %d\n",m,temp->vertex ,temp->weight);
					enqueue(&q,temp->vertex);	
				}
				temp = temp->next ;
			
			}
		 
		}
		else{
			m = dequeue(&q);
		}
	}
}


void dfs(graph g , int v){

	node* temp = g.adj_list[v];
	stack s ;
	init(&s , g.no_of_vertices);
	int visited[g.no_of_vertices];
	push(&s,v);
	int m ;
	
	while(!(isempty(s))){
		
		m = peek(s);
		temp = g.adj_list[m];
		if(visited[m] != 1)	printf("%d---",m);
		visited[m] = 1;
			
		while(temp != NULL){
			if(visited[temp->vertex] != 1){
			
				push(&s,temp->vertex);
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



















