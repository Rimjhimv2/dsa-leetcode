// class Solution {
// public:
//     vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        

//         int n = nums1.size();
//        vector<long long> ans(n);
//         for(int i = 0 ; i< n ; i++){
//             vector<int>temp;
//             for(int j = 0 ; j<n ; j++){
//                 if(nums1[j]< nums1[i]){
//                     temp.push_back(nums2[j]);
//                 }
//             }

//             sort(temp.begin(),temp.end(),greater<int>());

//             long long sum = 0 ; 
//             for (int x = 0; x < min(k, (int)temp.size()); x++) {
//     sum += temp[x];
// } ans[i] = sum;
//         }
//         return ans;
//     }
// };


class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {

        int n = nums1.size();

        vector<pair<int,int>> arr;

        for(int i = 0; i < n; i++) {
            arr.push_back({nums1[i], i});
        }

        sort(arr.begin(), arr.end());

        vector<long long> ans(n);

        priority_queue<int, vector<int>, greater<int>> pq;

        long long sum = 0;

        int j = 0;

        for(int i = 0; i < n; ) {

            while(j < n && arr[j].first < arr[i].first) {

                int val = nums2[arr[j].second];

                pq.push(val);
                sum += val;

                if(pq.size() > k) {
                    sum -= pq.top();
                    pq.pop();
                }

                j++;
            }

            int t = i;

            while(t < n && arr[t].first == arr[i].first) {
                ans[arr[t].second] = sum;
                t++;
            }

            i = t;
        }

        return ans;
    }
};