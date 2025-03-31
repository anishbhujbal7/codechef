#include <bits/stdc++.h>
using namespace std;

bool checkPalindrome(int p, int q, string &str){
    while(q>p){
        if (str[p]!=str[q]) return false;
        p++;
        q--;
    }
    return true;
}


int DisputeResolver(int n, string &str){
    if(n==1) return 1;
    int maxLen=1;
    int j=0;
    for(int i=0;i<n;i++){
        // if (i+j>n) return maxLen;
        for (int j=i+maxLen;j<n;j++){
            int currLen=j-i+1;
            if(checkPalindrome(i,j,str)){
                maxLen=max(maxLen,currLen);
            }
        }
    }
    return maxLen;
}



int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string str;
        cin>>str;
        int result=DisputeResolver(n,str);
        cout<<result<<endl;
    }
    return 0;

}
