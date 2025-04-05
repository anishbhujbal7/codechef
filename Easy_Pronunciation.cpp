#include <bits/stdc++.h>
using namespace std;

bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

void solve() {
    int n;
    string s;
    cin >> n >> s;

    int consonantCount = 0;
    for (int i = 0; i < n; i++) {
        if (!isVowel(s[i])) {
            consonantCount++;
            if (consonantCount == 4) {
                cout << "NO" << endl;
                return;
            }
        } else {
            consonantCount = 0;
        }
    }
    cout << "YES" << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
