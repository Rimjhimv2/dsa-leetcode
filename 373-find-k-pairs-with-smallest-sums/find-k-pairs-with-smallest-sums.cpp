class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
typedef pair<int, pair<int, int>> p;

        priority_queue<p,vector<p>,greater<p>>pq;
vector<vector<int>> result;
        int m = nums1.size();
        int n = nums2.size();
        int sum = nums1[0]+nums2[0];
        set<pair<int,int>> visited;
        pq.push({sum,{0,0}});
        visited.insert({0,0});
        while(k-- && !pq.empty()){
            auto temp = pq.top();
pq.pop();

int i = temp.second.first;
int j = temp.second.second;
 result.push_back({nums1[i], nums2[j]});

 if(i+1 < m && visited.count({i+1,j}) == 0) {
    pq.push({nums1[i+1]+nums2[j], {i+1,j}});
    visited.insert({i+1,j});
}
// Right neighbour
if(j+1 < n && visited.count({i,j+1}) == 0) {
    pq.push({nums1[i] + nums2[j+1], {i,j+1}});
    visited.insert({i,j+1});
}



        }
return result;

    }
};