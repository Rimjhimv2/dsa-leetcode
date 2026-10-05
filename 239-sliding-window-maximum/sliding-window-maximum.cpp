class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        int n = nums.size();
        deque<int>dq;
        vector<int>ans;

        for(int i = 0 ; i< n ; i++){
            ///window se bahar wale element ko remove karo 

            while(!dq.empty() && dq.front() <= i-k){
                dq.pop_front();
            }

            //ab chote element ko remove karo 
            // 2. Chhote elements ko remove karo
            while(!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }

            //ab current element ko dalo 

            dq.push_back(i);

             // 4. Window complete ho gayi
            if(i >= k-1) {
                ans.push_back(nums[dq.front()]);
            }
        }
             return ans;
    }
};