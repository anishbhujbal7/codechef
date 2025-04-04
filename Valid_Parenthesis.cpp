#include <bits/stdc++.h>
using namespace std;

int validCheck(string &str){
    stack<int> st;
    for(int i=0;i<str.length();i++){
        if(str[i]==')' && st.empty()) return 0;
        if (str[i]==')') st.pop();
        if (str[i]=='(') st.push(str[i]);
        
    }
    if(st.empty()) return 1;
    else return 0;
}

int main() {
	int t; 
	cin>>t;
	while(t--){
	    string str;
	    cin>>str;
	    int result=validCheck(str);
	    cout<<result<<endl;
	}

}
