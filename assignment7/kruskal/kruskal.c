#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
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


int find_parent(int son , int* parent){
	
	if(parent[son] == son){
		return son ;
	}
	
	return find_parent(parent[son] , parent);
}




void kruskal(graph g){
	// get array filled with edges and weight ;
	
	struct node* array ;
	array = (struct node* )malloc(sizeof(struct node) * g.e);
	
	int count = 0 ;
	for(int  i = 0 ;i < g.n ; i++){
		for(int j = i ; j < g.n ; j++){
			
			if(g.a[i][j] != 0){
				array[count].source = i ;
				array[count].dest = j ;
				array[count].weight = g.a[i][j] ;
				array[count].visited = 0 ;
				count++ ;
			}
		}
	
	}
		
	int parent[g.n] ;
	
	for(int i = 0 ; i < g.n ; i++)
		parent[i] = i ;
		
	for(int i = 0 ; i < g.n ; i++)
		printf("%d ",parent[i]); 
	
	printf("\n");
	
	
	int min = INT_MAX ;
	int min_index = 0 ;
	
	for(int i = 0 ; i < g.n - 1  ; i++){
		printf("\n");
		min = INT_MAX ;
		for(int j = 0 ; j < g.e ; j++){
			
			if(  ( find_parent(array[j].source , parent ) != find_parent(array[j].dest , parent))){
				
				if(array[j].weight < min && ( array[j].visited == 0) ){
					min = array[j].weight ;
					min_index = j ;
				}
			}
		}
		
		printf("%d---%d , weight : %d\n",array[min_index].source , array[min_index].dest , array[min_index].weight);
		parent[array[min_index].source] = array[min_index].dest ;
		//printf("%d\n" , parent[array[min_index].dest]) ;
		array[min_index].visited = 1 ;
		for(int i = 0 ; i < g.n ; i++)
			printf("%d ",parent[i]);
	}



}






void swap (node* p1, node* p2) {
   node temp = *p1;
  *p1 = *p2;
  *p2 = temp;
}










int main(){
	
	graph g ;
	g_init(&g , "adj_matrix.txt");
	kruskal(g ) ;
	
}

