
// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
#define loop(i , a, b)		for(int i = a; i < b ; i++)

using namespace std;


class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        
        vector<pair<int , int>>diff ; 
        int j = 0;
        
        loop(i , 0 , n){
        	
        	int m = arr[i] - k ;
        	if(m >= 0)
        		diff.push_back(make_pair(m , i));
        	
        	diff.push_back(make_pair(arr[i] + k , i));
        	
        }        	
   
        sort(diff.begin() , diff.end() );
        
        
        int element = 0 ; 
        vector<int>elements(n,0);
        
        int left = 0, right = 0 ;
        
        while(element != n ){
        	
        	elements[diff[right].second] ++ ;
        	if(elements[diff[right].second] == 1){
        		element ++ ;
        	//	cout << diff[right].second << " ";
        		
        	}
        	right ++ ;
        	if(right == n){
        		right -- ; 
        		break ;
        	}
        	
        }
       
        int minimum = INT_MAX ;

        while(right < diff.size()){
        	
        	if(element == n){
        		
        		minimum = min(minimum , diff[right].first - diff[left].first);
        		
        		if(elements[diff[left].second] == 1)
        			element = element - 1 ;
        		elements[diff[left].second]-- ;
        		left ++ ;
        	}
        
        	else{
        		while(element != n ){
        			right ++ ;
        			if(right == diff.size()){ 
        				break ;
        			} 
        			elements[diff[right].second] ++ ;
        			if(elements[diff[right].second] == 1)
        				element ++ ;
        			
        			
        		}
        	}
        }
        
        return minimum ; 
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends
