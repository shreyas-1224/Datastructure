// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template ; for C++

class Solution {
public:
    vector<int> factorial(int N){
        vector<int>fact ;
        
        fact.push_back(2);
        fact.push_back(4);
        //fact.push_back(0);
        
        for(int i = 5 ; i <= N ; i++){
        	
        	int carry = 0 ;
        	int product =  1 ;
        	int j = fact.size() - 1 ;
        	
        	while(j >= 0){
        		
        		product = fact[j] * i + carry ;
        		fact[j] = ( product % 10 );
        		carry = product / 10 ;
        		j-- ;
        	}
        	
        	while(carry){
        		auto it = fact.insert(fact.begin() , carry%10);
        		carry = carry / 10 ;
        	}
        	
        }
        
        return fact ;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i){
            cout<< result[i];
        }
        
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends
