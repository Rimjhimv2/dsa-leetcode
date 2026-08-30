class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minindex= 0;
        int maxindex = 0 ; 

        for(int i = 0 ; i<n;i++){
            if(nums[i] < nums[minindex])
            {minindex = i ;}

            if(nums[i] > nums[maxindex])
            {maxindex = i ;}
        }

        int left = min(minindex , maxindex);

        int right = max(minindex, maxindex);

        int bothfront = right + 1;
        int bothback = n - left ;

       int oneeach = (left + 1) + (n - right);

        return min({bothfront,bothback,oneeach});
    }
};