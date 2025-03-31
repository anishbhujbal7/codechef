#include <bits/stdc++.h>
using namespace std;

void stackSort(int n, vector<int>& arr) {
    vector<int> sortedArr = arr; // Create a sorted copy of arr
    sort(sortedArr.begin(), sortedArr.end()); // Sort the copied array
    stack<int> st;
    int j = 0; // Index for sortedArr

    for (int i = 0; i < n; i++) {
        st.push(arr[i]); // Push element into stack

        // While stack's top matches the expected sorted value
        while (!st.empty() && st.top() == sortedArr[j]) {
            st.pop();
            j++; // Move to the next sorted element
        }
    }

    // If the stack is empty, it means we successfully sorted the array
    if (st.empty()) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        stackSort(n, arr);
    }
    return 0;
}
