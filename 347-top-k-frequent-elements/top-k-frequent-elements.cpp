class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        

        //mp ki help se sare element ki frequency count karle bete 

        unordered_map<int,int>mp;
        //esme indexing nahi hoti 

        for(int i = 0 ; i< nums.size(); i++){
            mp[nums[i]]++;
        }

        ///heap mai store kar min heap bna or usme toh top element small hota toh jitna k manga jaye utna do baki remove pop karde

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        for(auto it: mp){

            int val = it.first;
            int freq= it.second;


//pq.push({freq,val});
//pq.push({freq,val});
//sabse important concept hai. Priority Queue hamesha pair ke first ko compare karti hai, isi liye frequency ko pehle rakhte hain.
        pq.push({freq,val});
            if(pq.size()> k ){
                pq.pop();
            }
        }

        vector<int>ans;

        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};