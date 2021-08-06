#include<iostream>

#define loop(i , a , b)	for(int i = a ; i < b ; i++)
#define ll 			long long

using namespace std ;

int main(){
	
	int n ; 
	cin >> n ;
	vector<int>arr(n) ;
	
	loop(i , 0 , k){
		cin >>arr[i] ;
	}
	//array is ready . logic is to apply kadanes algo but twice and also continue to measure second max with max ; 
	
	ll maxi = 0 ; 
	ll smax = 0 ;
	int mini = arr[0] ; 
	ll profit = 0 ;
	int temp = 0 ;
	
	loop(i , 1 , n){
		
		profit = arr[i] - mini ; 
		if(profit > maxi){
			temp = maxi ; 
			maxi = profit ; 
			smax = temp ;	
			int max_min = mini ; 
		}
		else if(smax < profit and max_min != mini){
			smax = profit ; 
		}
		
		if(arr[i] < mini)
			mini = arr[i];
				
	}
	
	cout << "max profit is : " << smax + maxi ;
}
