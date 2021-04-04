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
	int visited[g->n];
	
	for(int i = 0 ; i < g->n ; i++){
		for(int j = 0 ; j < g->n ; j++){
			fscanf(fptr,"%d",&(g->a[i][j]));
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


void prims(graph g , int u){
	
	int visited[g.n] ;
	int parent[g.n] ; parent[u] = -1 ;
	int mst_key[g.n] ;
	int psudo_parent = 2 ;
	
	for(int i = 0 ; i < g.n ; i++){
		
		visited[i] = 0 ;
		mst_key[i] = INT_MAX ;
	} 
	mst_key[u] = 0 ;
	visited[u] = 1 ;

	for(int m = 0; m < g.n - 1; m++){
	
	
	//-------------------------assign values to the respective array mst_key-------------------
	
		for(int l =0; l < g.n ; l++){
		
			if(visited[l] != 1 && g.a[u][l] != 0){
				if(g.a[u][l] < mst_key[l]){
					mst_key[l] = g.a[u][l];
				
				}

			}
		
		}	
		
		
	//-------------------------finding minimum of that array ----------------------------------
	
		int min = INT_MAX , min_index = u ,j ; 
		for(j =0 ; j < g.n ; j++){
			if(min > mst_key[j] && visited[j] != 1){
				min  = mst_key[j];
				min_index = j ;
			}
		
		}
		
		visited[min_index] = 1 ;
		
				
		while(min != g.a[u][min_index]){
			
			if( (parent[u] != -1 ) && min == g.a[parent[u]][min_index]){
				psudo_parent = u ;
				u = parent[u] ;
				
			}
			
			else if (min == g.a[psudo_parent][min_index])	{
				psudo_parent = u ;
				u = psudo_parent ;
			}
			break;
			
		}
		
		parent[min_index] = u ;
		u = min_index ;
	} 
	
	// printing ;
	
	for(int i = 0 ; i < g.n ; i++){
		printf("%d--%d\n", parent[i],i);
	}
	
	
	
	
}




















