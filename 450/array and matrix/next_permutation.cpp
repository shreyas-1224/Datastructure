#include<bits/stdc++.h>

#define loop(i , a , b) 		for(int i = a ; i < b ; i++)
#define ll 		long long int

using namespace std ;

int main(){
	
	int n ;
	cin >> n ;
	vector<int>combo(n) ;

	loop(i , 0 , n){
		cin >> combo[i] ;
	}
	
	int i = n- 1 , j = n-1;
	
	while(i >= 1 ){
		if(combo[i] > combo[i-1])
			break ;
		i-- ;
	}
	
	if(i == 0 ){
		sort(combo.begin() , combo.end());
	}
	 
	else{
		 i = i - 1 ;
		while(i < j){
			if(combo[j] > combo[i])
				break ;
			
			j-- ;
		}
		int temp = combo[i] ;
		combo[i] = combo[j] ;
		combo[j] = temp ;
		sort(combo.begin()+ i+1 , combo.end()) ;
	}
	
	loop(k , 0  , n){
		cout << combo[k] <<" ";
	}
		
}
