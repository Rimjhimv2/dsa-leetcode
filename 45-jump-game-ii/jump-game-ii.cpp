class Solution {
public:
    int jump(vector<int>& nums) {

        int jumps = 0;
        int currEnd = 0;
        int farthest = 0;

        // Last index tak loop nahi chalana
        for (int i = 0; i < nums.size() - 1; i++) {

            // Ab tak sabse door kaha tak pahunch sakte hain
            farthest = max(farthest, i + nums[i]);

            // Current jump ki boundary aa gayi
            if (i == currEnd) {

                jumps++;               // Nayi jump lo

                currEnd = farthest;    // Nayi boundary set karo
            }
        }

        return jumps;
    }
};
