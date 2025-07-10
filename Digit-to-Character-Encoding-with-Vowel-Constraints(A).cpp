#include <bits/stdc++.h>



using namespace std;

string solve(int n){
    set<int> set ={'a'-'a','e'-'a','i'-'a','o'-'a','u'-'a'};
    unordered_map<int,int> map;
    string str="";
    int cons=1;
    while(n>0){
        int currNo=n%10;
        if(map.find(currNo)!=map.end()){
            str+=map[currNo]+'a';
        }
        else if(currNo==2||currNo==3||currNo==5||currNo==7){
            int smallestVowel=*set.begin();
            set.erase(smallestVowel);
            map[currNo]=smallestVowel;
            str+=map[currNo]+'a';
        }
        else{
            while(set.count(cons)) cons++;
            map[currNo] = cons;
            str+=cons+'a';
            cons++;
        }
        n=n/10;
    }
    reverse(str.begin(),str.end());
    return str;
}


int main() {
    // your code goes here
    int n;
    cin>>n;
    cout << solve(n) << endl;
    return 0;

}
