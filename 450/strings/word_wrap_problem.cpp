#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

    int solveWordWrap(vector<int>nums, int k) { 
       
       
    } 
};


int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
	}
	return 0;
}
