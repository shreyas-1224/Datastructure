#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include "graph.h"
#include "stack.h"
#include "queue.h"

void g_init(graph *g, char* name){
	
	FILE* fptr ;

	fptr = fopen(name , "r");
	if(fptr == NULL)	return ;
	
	fscanf(fptr,"%d",&(g->n));
	g->e = 0;
	g->a = (int**)malloc(sizeof(int*)* g->n);
	
	for(int i = 0 ; i < g->n ; i++){
		
		g->a[i] = (int *)malloc(sizeof(int) * g->n);
		for(int j = 0 ; j < g->n ; j++){
			fscanf(fptr,"%d",&(g->a[i][j]));
			if(g->a[i][j] != 0)	
				g->e ++ ;
		}
	}
	
	fclose(fptr);
	
	return ;
		
}


void print(graph g){
	
	for(int i = 0 ; i < g.n ; i++){
		for(int j = 0 ; j < g.n ; j++){
			printf("%d " , g.a[i][j]);
		}
		
		printf("\n");
		
	}
}


// depth first search implementation . using global array ; 

int visited[20] ;

// using recursion ; 

void DFS(graph g , int u){
	
	visited[u] = 1 ;
	
	for(int i = 0 ; i < g.n ; i++){
		
		if(visited[i] != 1 && g.a[u][i] == 1){
			printf("%d--%d\n",u,i);
			DFS(g , i);
		}
	}
}



void BFS(graph g , int i){

	queue q ; q_init(&q, g.n);
	enqueue(&q , i);
	visited[i] = 1 ;
	while(!(q_isempty(q))){
	
		i = dequeue(&q);
		printf("%d\t", i);
        	for(int j = 0; j< g.n; j++) {
            		if(g.a[i][j] == 1 && visited[j] == 0) {
               		 visited[j] = 1;
               		 enqueue(&q, j);
            		}
		
		}
	}
}

void DFS_loop(graph g , int u){

	stack s ;
	init(&s , g.n);
	push(&s, u);
	int visited[g.n];
	
	while(! isempty(s)){
		
		int v = peek(s);
		int flag = 0 ;
		if(visited[v] != 1)	printf("%d--",v);
		visited[v] = 1 ;
		
		for(int i = 0 ; i < g.n ; i++){
			
			if(visited[i] != 1 && g.a[v][i] == 1){
				
				
				push(&s , i);
				flag = 1 ;
				break ;
			}
		}
		
		if(flag == 0){
			int k = pop(&s) ;
		
		}
		
		
	}	
	
	
}







