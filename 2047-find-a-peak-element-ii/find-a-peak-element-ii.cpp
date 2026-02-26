class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        
        int m = mat.size();
        int n = mat[0].size();
        
        int low = 0;
        int high = n - 1;
        
        while (low <= high) {
            
            int mid = low + (high - low) / 2;
            
            // Step 1: Find max element row in mid column
            int maxRow = 0;
            for (int i = 0; i < m; i++) {
                if (mat[i][mid] > mat[maxRow][mid]) {
                    maxRow = i;
                }
            }
            
            // Step 2: Check neighbors
            int left  = (mid - 1 >= 0) ? mat[maxRow][mid - 1] : -1;
            int right = (mid + 1 < n) ? mat[maxRow][mid + 1] : -1;
            
            // Step 3: Check if peak
            if (mat[maxRow][mid] > left && mat[maxRow][mid] > right) {
                return {maxRow, mid};
            }
            
            else if (right > mat[maxRow][mid]) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        
        return {-1, -1};
    }
};