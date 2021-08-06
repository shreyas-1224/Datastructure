#include<bits/stdc++.h>

#define loop(i , a , b)	for(int i = a ; i < b ; i++)
#define ll 			long long int

using namespace std ;

int main(){
	int n ,k , tp; 
	ll max_area = INT_MIN;
	ll temp_area = 0 ; 
	
	cin >> n;
	vector<int>arr(n);
	
	loop(i , 0 , n){
		cin >> arr[i];
	}
	
	stack<int>st ; 
	
	k = 0 ;
	while(k < n){
		
		if(st.empty() or arr[k] > arr[st.top()]){
			st.push(k++);
		}
		else{
			tp = st.top();
			st.pop();
			temp_area = st.empty() ? arr[tp] * (k) : arr[tp] * (k-st.top()-1);
			max_area = temp_area > max_area ? temp_area : max_area;
			
		}
	}
	
	while(! st.empty()){
		
		tp = st.top();
		st.pop();
		temp_area = st.empty() ? arr[tp] * (k) : arr[tp] * (k-st.top()-1);
		max_area = temp_area > max_area ? temp_area : max_area;
		
	}
	cout << max_area ;
		 
} 



