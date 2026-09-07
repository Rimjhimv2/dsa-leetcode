class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;

        // Store non-zero elements
        for(int i = 0; i < n; i++) {
            if(nums[i] != 0) {
                temp.push_back(nums[i]);
            }
        }

        // Put non-zero elements back
        for(int i = 0; i < temp.size(); i++) {
            nums[i] = temp[i];
        }

        // Fill remaining positions with zero
        for(int i = temp.size(); i < n; i++) {
            nums[i] = 0;
        }
    }
};