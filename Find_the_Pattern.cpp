#include <bits/stdc++.h>
using namespace std;


int findString(const string &s, const string &p){
    return s.find(p)!=string::npos;
}

int main() {
	int t;
	cin>> t;
	while(t--){
	    string s,p;
	    cin>>s>>p;
	    cout<<findString(s,p)<<endl;
	}
	
	return 0;

}
