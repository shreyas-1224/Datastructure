// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    
    
    int findLongestConseqSubseq(int arr[], int N)
    
    {
    
      int max = 0 ;
      map<int , int>hash ;
      
      for(int i = 0 ; i < N ; i++){
      		
      		hash[arr[i]] = hash[arr[i] - 1] + 1 ;
      		max = max < hash[arr[i]] ? hash[arr[i]] : max ;
      		if(hash[arr[i] + 1] != 0){
      			
      			hash[arr[i] + 1] = hash[arr[i]] + 1 ;
      			max = max < hash[arr[i]] ? hash[arr[i]] : max ;
      		}
      }
      
      return max ;
    
    }
};

// { Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}  // } Driver Code Ends
