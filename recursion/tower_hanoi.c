#include<stdio.h>

void hanoi(int,char*,char*,char*);

void hanoi(int n,char *s,char* a,char* d){
	
	if(n==1){
		printf("move the disk 1 from %s to %s\n",s,d);
		return ;
	}
	hanoi(n-1,s,d,a);
	printf("move disk from %s to %s\n",s,d);
	hanoi(n-1,a,s,d);
	return ;
}

int main(){
	int n;
	printf("enter the number od disks\t");
	scanf("%d",&n);
	char s[10]="source";
	char a[10]="auxillary";
	char d[12]="destination";
	hanoi(n,s,a,d);
}

