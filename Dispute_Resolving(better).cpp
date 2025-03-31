#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp; // Memoization table

// Recursive function to check if substring s[l...r] is a palindrome
bool isPalindrome(int l, int r, string &s) {
    if (l >= r) return true;  // Base case: Single character or empty string is palindrome

    if (dp[l][r] != -1) return dp[l][r]; // Use stored result if available

    if (s[l] == s[r]) 
        return dp[l][r] = isPalindrome(l + 1, r - 1, s); // Check inner substring
    else 
        return dp[l][r] = 0; // Not a palindrome
}

// Function to find longest palindromic substring length
int longestPalindromicSubstring(int n, string &s) {
    if (n == 1) return 1;
    
    dp.assign(n, vector<int>(n, -1)); // Initialize DP table

    int maxLength = 1;
    
    // Check all substrings
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (isPalindrome(i, j, s)) {
                maxLength = max(maxLength, j - i + 1);
            }
        }
    }

    return maxLength;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << longestPalindromicSubstring(n, s) << endl;
    }
    return 0;
}
