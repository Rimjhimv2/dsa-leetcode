class Solution {
public:

    int m, n;
    int peri = 0;

    void dfs(vector<vector<int>>& grid, int i, int j) {

        // Agar grid ke bahar hain ya water mila
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) {
            peri++;
            return;
        }

        // Already visited
        if (grid[i][j] == -1) {
            return;
        }

        // Mark as visited
        grid[i][j] = -1;

        // Down
        dfs(grid, i + 1, j);

        // Up
        dfs(grid, i - 1, j);

        // Right
        dfs(grid, i, j + 1);

        // Left
        dfs(grid, i, j - 1);
    }

    int islandPerimeter(vector<vector<int>>& grid) {

        m = grid.size();
        n = grid[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                // Pehla land cell mil gaya
                if (grid[i][j] == 1) {
                    dfs(grid, i, j);
                    return peri;
                }
            }
        }

        return 0;
    }
};