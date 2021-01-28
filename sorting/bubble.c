#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

void swap(int *a,int* b){
	int temp=*a;
	*a=*b;
	*b=temp;
}

void bubble(int a[],int n){
	
	for(int i=0;i<n;i++){
		int swap=0;
		for(int j=0;j<n-1;j++){
			if(a[j]>a[j+1]){
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				swap++;
			}
		}
		if(swap==0){return ;}
	}
	return ;

}


void insertion(int a[],int n){
	for(int j=1;j<n;j++){
		int key=a[j];
		int k=j;
		while(key<a[k-1] && k>0){
			int temp=a[k-1];
			a[k-1]=key;
			a[k]=temp;
			k--;
		}
	}
	return ;
}


void selection(int a[],int n){
	
	for(int i=0;i<n-1;i++){
		int min=i;
		for(int j=i+1;j<n;j++){
			if(a[j]<a[min]){min=j;}
		}
		/*int temp=a[i];
		a[i]=a[min];
		a[min]=temp;*/
		swap(&a[i],&a[min]);
		
	}
	
	return ;
}

int main(){
	int a[]={1,9,3,2,4,5,-45,2345,65,123,-9876,4567,23,72834,1,1,1,23,543,-23};
	selection(a,20);
	for(int i=0;i<20;i++){printf("%d ",a[i]);}
}
