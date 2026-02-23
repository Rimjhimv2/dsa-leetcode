class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        int n = nums.size();
        //hamne map bnaya 
        unordered_map<int,int>mp;
        //0 ko initailze karo 
        mp[0]=-1;
        int sum = 0;
        //sum nikalo 
        //Har index pe total sum ka remainder nikal rahe.
        for(int i =0;i<n;i++){
          sum+= nums[i];
        
        // remainder kse nikalega mod nikalo with respect to k 
         int remainder = sum% k;
        //hamne sum toh nikal liya ab kya karna hai 
        //ab map mai check karna 
        //Agar remainder pehle mil chuka hai:
        if(mp.find(remainder) != mp.end()){
            //ab hamne pure map mai dekha 
            //hame mila toh ab ham current index nikalenge 
            if(i - mp[remainder]>= 2){
                return true;
            }
        }
        //yaha esle for loop se bahr likhenge becoz esko 1 hi baaar chalana hai 
            else{
                mp[remainder ]=i;
            }
        }
        
        return false;
    }
};