class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        map<int,int>mp;
        for(int i = 0 ; i<n;i++){
            for(int j = 0 ; j< n ; j++){
                mp[grid[i][j]]++;
            }
        }

        int repeating = -1;
        int duplicating = -1;
        for(int num = 1 ; num<=n* n ; num++){
           if(mp[num]==2){
            repeating= num;
           }
           if(mp[num]==0){
            duplicating = num;
           }
        }

        return {repeating, duplicating};
    }
};