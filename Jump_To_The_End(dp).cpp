#include <bits/stdc++.h>
using namespace std;


int maxJump(int i,int n,vector<int>& arr, vector<int>& dp){
    if (i==n-1) return dp[i]=0;
    if(arr[i]==0) return dp[i]=-1e9;
    if (dp[i]!=-1) return dp[i];
    int totalJumps=-1e9;
    for(int j=1;j<=arr[i];j++){
       if(i+j<n){
           totalJumps=max(totalJumps,1+maxJump(i+j,n,arr,dp));
       }
       
    }
    return dp[i] = (totalJumps == -1e9 ? -1 : totalJumps);

}



int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> arr(n);
	    vector<int> dp(n,-1);
	    for(int i=0;i<n;i++){
	        
	        cin>>arr[i];
	        
	    }
	    int result=maxJump(0,n,arr,dp);
        cout << (result >= 0 ? result : -1) << "\n";

	}

}
