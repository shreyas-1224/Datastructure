#include<stdio.h>
#include<stdlib.h>
#include<limits.h>


int partition(char a[],int,int);
void quicksort(char a[],int ,int );
void swap(char *a,char* b){
	char temp=*a;
	*a=*b;
	*b=temp;
}

void quicksort(char a[],int first,int last){
	if(first<last){
		int p=partition(a,first,last);
		quicksort(a,0,p-1);
		quicksort(a,p+1,last);
	}
}

int partition(char a[],int first,int last){
	int i=first;
	int j=last;
	int pivot=a[first];
	
	while(i<j)
	{
	
		while(a[i]<=pivot && i<last){
			i++;
		}
		
		while(a[j]>pivot){
			j--;
		}
		
		if(i<j){
			swap(&a[i],&a[j]);
		}
	}
	
	a[first]=a[j];
	a[j]=pivot;
	return j;
	
}



int main(){
	char ar[50];
	fgets(ar,sizeof(ar),stdin);
	char newar[50];
	int i=0,j=0;
	while(ar[i]!='\0'){
		if(ar[i]!=' '){
			newar[j]=ar[i];
			j++;
		}
		i++;

	}
	
	quicksort(newar,0,j-1);
	for(int i=0;i<20;i++){printf("%c ",newar[i]);}
}



