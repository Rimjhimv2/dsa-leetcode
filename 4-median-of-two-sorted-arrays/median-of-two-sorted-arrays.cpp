class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int i = 0;
        int j = 0;

        int n1 = nums1.size();
        int n2 = nums2.size();
        int n = n1 + n2;

        vector<int> arr;

        while(i < n1 && j < n2) {

            if(nums1[i] < nums2[j]) {
                arr.push_back(nums1[i]);
                i++;
            }
            else {
                arr.push_back(nums2[j]);
                j++;
            }
        }

        while(i < n1) {
            arr.push_back(nums1[i]);
            i++;
        }

        while(j < n2) {
            arr.push_back(nums2[j]);
            j++;
        }

        if(n % 2 == 1) {
            return arr[n / 2];
        }
        else {
            return (arr[n / 2 - 1] + arr[n / 2]) / 2.0;
        }
    }
};