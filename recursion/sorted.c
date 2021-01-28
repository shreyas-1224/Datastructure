#include<stdio.h>

int  is_sorted(int *,int);

int  is_sorted(int a[],int n){
	if(n==1){
		return 1;
	}
	else{
		return (a[n-1]>a[n-2] ? is_sorted(a,n-1) : 0);
	}
}

int main(){
	int n[]={12,13,14,15,543,2345,4};
	int size=sizeof(n)/sizeof(n[0]);
	if(is_sorted(n,size)){
		printf("sorted");
		return 1;
	}
	else{printf("unsorted");}
}
