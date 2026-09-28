class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();

        vector<int>ans;
        for(int i = 0 ; i< n ; i++){
            bool found = false;
            for(int j = 0 ; j < ans.size(); j++){
                if(ans[j] == nums[i]){
                    found = true;
                    break;
                }
                
            }
            if(!found){
                
                    ans.push_back(nums[i]);
              
            }

            // Put unique elements back into nums
        for(int i = 0; i < ans.size(); i++) {
            nums[i] = ans[i];
        }
        }
        return ans.size();
    }
};