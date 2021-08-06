#include<bits/stdc++.h>

using namespace std;


class Solution {

  public:

    string longestPalin (string s) {
	 int n = s.size();
	 vector<vector<int>> dp( n , vector<int> (n, 0));
	 int start;
	 int end;	 
	 for(int i = 0 ; i < n - 1 ; i++){
	 	dp[i][i+1] = (s[i] == s[i+1]) ? 1 : 0 ;
	 	dp[i][i] = 1;	
	 }
	 dp[n-1][n-1] = 1 ;
	 
	// fill matrix wrt string and its next char.
	
	int p = 2 ;
	while(p < n){
		for(int i = 0 ; i < n ; i++){
			if(i+p >= n)
				break ; 
			if(s[i] == s[i+p]){
				if(dp[i+1][i+p-1] == 1)
					dp[i][i+p] = 1;
				else
					dp[i][i+p] = 0;
			}
			else
				dp[i][i+p] = 0;
		}
		p++;
	} 
	
	// end of filling
	
	
	 	
	 int maxi = 0 ; 
	 start = 0 ; 
	 end = 0;
	 int j ;
	 
	 for(int i = 0 ; i < n ; i++){
	 	for(j = n-1 ; j >= i ; j --){
	 		if(dp[i][j] == 1){
	 			break;
	 		}
	 	}
	 	if(abs(j - i) > maxi ){
	 		maxi = abs(j-i);
	 		if(i < j){
	 			start = i ; 
	 			end = j;
	 		}
	 		else{
	 			start = j ; 
	 			end = i;
	 		}
	 		
	 	}
	 }
	 string answer =  s.substr(start , maxi+1);
	 return answer;
	 
	 }   

};



int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
