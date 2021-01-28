#include"maze.h"
#include<stdio.h>
#include<stdlib.h>
//#include<conio.h>
#include<limits.h>
//#include"queue.h"

/*
void initMaze(maze *m, char *filename1) {
	int x;
	FILE *fp;
	int i, j;
	fp = fopen(filename1, "r");
	if(fp == NULL){
		printf("Unable to open file");    //our maze has the structure of an array and an integer.
		return;
	}
    fscanf(fp, "%d", &x);
        m->n = x;

	for(i = 0; i < x; i++)
		for(j = 0; j < x; j++)
			fscanf(fp, "%d", &(m->a[i][j]));  //in this init function , we have created a maze and filled up the array.
    return;
}
*/

// init function. in the init function, we will initialize the array and size of array from the structure maze. 

void initMaze(maze *m,char *filename1){
	int x;
	FILE* fp;   //file pointer.
	int i,j;
	fp=fopen(filename1,"r");
	if(fp==NULL){
		printf("unable to open\n");
		return ;
	}
	fscanf(fp,"%d",&x);       //assigning size .
	m->n=x;
	for(int i=0;i<x;i++){
		for(int j=0;j<x;j++){
			fscanf(fp,"%d",&(m->a[i][j]));   //creating array.
		}
	}
	return ;
}










void printMaze(maze *m){
    int i ,j;
    for(i = 0; i <m->n; i++){
        for(j = 0; j <m->n; j++)
            printf("%d  ", m->a[i][j]);
        printf("\n");
    }
    return;
}

/*void dothis(int s,int i, int j , maze *m,  queue *Qx, queue *Qy){
    if(i >= 0 && i <= s && j >= 0 && j <= s){
           if(m->a[i][j] == 0) {
                    enqueue(Qx,i);
                    enqueue(Qy,j);
                    m->a[i][j] = 2;
                                }

   }
   return;
}*/

/*void findPath(maze *m, int x1, int y1, int x2, int y2) {
     int  r, c;
     queue Qx;
     queue Qy;
     initQueue(&Qx);
     initQueue(&Qy);
     enqueue(&Qx,x1);
     enqueue(&Qy,y1);

     while(x1 != x2 && y1 != y2){
        if(!isQueueEmpty(Qx)){
            r = dequeue(&Qx);
            c = dequeue(&Qy);
        }
        else
            return;
        dothis(m->n,r,c+1,m,&Qx,&Qy);
        dothis(m->n,r + 1,c,m,&Qx,&Qy);
        dothis(m->n,r, c-1,m,&Qx,&Qy);
        dothis(m->n,r-1,c,m,&Qx,&Qy);
        }
     return;
    }


*/

/*
int findPath(maze *m, int x1, int y1, int x2, int y2) {
    if(!(x1 >= 0 && x1 < m->n && y1 >= 0 && y1 < m->n)){

        return 0;
    }
    if(x1 == x2 && y1 == y2){
            return 1;
    }

    if(m->a[x1][y1] == 1)
        return 0;


    m->a[x1][y1] = 2;
    if(findPath(m, x1,y1+1, x2, y2)) return 1;
    if(findPath(m, x1+1,y1, x2, y2)) return 1;
    if(findPath(m, x1,y1-1, x2, y2)) return 1;
    if(findPath(m, x1-1 ,y1, x2, y2)) return 1;
    m->a[x1][y1] = 0;
    return 0;

}
*/

int findPath(maze* m,int x1,int y1,int x2,int y2){ 
	if(!(x1 >= 0 && y1 >=0 && x1< m->n && y2< m->n)){   //boundry conditions checked.
		return 0;
	}
	if(x1==x2 && y1==y2){ 				      // success condition.
		return 1;
	}
	if(m->a[x1][y1]==1){     			      // wall condition.
		return 0;
	}
	
	//if current state is path then mark it as 2.
	m->a[x1][y1]=2;
	
	//now use backtraking.. and check in all directions.
	
	if(findPath(m,x1,y1+1,x2,y2)){return 1;}
	if(findPath(m,x1+1,y1,x2,y2)){return 1;}
	if(findPath(m,x1,y1-1,x2,y2)){return 1;}
	if(findPath(m,x1-1,y1,x2,y2)){return 1;}
	
	//if no conditions satisfy, dismark the position and return 0;
	m->a[x1][y1]=0;
	return 0 ;
}


void printPath(maze *m, int x1, int y1, int x2, int y2){
      int f = findPath(m, x1,  y1,  x2,  y2);
      if(f == 0){
        printf("NO PATH FOUND");
        return;
      }
      int i,j;
      for(i = 0; i < m->n; i++)
        for(j = 0; j < m->n; j++)
            if(m->a[i][j] == 2)
                printf("%d,%d\n", i, j);
      return;
}










