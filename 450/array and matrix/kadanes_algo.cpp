#include<bits/stdc++.h>

#define loop( i , a , b)	 	for(int i = a ; i < b ; i++)

using namespace std ;

int main(){
	
	int n ;
	cin >> n ;
	int a[n] ;
	
	loop(i , 0 , n)
		cin >> a[i];
	
	
	//  we will track  , current max , max , and curret min ; 
	// current max will always be greater than = 1 , current min will always be smaller than = 1 ;
	
	int c_min = 1 ;
	int c_max = 1 ;
	int max_prod = 0 ;
	
	loop(i , 0 , n){
	
		// if number is +ve ; take product with c_max ;
		if(a[i] > 0){
		
			c_max = c_max * a[i] ;
			c_min = min(c_min * a[i] , 1);
		}
		
		else if(a[i] == 0){
		
			c_min = 1 ;
			c_max = 1 ;
		}
		
		else{
			// if given number is -ve ;
			int temp = c_max ;
			c_max = max(c_min * a[i] , 1) ;
			c_min = temp * a[i] ;
		
		}
		
		if(max_prod < c_max){
			cout << max_prod << endl ;
			max_prod = c_max ;
		}	
	}
	
	
	cout << max_prod ;
}
