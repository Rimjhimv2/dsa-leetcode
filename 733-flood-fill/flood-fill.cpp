class Solution {
public:

void dfs(vector<vector<int>>& image, int row, int col,
             int oldColor, int newColor) {


       int m = image.size();
       int n = image[0].size();


       if(row<0 || row>=m || col< 0 ||col>=n){
        return;
       }

       if(image[row][col] != oldColor){
 return;
       }

         // Current cell ko new color se paint karo
        image[row][col] = newColor;

        // 4 directions
        dfs(image, row + 1, col, oldColor, newColor); // Down
        dfs(image, row - 1, col, oldColor, newColor); // Up
        dfs(image, row, col + 1, oldColor, newColor); // Right
        dfs(image, row, col - 1, oldColor, newColor); // Left
             }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int oldColor = image[sr][sc];//1

        if(oldColor == color){
            return image;
            //matlab kuch change nahi hoga
        }

   dfs(image, sr, sc, oldColor, color);
 return image;
 

    }
};