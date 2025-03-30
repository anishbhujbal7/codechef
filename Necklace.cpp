#include <bits/stdc++.h>
using namespace std;

void kRotation(int n, int k, vector<int>& arr) {
    int r = k % n; // Effective number of left rotations
    if (r == 0) { // No rotation needed
        for (int num : arr) cout << num << " ";
        cout << endl;
        return;
    }

    vector<int> temp(arr.begin() + r, arr.end()); // Take elements from index r to end
    temp.insert(temp.end(), arr.begin(), arr.begin() + r); // Append first r elements

    // Print the rotated array
    for (int num : temp) cout << num << " ";
    cout << endl;
}

int main() {
    int t;
    cin >> t; // Number of test cases
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];

        kRotation(n, k, arr);
    }
    return 0;
}
