#include <bits/stdc++.h>
using namespace std;

int minTimeToInvadeAll(vector<vector<char>>& grid){
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> visited(n,vector<bool>(m,false));
    queue<pair<int,pair<int,int>>> q; 
    
    
     int totalEnemies = 0;

    // Directions: up, down, left, right
    vector<pair<int, int>> adjList = {{-1,0}, {1,0}, {0,-1}, {0,1}};

    // Step 1: Initialize the queue with all 'A' cells
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'A') {
                q.push({0,{i, j}});
                visited[i][j] = true;
            } else if (grid[i][j] == 'E') {
                totalEnemies++;
            }
        }
    }
    if (totalEnemies == 0) return 0; // nothing to invade
    int invaded=0;
    int maxTime=0;
    while(!q.empty()){
        int t=q.front().first;
        int row=q.front().second.first;
        int col = q.front().second.second;
        maxTime=max(t,maxTime);
        for(auto [r,c]:adjList){
            int newRow = row+r;
            int newCol=col+c;
            if(newRow<n&&newCol<m&&newCol>=0&&newRow>=0&& !visited[newRow][newCol]&&grid[newRow][newCol] != '*'){
                if(grid[newRow][newCol]=='E'){
                    invaded++;
                    grid[newRow][newCol]='A';
                }
                q.push({t+1,{newRow,newCol}});
                visited[newRow][newCol] = true;
            }
        }
    }
   if (invaded == totalEnemies) return maxTime;
    return -1;
    
}

int main() {
    vector<vector<char>> grid = {
        {'A', 'E', '*'},
        {'*', 'E', 'E'},
        {'*', '*', 'E'}
    };

    cout << minTimeToInvadeAll(grid) << endl;  // Output: 4 (for example)
}

