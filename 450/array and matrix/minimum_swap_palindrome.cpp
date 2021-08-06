#include<iostream>
#include<bits/stdc++.h>
#define loop(i , a, b)		for(int i = a ; i < b ; i++)

using namespace std ; 

int main(){
	
	int n ; 
	cin >> n ;
	vector<int>arr(n,0);
	
	loop(i , 0 , n){
		cin >> arr[i];	
	}
	
	int left = 0 ; 
	int right = n-1 ; 
	int count = 0 ;
	 
	while(left < right){
		
		if(arr[left] == arr[right]){
			left++ ;
			right-- ;
		}
		else{
			arr[left + 1] = arr[left] + arr[left + 1];
			arr[right - 1] = arr[right] + arr[right - 1];
			right-- ;
			count ++ ;
		}
		
	}

	cout << count ;
}
