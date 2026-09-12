class Solution {
public:
int maxValue(vector<int>& nums){
    int maxi = INT_MIN;
    int n = nums.size();
    for(int i = 0 ; i<n ; i++){
        maxi = max(maxi,nums[i]);
    }
    return maxi;
}
int sumofD(vector<int>& nums, int k) {
    int sum = 0;

    for(int i = 0; i < nums.size(); i++) {
        sum += ceil((double)nums[i] / k);
    }

    return sum;
}
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = maxValue(nums);
        int ans = 0;
        while(low<=high){
            int mid = low + (high - low)/2;
            if(sumofD(nums,mid) <= threshold){
                ans = mid;
                high = mid-1;
            
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};