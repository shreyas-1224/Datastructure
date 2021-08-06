#include<bits/stdc++.h>

using namespace std ;

int minJumps(int arr[], int n){
        if(arr[0] == 0)
            return -1 ;
        vector<int >dp (n , INT_MAX);
        dp[0] = 0;
        dp[1] = 1;
        
        int k ;
        for(int i = 1 ; i < n ; i++){
            k = arr[i] + i ;
            dp[i] = dp[i-1] + 1;
            if(k > n-1)
            	dp[n-1] = min(dp[n-1] , dp[i] + 1);
            
            else
            	dp[k] = min (dp[k] , dp[i] + 1)
        }
        
        return dp[n-1];
               
}

int main(){
	int arr[11] ={1 ,3 ,5 ,8 ,9 ,2 ,6 ,7, 6, 8, 9};
	cout << minJumps(arr , 11);
}
