class Solution {
public:
    string reorganizeString(string s) {
        
unordered_map<char, int> mp;



for (int i = 0; i < s.length(); i++) {
    mp[s[i]]++;
}

priority_queue<pair<int,char>>pq;
//max heap hia ye 
for(auto &it : mp){
    pq.push({it.second,it.first});
}

string ans = "";
while(pq.size()>1){
    auto first = pq.top();
    pq.pop();


    auto second = pq.top();
    pq.pop();

   ans += first.second;
            ans += second.second;

            first.first--;
            second.first--;

            if(first.first>0){
                pq.push(first);
            }

            if (second.first > 0)
                pq.push(second);
}

// Last character (if any)
        if (!pq.empty()) {

            if (pq.top().first > 1)
                return "";

            ans += pq.top().second;
        }

        return ans;



    }
};