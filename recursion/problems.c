#include<stdio.h>
/*
void print(int );

void print(int a){
	if(a==1){                                  //stack upwards.
		printf("%d\n",a);
		return;
	}
	printf("%d\n",a);
	print(a-1);
	printf("%d\n",a);
	return ;
}



int main(){
	int n;
	scanf("%d",&n);
	//print(n);
	print(n);
	
}

*/

//how many binary strings of length n and no consucative 1's
void binary_strings(char **s,int n, int k);

//first check how many strings can be made.

int result=0;

void binary_strings(char **s, int n,int k){
	if(n==0){
		printf("%s\n",*s);
		result++;
		return ;
	}
	(*s)[n-1]=='0';
	binary_strings(s,n-1,k);
	if(n!=k && (*s)[n]==0){
	(*s)[n-1]==1;
	binary_strings(s,n-1,k);
	}
	return ;
}


int  main(){
	char* s;
	binary_strings(&s,2,2);
	printf("%d",result);
	
}

/*

//  given a,b. perform a^b;

long long int power(int , int );

long long int power(int a,int b){
	if(b==0) return 1;           //time complexity O(b) and space complexity O(b)
	return a*power(a,b-1);
}
long long int new_power(int,int);
long long int new_power(int a,int b){
	if(b==0) return 1;
	if(b==1) return a;
	int temp;
	temp=new_power(a,b/2);
	if(b%2==0){
		return (temp*temp);
	}
	else{
		return(temp*temp*a);
	}
	
}

int main(){
	printf("%lld",new_power(2,10));
}



//pattern printing usig recursion

void print(int ,int );
void print(int n,int i){
	if(n==0) return ;
	if(i<n){
		printf("*");
		print(n,i+1);
	}
	else{
		printf("\n");
		print(n-1,0);
	}
	return ;
}

void printi(int, int, int );

void printi(int k,int n,int i){
	if(n==k){return ;}
	if(i<n){
		printf("*");
		printi(k,n,i+1);
	}
	else{
		printf("\n");
		printi(k,n+1,0);
	}
	return;
}

int main(){
	printi(6,1,0);
}




*/























