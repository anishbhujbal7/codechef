#include <bits/stdc++.h>
using namespace std;

int minMoves(vector<int> &dp, int n) {
    if (n <= 1) return 0;
    if (dp[n] != -1) return dp[n];

    int res1 = 1 + minMoves(dp, n - 1);
    int res2 = 1 + minMoves(dp, n - (n / 2));      // reduce half
    int res3 = 1 + minMoves(dp, n - (2 * n / 3));  // reduce two-thirds

    dp[n] = min({res1, res2, res3});
    return dp[n];
}

int main() {
    int n = 5;
    vector<int> dp(n + 1, -1);
    cout << minMoves(dp, n) << endl;
    return 0;
}
