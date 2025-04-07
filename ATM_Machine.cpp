#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,k;
	    cin>>n>>k;
	    vector<int> arr(n);
	    for(int i =0;i<n;i++){
	        cin>>arr[i];
	    }
	    vector<int> ans;
	    for(int i=0;i<n;i++){
	        if(k-arr[i]>=0){
	            ans.push_back(1);
	            k=k-arr[i];
	        }
	        else ans.push_back(0);
	    }
	    for(int i:ans){
	        cout<<i;
	    }
	    cout<<endl;
	}

}
