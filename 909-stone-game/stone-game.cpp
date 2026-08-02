class Solution {
public:
    vector<vector<int>> dp;

    int solve(vector<int>& piles, int i, int j) {

        // Ek hi pile bachi
        if (i == j)
            return piles[i];

        if (dp[i][j] != -1)
            return dp[i][j];

        // Left pile uthao
        int takeLeft = piles[i] - solve(piles, i + 1, j);

        // Right pile uthao
        int takeRight = piles[j] - solve(piles, i, j - 1);

        // Jo better ho
        return dp[i][j] = max(takeLeft, takeRight);
    }

    bool stoneGame(vector<int>& piles) {

        int n = piles.size();

        dp.assign(n, vector<int>(n, -1));

        // Agar score difference positive hai,
        // to Alice jeetegi.
        return solve(piles, 0, n - 1) > 0;
    }
};