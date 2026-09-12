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
int sumArray(vector<int>& nums){
    int n = nums.size();
    int sum = 0;
      for(int i = 0 ; i<n ; i++){
         sum+= nums[i];

      }
return sum;
    
}
int calculate(vector<int>& nums,int capacity){
int day = 1;
int load = 0;
int n = nums.size();
//day 1 hai or tk load kuch nhi hua hai 
for ( int i = 0 ; i< n ; i++){

  if((load + nums[i])>capacity){
        day++;
        //i will go to yhe next day 
        load = nums[i];
        //ab loading next element se hogi

    }
    else{
        load += nums[i];
    }
}
  
    return day;
    
}

    int shipWithinDays(vector<int>& nums, int days) {
        int low = maxValue(nums);
        int high = sumArray(nums);
        int n = nums.size();
        int ans = 0 ;
        while(low<= high){

            int mid = low+(high - low)/2;
             if(calculate(nums,mid)<=days){
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