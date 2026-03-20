class Solution {
public:
    int dfs(int node, int parent, vector<vector<pair<int,int>>> &adj) {
        int changes = 0;
        
        for (auto &it : adj[node]) {
            int neighbor = it.first;
            int needsReversal = it.second;
            
            if (neighbor == parent) continue;
            
            changes += needsReversal;
            changes += dfs(neighbor, node, adj);
        }
        
        return changes;
    }
    
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>> adj(n);
        
        for (auto &edge : connections) {
            int u = edge[0];
            int v = edge[1];
            
            adj[u].push_back({v, 1}); // needs reversal
            adj[v].push_back({u, 0}); // already correct
        }
        
        return dfs(0, -1, adj);
    }
};