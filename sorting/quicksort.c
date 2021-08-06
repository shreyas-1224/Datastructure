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
	printf("%c\n",a[j]);
	return j;
	
}



int main(){
	char ar[10] = {'v','a','r','j','c','z','w','p','g','u'} ;
	quicksort(ar , 0 , 9);
	for(int i = 0 ; i < 10 ; i++){
		printf("%c\t",ar[i]);
	}
}



