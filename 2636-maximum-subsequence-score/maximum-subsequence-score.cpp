class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {

int n = nums1.size();

//ab hame pair bnana hai 
vector<pair<int,int>>v;
//ese mai pairs. store karne hai 

for(int i = 0 ; i< n ; i++){
    v.push_back({nums2[i],nums1[i]});
//ab sare pairs v mai aaaggye hai 
}

//sort karo  v ko 

sort(v.begin(),v.end(),greater<pair<int,int>>());


priority_queue<int,vector<int>,greater<int>>pq;

//min heap bnaliya hai '

long long sum = 0 ; 
long long ans =0 ; 
for(auto &it : v){
    sum += it.second;
    pq.push(it.second);

    if(pq.size()> k){
        sum-= pq.top();
        pq.pop();
    }

    if(pq.size() == k){
      ans = max(ans, sum * it.first);
    }
}


     return ans;
    }
};