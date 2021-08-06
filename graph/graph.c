#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include "graph.h"
#include "stack.h"
#include "queue.h"


int find_parent(int i , int* parent){
	if(parent[i] == i)
		return i ;
	find_parent(parent[i] , parent);
}

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



void DFS(graph g , int u){
	
	/*
	//using recursion 
	visited[u] = 1 ;
	
	for(int i = 0 ; i < g.n ; i++){
		
		if(visited[i] != 1 && g.a[u][i] == 1){
			printf("%d--%d\n",u,i);
			DFS(g , i);
		}
	}*/
	
	int visited[g.n ] ;
	stack s ;
	init(&s , g.n);
	push(&s , u);
	visited[u] = 1 ;
	
	while(!isempty(s)){
	
		u = pop(&s) ;
		//visited[u] = 1 ;
		for(int i = 0 ; i < g.n ; i++){
			if(visited[i] != 1 && g.a[u][i]){
				push(&s ,i);
				visited[i] = 1 ;
			}
		}
		
		printf("%d-->",u);
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


/*
we cant really use this function to check the total number of cycles in the graph. but this work for both directed and undirected graph.
//(time complexity reason)

void is_cycle(graph g){
	
	int count = 0 ;
	int parent[g.n];
	int visited[g.n];
	
	for(int i = 0 ; i < g.n ; i++){
		parent[i] = i ;
		visited[i] = 0 ;
	}
	
	
	for(int i = 0 ; i < g.n ; i++){
	
		visited[i] = 1 ;
		for(int j = 0 ;  j < g.n ; j++){
			
			if(g.a[i][j]){
				if(visited[j] == 0 ){
					 if(parent[i] == parent[j])
						count ++ ;
				
					else
						parent[j] = i ;
				}
			}
		}
	}	
	
	printf("total count of cycle is : %d\n",count);

	
}
*/

// finding cycle in a directed graph using dfs .

void is_cycle(graph g){

	// we will use an visited array and dfs . 
	int count = 0, u ;
	
	int visited[g.n] ;
	
	for(int i = 0 ; i < g.n ; i++){
		visited[i] = 0 ;
	}
	stack s ;
	init(&s , g.n);
	
	//start from zero ;
	push(&s,0);
	
	while(! isempty(s)){
		
		u = pop(&s);
		visited[u] = 1 ;
		
		for(int i = 0 ; i < g.n ; i++){
			
			if(visited[i] == 0 && g.a[u][i])
				push(&s,i);
			
			else if(visited[i] == 1 && g.a[u][i]){
				//printf("reached");
				count++ ;
				push(&s, i);
			}
		}
	}
	
	printf("total number of cycles are : %d\n",count);
} 



int is_bipartite(graph g){
	
	int visited[g.n] ;
	for(int i = 0 ; i < g.n ; i++)
		visited[i] = 0 ;
	queue q ;
	q_init(&q,g.n);
	enqueue(&q , 0);
	visited[0] = 1 ;
	while(!(q_isempty(q))){
		
		int u = dequeue(&q);
		for(int i = 0 ; i < g.n ; i++){
			
			if(g.a[u][i] != 0 && (visited[u] == visited[i]))
				return 0 ;
				
			else if(visited[i] == 0 && g.a[u][i] != 0){
				visited[i] = ( visited[u] == 1 ) ? 2 : 1 ;
				enqueue(&q ,1);
			}
		}
	}
	return 1 ;
}









