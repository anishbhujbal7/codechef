class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        merged.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {
            vector<int> last = merged.back(); // copy

            if (last[1] >= intervals[i][0]) {
                last[1] = max(last[1], intervals[i][1]); // modify copy
                merged.back() = last; // manually update the actual vector
            } else {
                merged.push_back(intervals[i]);
            }
        }
        return merged;
    }
};
