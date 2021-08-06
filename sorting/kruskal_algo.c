#include<stdio.h>
#include<stdlib.h>
#include "kruskal_algo.h"

void g_init(graph *g, char* name){
	
	FILE* fptr ;
	
	fptr = fopen(name , "r");
	if(fptr == NULL)	return ;
	
	fscanf(fptr,"%d",&(g->n));
	
	g->a = (int **)malloc(sizeof(int *) * g->n );
	
	for(int i = 0 ; i < g->n ; i++){
		g->a[i] = (int *)malloc(sizeof(int ) * g->n );
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


void quicksort(struct node *a,int first,int last){
	if(first<last){
		int p = partition(a,first,last);
		quicksort(a,0,p-1);

		quicksort(a,p+1,last);
	}
}

int partition(struct node* a,int first,int last){
	int i=first;
	int j=last;
	int pivot=a[first].weight;
	
	while(i<j)
	{
	
		while(a[i].weight <= pivot && i < last){
			i++;
		}
		
		while(a[j].weight > pivot){
			j--;
		}
		
		if(i<j){
			// swapping the structure at i and j position .
			struct node temp = a[i] ;
			a[i] = a[j] ; 
			a[j] = a[i] ; 
		}
	}
	
	a[first] = a[j];
	a[j].weight = pivot;
	return j;
	
}



int find_parent( int i , int* parent){
	
	if(parent[i] == i)
		return i ;
	return find_parent(parent[i] , parent );

}


void kruskal_algo( graph g ){

	int e = 0 ;
//	struct node array[18] ;
	// fill the array with structs . 
	/*
	for(int i = 0 ; i < g.n ; i++){
		
		for(int j = 0 ; j < g.n ; j++){
			if (g.a[i][j] != 0){
				array[e].source = i ;
				array[e].dest = j ;
				array[e].weight = g.a[i][j] ;
				e++ ; 
				
			}
			
		}
	
	}
	
	*/
	
	int number[] = {23 , 32 , 43 ,92, 58, 293, 1 , -34 ,54 , 23 , 89 , 3 ,2 ,54, 232, 43, 92, 11 , 9 , 20 };
	struct node array[20] ;
	
	for(int i =0 ; i < 20 ; i++){
		array[i].source = i ;
		array[i].dest = 20 - i;
		array[i].weight = number[i];
	}	
	
	

	quicksort(array , 0 , 19 );
	for(int i = 0 ; i < 20 ; i++){
		printf("%d--%d , %d\n", array[i].source , array[i].dest , array[i].weight );
	} 
	return ;
	int i = 0;
	int parent[g.n] ;
	for(int i =0 ; i < g.n ; i++){
		parent[i] = i ;
	}
	
	/*
	while(e --){
		if(find_parent(input[i].source , parent ) != find_parent(input[i].dest , parent) ){
			//printf("%d---%d , %d\n",input[i].source , input[i].dest , input[i].weight);
			parent[input[i].source] = input[i].dest ;		// or vice-versa..do anyhthing .
		}
		
		i++ ;
	}
	
	 
	
*/

}





