class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {

        long long ans = 0;
        int prev = nums.back();

        for (int i = nums.size() - 2; i >= 0; i--) {

            if (nums[i] <= prev) {
                prev = nums[i];
            }
            else {
                int part = (nums[i] + prev - 1) / prev; // ceil(nums[i]/prev)
                ans += part - 1;
                prev = nums[i] / part;
            }
        }

        return ans;
    }
};
//tumhe kitni replacement karni padegi to make the sorted array 
//array non decreasung order mai hona chaiye 
//ager array sorted nahi hai toh usee like 1 2 10 4 here 10>4 split the 10 to make the array sorted.

