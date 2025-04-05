#include <bits/stdc++.h>
using namespace std;

vector<char> rpnform(string &str){
    vector<char> ans;
    stack<char>stChar;
    stack<char>stOpp;
    for(int i=0;i<str.size();i++){
        if(str[i]=='(') stChar.push(str[i]);
        else if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='^'||str[i]=='%'||str[i]=='/'){
            stOpp.push(str[i]);
        }
        else if(str[i]==')'){
            stChar.pop();
            char x=stOpp.top();
            ans.push_back(x);
            stOpp.pop();
        }
        else ans.push_back(str[i]);
    }
    return ans;
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    string str;
	    cin>>str;
	    std::vector<char>result=rpnform(str);
	    for(auto i:result){
	        cout<<i;
	    }
	    cout<<endl;
	}

}
