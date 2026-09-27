// class Solution {
// public:
//     vector<int> twoSum(vector<int>& numbers, int target) {
//         int left = 0;
//         int n = numbers.size();
//         int right = n-1;
//          while(left<right){
//             int sum = numbers[left]+ numbers[right];
//             if(sum > target){
//                 right--;
//             }
//             else if(sum < target){
//                 left++;
//             }
//             else{
//                 return { left+1, right+1};
//             }
//          }

//          return {};
//     }
// };

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();

        for (int i = 0; i < n; i++) {

            int left = 0;
            int right = n - 1;

            int needed = target - numbers[i];

            while (left <= right) {

                int mid = left + (right - left) / 2;

                if (numbers[mid] > needed) {
                    right = mid - 1;
                }
                else if (numbers[mid] < needed) {
                    left = mid + 1;
                }
                else {
                    if (mid != i) {
                        return {i + 1, mid + 1};
                    }

                    left = mid + 1;
                }
            }
        }

        return {};
    }
};