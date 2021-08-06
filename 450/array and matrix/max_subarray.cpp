// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends

class Solution{
    
        public :    
        long long int maxProduct(int* arr , int n){
        
        long long int maxproduct = 1 ;
        long long int minproduct = 1 ;
        long long int cproduct = 1 ;
        
        for(long long int i = 0 ; i < n ; i++){
            
            if(arr[i] > 0){
                
                cproduct = cproduct * arr[i] ;
               // minproduct = min (minproduct * arr[i] , 1 ) ;
                if(minproduct * arr[i] < 1)
                    minproduct = minproduct * arr[i];
                
                else
                    minproduct = 1 ;
                
            }
            
            else if(arr[i] == 0){
                cproduct = 1 ;
                minproduct = 1 ;
            }
            
            else{
                
                long long int temp = cproduct ;
                //cproduct = max(minproduct* arr[i] , 1);
                 if(minproduct * arr[i] > 1)
                    cproduct = minproduct * arr[i];
                
                else
                    cproduct = 1 ;
                    
                minproduct = temp* arr[i] ;
            
                
            }
            
            maxproduct = max(maxproduct , cproduct) ; 
        }
        return maxproduct ;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends








/* more effiecient code is 


// C++ program to find maximum product subarray
#include <bits/stdc++.h>
using namespace std;

// Function to find maximum product subarray
int maxProduct(int* arr, int n)
{
    // Variables to store maximum and minimum
    // product till ith index.
    int minVal = arr[0];
    int maxVal = arr[0];

    int maxProduct = arr[0];

    for (int i = 1; i < n; i++) {

        // When multiplied by -ve number,
        // maxVal becomes minVal
        // and minVal becomes maxVal.
        if (arr[i] < 0)
            swap(maxVal, minVal);

        // maxVal and minVal stores the
        // product of subarray ending at arr[i].
        maxVal = max(arr[i], maxVal * arr[i]);
        minVal = min(arr[i], minVal * arr[i]);

        // Max Product of array.
        maxProduct = max(maxProduct, maxVal);
    }

    // Return maximum product found in array.
    return maxProduct;
}

// Driver Code
int main()
{
    int arr[] = { -1, -3, -10, 0, 60 };

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Maximum Subarray product is "
         << maxProduct(arr, n) << endl;

    return 0;
}

*/

