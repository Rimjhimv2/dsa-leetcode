
//imp points to be remembber 
//. Core Idea of  Boyre-Moore’s Voting Algorithm

//Maintain:

//maj → potential majority candidate

//count → frequency counter

//If count becomes 0, choose a new candidate.

//If current element equals candidate → increment count

////Otherwise → decrement count

//👉 The logic works because the majority element cannot be completely canceled out by other elements.

// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//      int n = nums.size();
//      int count= 0;
//      int maj = NULL;
//      for(int i = 0;i<n;i++){
//         if(count == 0 ){
//             count = 1;
//             maj = nums[i];
//         }
//         else if(nums[i]==maj){
//             count++;
//         }
//         else{
//             count--;
//         }
//      }
//      return maj;
//     }
// };




// //ye optimal solution hai 
// //We traverse the array once using a single loop.

// //Each element is processed in O(1) time.

// //👉 Overall Time Complexity = O(n)

class Solution {
public:
    int majorityElement(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        int freq = 1;
        int maxFreq = 1;
        int ans = nums[0];

        for(int i = 1; i < nums.size(); i++) {

            if(nums[i] == nums[i-1]) {
                freq++;
            } else {
                freq = 1;
            }

            if(freq > maxFreq) {
                maxFreq = freq;
                ans = nums[i];
            }
        }

        return ans;
    }
};