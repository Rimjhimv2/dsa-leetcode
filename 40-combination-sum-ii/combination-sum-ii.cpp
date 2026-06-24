class Solution {
public:
    void solve(vector<int>& candidates, int target,
               vector<int>& curr, int idx,
               vector<vector<int>>& result) {

        // Base case
        if (target == 0) {
            result.push_back(curr);
            return;
        }

        for (int i = idx; i < candidates.size(); i++) {

            // Skip duplicates
            if (i > idx && candidates[i] == candidates[i - 1])
                continue;

            // Since array is sorted
            if (candidates[i] > target)
                break;

            // Choose
            curr.push_back(candidates[i]);

            // Move to next index because one element can be used only once
            solve(candidates, target - candidates[i],
                  curr, i + 1, result);

            // Backtrack
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        vector<vector<int>> result;
        vector<int> curr;

        sort(candidates.begin(), candidates.end());

        solve(candidates, target, curr, 0, result);

        return result;
    }
};