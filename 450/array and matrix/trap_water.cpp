// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends


class Solution{

    // Function to find the trapped water between the blocks.
    public:
    int trappingWater(int arr[], int n){
         vector<int>presum(n);
        vector<int>postsum(n);
        
        int max = arr[0];
     //	presum[0] = postsum[0] = 0;
     //	presum[n-1] = postsum[n-1] = 0;
     	
     	int water = 0 ;
     	
        for(int i = 1; i < n-1 ; i++){
        	
        	if(arr[i] > max){
        		max = arr[i];
        		presum[i] = 0;
		}        		
        	else{
        		presum[i] = max - arr[i];
        	}
        		
        }
        
        max = arr[n-1];
        
        for(int i =  n-2; i > 0 ; i--){
        	
        	if(arr[i] > max){
        		max = arr[i];
        		postsum[i] = 0;
		}        		
        	else{
        		postsum[i] = max - arr[i];
        	}
        		
        } 
        
        for(int i = 1 ; i < n-1 ; i++){
        	//if(presum[i] == postsum[i] and ( presum[i] == )
        //		continue ;
        	if(presum[i] < postsum[i])
        		water = water + presum[i] ;
        	else
        		water = water + postsum[i];
        }
        
       
        return water ;
    }
};

// { Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends
