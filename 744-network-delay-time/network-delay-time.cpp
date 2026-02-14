class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<pair<int,int>>> adj(n + 1);
        
        for(auto &t : times){
            int u = t[0];
            int v = t[1];
            int wt = t[2];
            
            adj[u].push_back({v, wt});
        }
        
        priority_queue<pair<int,int>, 
                      vector<pair<int,int>>, 
                      greater<pair<int,int>>> pq;

        vector<int> result(n+1, INT_MAX);

        result[k] = 0;
        pq.push({0, k});

        while(!pq.empty()){
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(d > result[node]) continue;

            for(auto &it : adj[node]){
                int adjNode = it.first;
                int wt = it.second;

                if(d + wt < result[adjNode]){
                    result[adjNode] = d + wt;
                    pq.push({result[adjNode], adjNode});
                }
            }
        }

        int ans = 0;

        for(int i = 1; i <= n; i++){
            if(result[i] == INT_MAX) return -1;
            ans = max(ans, result[i]);
        }

        return ans;
    }
};
