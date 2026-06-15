class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {

        int m = matrix.size();
        int n = matrix[0].size();

        int ans = 0;

        for(int startCol = 0; startCol < n; startCol++) {

            vector<int> rowSum(m, 0);

            for(int endCol = startCol; endCol < n; endCol++) {

                for(int row = 0; row < m; row++) {
                    rowSum[row] += matrix[row][endCol];
                }

                unordered_map<int,int> mp;
                mp[0] = 1;

                int prefixSum = 0;

                for(int row = 0; row < m; row++) {

                    prefixSum += rowSum[row];

                    if(mp.find(prefixSum - target) != mp.end()) {
                        ans += mp[prefixSum - target];
                    }

                    mp[prefixSum]++;
                }
            }
        }

        return ans;
    }
};