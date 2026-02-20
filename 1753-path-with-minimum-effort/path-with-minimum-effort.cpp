class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        
        vector<vector<int>> result(m, vector<int>(n, INT_MAX));
        
        priority_queue<
            pair<int, pair<int,int>>, 
            vector<pair<int, pair<int,int>>>, 
            greater<pair<int, pair<int,int>>>
        > pq;
        
        result[0][0] = 0;
        pq.push({0, {0, 0}});
        
        vector<vector<int>> dirs = {{0,1},{1,0},{0,-1},{-1,0}};
        
        auto isSafe = [&](int x, int y) {
            return x >= 0 && x < m && y >= 0 && y < n;
        };
        
        while(!pq.empty()) {
            int diff = pq.top().first;
            auto coord = pq.top().second;
            pq.pop();
            
            int x = coord.first;
            int y = coord.second;
            
            if(x == m-1 && y == n-1)
                return diff;
            
            for(auto &dir : dirs) {
                int x_ = x + dir[0];
                int y_ = y + dir[1];
                
                if(isSafe(x_, y_)) {
                    int absDiff = abs(heights[x][y] - heights[x_][y_]);
                    int maxDiff = max(diff, absDiff);
                    
                    if(result[x_][y_] > maxDiff) {
                        result[x_][y_] = maxDiff;
                        pq.push({maxDiff, {x_, y_}});
                    }
                }
            }
        }
        
        return 0;
    }
};