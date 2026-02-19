class Solution {
public:
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        vector<vector<int>> dir = {
            {-1,-1},{-1,0},{-1,1},
            {0,-1},        {0,1},
            {1,-1},{1,0},{1,1}
        };
        int m = grid.size();
        int n= grid[0].size();
        if(m==0 || n==0 || grid[0][0]!=0){
            return -1;
        }
        auto isSafe = [&](int x, int y){
    if(x >= 0 && x < m && y >= 0 && y < n)
        return true;
    return false;
};
        queue<pair<int,int>>que;
        que.push({0,0});
        grid[0][0]=1;
        
        int level=0;
        while(!que.empty()){
            int N= que.size();
        
        while(N--){
            auto vec= que.front();
            que.pop();
            int x= vec.first;
            int y = vec.second;
            if(x== m-1 && y==n-1)
                return level+1;
            for(int i=0;i<dir.size();i++){            int _x = x+dir[i][0];
            int _y = y+dir[i][1];
                                                     if(isSafe(_x,_y ) && grid[_x][_y]==0){
                                                         que.push({_x,_y});
                                                         grid[_x][_y]=1;
                                                     }
                
            }
            
        } 
            level++;
        }
        return -1;
    }
};