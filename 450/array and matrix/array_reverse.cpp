#include<bits/stdc++.h>

#define loop( i , a , b) 	for(int i = a ; i < b ; i++)

using namespace std ;


// recursion for reversing the array ; 

void reverse_array(vector<int> rev ,  int start , int end ){

    if (start >= end)
    	return;
     
    int temp = rev[start];
    rev[start] = rev[end];
    rev[end] = temp;
     
    // Recursive Function calling
    reverse_array(rev, start + 1, end - 1);
}

int main(){
	
	int  n;
	cin >> n ; 
	vector<int> rev(n); 
	
	loop( i , 0 , n){
	
		//int temp ;
		cin >> rev[i] ; 		
	}
	
	int start = 0 ;
	int end = rev.size() - 1;
	
	while(start < end){
		
		int temp = rev[start] ;
		rev[start] = rev[end] ;
		rev[end] = temp ;
		start++ ;
		end-- ;
	}
	loop( i , 0 , n){
		cout << rev[i] <<" " ;
	}
	reverse_array(rev , 0 , rev.size()-1) ;
	loop( i , 0 , n){
		cout << rev[i] <<" " ;
	}
	
	
	
}










