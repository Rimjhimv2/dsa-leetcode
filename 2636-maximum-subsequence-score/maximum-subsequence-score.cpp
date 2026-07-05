class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {

        int n = nums1.size();

        vector<pair<int,int>> v;

        // {nums2, nums1}
        for(int i=0;i<n;i++)
            v.push_back({nums2[i], nums1[i]});

        // Sort according to nums2 descending
        sort(v.begin(), v.end(), greater<pair<int,int>>());

        priority_queue<int, vector<int>, greater<int>> pq;

        long long sum = 0;
        long long ans = 0;

        for(auto &it : v){

            sum += it.second;
            pq.push(it.second);

            if(pq.size() > k){
                sum -= pq.top();
                pq.pop();
            }

            if(pq.size() == k){
                ans = max(ans, sum * 1LL * it.first);
            }
        }

        return ans;
    }
};