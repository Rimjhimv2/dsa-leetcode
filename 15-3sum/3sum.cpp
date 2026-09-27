class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        int n = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++) {

            // Duplicate i skip
            if(i > 0 && nums[i] == nums[i - 1])
                continue;

            int left = i + 1;
            int right = n - 1;

            while(left < right) {

                int sum = nums[i] + nums[left] + nums[right];

                if(sum < 0) {
                    left++;
                }
                else if(sum > 0) {
                    right--;
                }
                else {
                    ans.push_back({
                        nums[i],
                        nums[left],
                        nums[right]
                    });

                    left++;
                    right--;

                    // Duplicate left skip
                    while(left < right && nums[left] == nums[left - 1]) {
                        left++;
                    }

                    // Duplicate right skip
                    while(left < right && nums[right] == nums[right + 1]) {
                        right--;
                    }
                }
            }
        }

        return ans;
    }
};


//  class Solution {
//  public:
//      vector<vector<int>> threeSum(vector<int>& nums) {
//         set<vector<int>>st;
        

//         int n = nums.size();
//         for(int i = 0 ; i <n ; i++){
//             set<int>hashset;
//             for(int j = i+1; j<n ; j++){


//                 //ab 2 number aagya ab hame 3 no find karna 

//                 int third = -(nums[i] + nums[j]);
//                 //ab third number aagya ab check kro kya hashset mai presen hia ya nhi 

//                 if(hashset.find(third)!=hashset.end()){
//                     vector<int>temp = {nums[i], nums[j], third};

//                     sort(temp.begin(),temp.end());
//                     st.insert(temp);

//                 }
//                 hashset.insert(nums[j]);
//             }
//         }

// vector<vector<int>>ans(st.begin(),st.end());

// return ans;
//               //jab jab i increment hoga tab tab 
//           }
//  };
