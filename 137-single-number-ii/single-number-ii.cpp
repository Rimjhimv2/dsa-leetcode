class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int ans = 0;

        // Har 32 bits ko check karo
        for (int bit = 0; bit < 32; bit++) {

            int count = 0;

            // Har number ka current bit check karo
            for (int num : nums) {

                if (num & (1 << bit)) {
                    count++;
                }
            }

            // 3 baar wale numbers cancel ho jayenge
            if (count % 3 != 0) {
                ans = ans | (1 << bit);
            }
        }

        return ans;
    }
};