#include <bits/stdc++.h>
using namespace std;

int findDistance(vector<int> &people, int x, int y){
    int n = people.size();
    vector<bool> visited(n,0);
    queue<pair<int,int>> q;
    q.push({x-1,0});
    visited[x-1]=true;
    int jumps =0;
    while(!q.empty()){
        auto[posi,j]=q.front();
        q.pop();
        jumps=max(jumps,j);
        if(posi==y-1) return jumps;
        int rightPosi=(posi+people[posi])%n;
        int leftPosi=(posi-people[posi]+n)%n;
        if (rightPosi>=0 && rightPosi<n && !visited[rightPosi]){
            q.push({rightPosi,j+1});
            visited[rightPosi]=true;
        }
        
        if (leftPosi>=0 && leftPosi<n && !visited[leftPosi]){
            q.push({leftPosi,j+1});
            visited[leftPosi]=true;
        }
    }
    return -1;
}

int main() {
    int n = 5;
    int x = 1;
    int y = 3;
    vector<int> people = {1, 2, 3, 1, 2};  // jump values for chairs 1 to 5

    int result = findDistance(people, x, y);

    if (result != -1)
        cout << "Minimum number of jumps: " << result << endl;
    else
        cout << "Target chair is unreachable." << endl;

    return 0;
}
