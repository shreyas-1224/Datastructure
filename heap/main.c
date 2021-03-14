#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include "heap.h"

int main(int argc , char **argv){
	
    heap h;
    
    FILE * fp;
    fp=fopen(argv[1],"r+");
    
    if(fp==NULL){
    	printf("unable to open ");
    	return 0;
    }
    
    int a,c;
   // fscanf(fp,"%d ",&a);
    //sinit_heap(&h,a);
    int i = 0;

    while(fscanf(fp,"%d",&c)!=EOF){	
	
	i++ ;
    }
    
    fclose(fp);
    
    //___________________________
    
    FILE * fpp;
    fpp=fopen(argv[1],"r+");
    
    if(fpp == NULL)
    	{
    		printf("unable to open ");
    		return 0;
    	}
    
    
    init_heap(&h,i);
    i = 0;

    while(fscanf(fp,"%d",&c)!=EOF){	
	
	i++;
	insert_heap(&h , c);
    }
    
    //___________________________
    
    int j ;
    
    for(j = 0;j < i ; j++){
    	
    	delete_heap(&h);
    
    }

    fclose(fpp);
    
    
    for(int i = 0 ; i< j+1 ;i++){
    	delete_heap(&h);
   }
   h.rear = h.size - 1 ;
   traverse_heap(h);
  
   
   

}
