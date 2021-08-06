// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:
   
    void swap(int*a , int*b){
        int temp = *a ;
        *a = *b ;
        *b = temp ;
        
    }
	void merge(int arr1[], int arr2[], int n, int m) {
	    // code hereit 
	    int gap ;
        if((n+m) % 2 == 0)
            gap = (n+m)/2 ;
        else
            gap = (n+m)/2 + 1 ;
            
        int l = 0 , r = gap;
        
        while(gap){
            
            while(l < n and r < n){
                
                if(arr1[l] > arr1[r]){
                    swap(&arr1[l],&arr1[r]);
                }
                l++ ;
                r++ ;
            }
            
            r = r - n ;
            while(l < n and r < m ){
                if(arr1[l] > arr2[r]){
                    swap(&arr1[l],&arr2[r]);
                }
                l++ ;
                r++ ;
                
            }
            
            l = l - n ;
             while(l < m and r < m ){
                if(arr2[l] > arr2[r]){
                    swap(&arr2[l],&arr2[r]);
                }
                l++ ;
                r++ ;
                
            }
            
            if((gap % 2) == 0)
                gap = gap/2 ;
            else{
                if(gap != 1)
                    gap = gap/2 + 1 ;
                else
                    return ;
            }
            l = 0 ;
            r = gap ;
            
         //   return;
            
            
        }
	}
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, i;
        cin >> n >> m;
        int arr1[n], arr2[m];
        for (i = 0; i < n; i++) {
            cin >> arr1[i];
        }
        for (i = 0; i < m; i++) {
            cin >> arr2[i];
        }
        Solution ob;
        ob.merge(arr1, arr2, n, m);
        for (i = 0; i < n; i++) {
            cout << arr1[i] << " ";
        }
        for (i = 0; i < m; i++) {
            cout << arr2[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends
