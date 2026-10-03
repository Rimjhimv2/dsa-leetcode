class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        
        vector<int>diff(52);
         for(auto range : ranges){
             
             int start = range[0];
             int end = range[1];

              diff[start]++;
              diff[end+1]--;
         }
       

        for(int i = 1; i<52;i++){
            diff[i]+= diff[i-1];

            
            
        }

        for(int i = left ; i<=right; i++){
            if(diff[i]== 0){
                return false;
            }
        }
        
        return true;
    }
};