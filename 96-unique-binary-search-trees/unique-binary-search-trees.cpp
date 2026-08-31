class Solution {
public:

    int dp[20][20];

    int solve(int start, int end) {

        // No nodes
        if (start > end) {
            return 1;
        }

        // Already calculated
        if (dp[start][end] != -1) {
            return dp[start][end];
        }

        int count = 0;

        // Har node ko root bana ke dekho
        for (int i = start; i <= end; i++) {

            int left_bst = solve(start, i - 1);
            int right_bst = solve(i + 1, end);

            count += left_bst * right_bst;
        }

        return dp[start][end] = count;
    }

    int numTrees(int n) {

        memset(dp, -1, sizeof(dp));

        return solve(1, n);
    }
};