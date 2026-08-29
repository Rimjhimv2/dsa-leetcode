class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {

        int n = nums.size();

        // value + original index
        vector<pair<int, int>> arr;

        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }

        // Sort according to value
        sort(arr.begin(), arr.end());

        vector<int> ans(n);

        int start = 0;

        while (start < n) {

            int end = start;

            // Find one connected group
            while (end + 1 < n &&
                   arr[end + 1].first - arr[end].first <= limit) {
                end++;
            }

            // Collect original indices
            vector<int> indices;

            for (int i = start; i <= end; i++) {
                indices.push_back(arr[i].second);
            }

            // Original indices ko sort karo
            sort(indices.begin(), indices.end());

            // Smallest values -> smallest indices
            int k = start;

            for (int idx : indices) {
                ans[idx] = arr[k].first;
                k++;
            }

            start = end + 1;
        }

        return ans;
    }
};