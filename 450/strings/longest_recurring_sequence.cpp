// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		int LongestRepeatingSubsequence(string str){
		    
		    int n = str.size();
		    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
		    str = ' '+str;
		    
		    
		    for(int i = 1 ; i < n+1 ; i++){
		    	
		    	for(int j = i ; j < n+1 ; j++){
		    	
		    		if(str[i] == str[j] and i != j){
		    			dp[i][j] = 1 + dp[i-1][j-1];
		    		}
		    		else{
		    			dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
		    		}
		    	}
		    }
		    
		    
		    return dp[n][n];
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
