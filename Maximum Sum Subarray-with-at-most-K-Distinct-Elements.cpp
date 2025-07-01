int maxSumSubarrayWithKDistinct(vector<int>& A, int k) {
    unordered_map<int, int> freq;
    int n = A.size();
    int left = 0, right = 0;
    int maxSum = 0, currSum = 0;

    while (right < n) {
        freq[A[right]]++;
        currSum += A[right];

        // Shrink window if we exceed k distinct elements
        while (freq.size() > k) {
            freq[A[left]]--;
            currSum -= A[left];
            if (freq[A[left]] == 0) freq.erase(A[left]);
            left++;
        }

        // Update max sum
        maxSum = max(maxSum, currSum);
        right++;
    }

    return maxSum;
}
