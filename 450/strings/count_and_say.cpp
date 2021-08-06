#include<bits/stdc++.h>

using namespace std;

int main(){
	
	int n;
	cin >> n;
		
        vector<string>dp(30);
        dp[0] = "1";
        dp[1] = "11";
        dp[2] = "21";
        dp[3] = "1211";

        int count = 0 ; 
        string say = "";
        string psay;
        int j = 0 ; 
        
        if(n < 5){
        	cout << dp[n-1];
        	return 0;
        }
        for(int i = 4 ; i < n ; i++){
            
            say = "";
            psay = dp[i-1];
            while(j < psay.size()){
                char a = psay[j] ; 
                while(j < psay.size() and psay[j] == a ){
                    count++ ; 
                    j++ ; 
                }
                say = say + to_string(count) + a ; 
                count  = 0 ;
            }
            j = 0 ;
            dp[i] = say ; 
            cout << dp[i]<<endl;
        }
    	return 0;
};




