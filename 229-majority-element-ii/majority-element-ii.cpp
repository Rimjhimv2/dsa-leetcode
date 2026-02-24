class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        

        int n = nums.size();
        int count1 = 0;
        int count2 = 0;

        int maj1 = 0, maj2 = 1; 

        for(int i =0;i<n;i++){
            if(maj1 == nums[i]){
               count1++;
              
            }
            else if(maj2 == nums[i]){
              count2++;
            }
            else if(count1==0){
              count1= 1;
               maj1 = nums[i];
            }
            else if(count2 == 0){
              count2 = 1;
              maj2= nums[i];
            }
            else{
              count1--;
              count2--;
            }
        }
        //verify karna hai 
        count1= 0;
         count2=0;
        for(int i =0;i<n;i++){
            if(maj1 == nums[i]){
                count1++;
            }
            else if(maj2 == nums[i]){
                count2++;
            }
        }
        vector<int>result;
        if(count1>n/3){
            result.push_back(maj1);
        }
        if(count2>n/3){
            result.push_back(maj2);
        }
        return result;
    }
};