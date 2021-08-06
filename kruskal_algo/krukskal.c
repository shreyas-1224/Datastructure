#include<stdio.h>
#include<stdlib.h>
#include <limits.h>
#include "kruskal.h"



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


int find_parent(int i , int* parent){
	
	if(parent[i] == i )
		return i ;
	else 
		return find_parent(parent[i],parent);
}

void kruskal(graph g){

	
	int visited[g.n] ;
	int source , dest ;
	
	int parent[g.n];
	
	for(int i = 0 ; i < g.n ; i++){
		parent[i] = i ;
		//visited[i]= 0 ;
	}
	
	int min , count = 0;
	for(int i = 0 ; i < g.n ; i++){
		
		if(count == g.n - 1) 	break ;
		min = INT_MAX ;
		for(int j = 0 ; j < g.n ; j++){
			
			if(g.a[i][j] != 0  && ( find_parent(i , parent) != find_parent(j , parent) ) ){
				if(min > g.a[i][j]){
					//printf("%d",i);
					source = i ; 
					dest = j ;
					min = g.a[i][j];	
				}
			}
			
			
		}	
		printf("%d---%d , %d\n" , source , dest , min) ;
		//visited[dest] = 1 ;
		count ++ ;
		parent[source] = dest ;
	}	
	
}
















