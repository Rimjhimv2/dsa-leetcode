// class Solution {
// public:
//     int subarraysDivByK(vector<int>& nums, int k) {
//         int n = nums.size();
//         int ans = 0;
//         for(int i = 0; i< n ; i++){
//             int sum =0;
//             for(int j = i ; j<n ; j++){
           
//               sum+=nums[j];
//               if(sum%k == 0){
//                 ans++;
//               }

//             }
//         }
//         return ans;
//     }
// };


 class Solution {
 public:
   int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>mp;
        mp[0]=1;
        int sum =0;
        int ans =0;

        for(int x : nums){
           sum+=x;

            int remainder = ((sum % k) + k) % k;
           //ager ye map mai already hai to simply add karo ye remainder 
           // agar remainder pehle aa chuka hai
            if(mp.find(remainder) != mp.end()) {
                ans += mp[remainder];
            }

//or ager nahi hai toh map mai ye remainder store karo 
           mp[remainder]++;
        }

         return ans;
          }
 };
