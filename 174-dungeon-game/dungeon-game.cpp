// class Solution {
// public:
//     int m, n;
//     unordered_map<string, bool> mp;

//     bool canSurvive(int i, int j, int health, vector<vector<int>>& dungeon) {

//         // out of bounds
//         if (i >= m || j >= n) return false;

//         // apply current cell
//         health += dungeon[i][j];

//         // died
//         if (health <= 0) return false;

//         // reached princess
//         if (i == m - 1 && j == n - 1) return true;

//         // memo key
//         string key = to_string(i) + "_" + to_string(j) + "_" + to_string(health);

//         if (mp.count(key)) return mp[key];

//         bool ans = canSurvive(i + 1, j, health, dungeon) ||
//                    canSurvive(i, j + 1, health, dungeon);

//         return mp[key] = ans;
//     }

//     int calculateMinimumHP(vector<vector<int>>& dungeon) {

//         m = dungeon.size();
//         n = dungeon[0].size();

//         int left = 1;
//         int right = 4 * 1e7;

//         int minHealth = right;

//         while (left <= right) {
//             int mid = left + (right - left) / 2;

//             mp.clear();

//             if (canSurvive(0, 0, mid, dungeon)) {
//                 minHealth = mid;
//                 right = mid - 1;
//             } else {
//                 left = mid + 1;
//             }
//         }

//         return minHealth;
//     }
// };
//Dungeon ek grid hai jisme:

//Negative number → damage (health kam hoti hai) 😈
//Positive number → health badhti hai 💚
//0 → kuch nahi
//🚶 Rules
//Sirf right ➡️ ya down ⬇️ move kar sakta hai
//Kabhi bhi health 0 ya negative hui → game over ❌
//👉 Starting mein minimum kitni health chahiye taki knight safely princess tak pahunch jaye.

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));

        // base case (princess cell)
        dp[m-1][n-1] = max(1, 1 - dungeon[m-1][n-1]);

        // last column
        for (int i = m - 2; i >= 0; i--) {
            dp[i][n-1] = max(1, dp[i+1][n-1] - dungeon[i][n-1]);
        }

        // last row
        for (int j = n - 2; j >= 0; j--) {
            dp[m-1][j] = max(1, dp[m-1][j+1] - dungeon[m-1][j]);
        }

        // rest of grid
        for (int i = m - 2; i >= 0; i--) {
            for (int j = n - 2; j >= 0; j--) {
                int need = min(dp[i+1][j], dp[i][j+1]);
                dp[i][j] = max(1, need - dungeon[i][j]);
            }
        }

        return dp[0][0];
    }
};