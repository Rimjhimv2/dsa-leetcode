class Solution {
public:
    int missingInteger(vector<int>& nums) {
        
        int n = nums.size();
        
        // Step 1: Find longest sequential prefix sum
        int sum = nums[0];
        
        for(int i = 1; i < n; i++) {
            if(nums[i] == nums[i-1] + 1) {
                sum += nums[i];
            } else {
                break;
            }
        }
        
        // Step 2: Store all elements in set for fast lookup
        unordered_set<int> st(nums.begin(), nums.end());
        
        // Step 3: Find smallest missing integer >= sum
        while(st.count(sum)) {
            sum++;
        }
        
        return sum;
    }
};