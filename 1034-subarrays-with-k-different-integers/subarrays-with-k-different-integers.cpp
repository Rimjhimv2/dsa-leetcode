class Solution {
public:

    int atMost(vector<int>& nums, int k) {

        unordered_map<int, int> mp;

        int left = 0;
        int count = 0;

        for (int right = 0; right < nums.size(); right++) {

            // Add current element
            mp[nums[right]]++;

            // If distinct elements > k
            while (mp.size() > k) {

                mp[nums[left]]--;

                // Remove element completely
                if (mp[nums[left]] == 0) {
                    mp.erase(nums[left]);
                }

                left++;
            }

            // Number of valid subarrays ending at right
            count += right - left + 1;
        }

        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {

        // Exactly K = At Most K - At Most (K - 1)
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};