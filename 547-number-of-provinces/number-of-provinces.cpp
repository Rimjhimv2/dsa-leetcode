
class Solution {
public:

    void bfs(unordered_map<int, vector<int>> &adj, int u, vector<bool>& visited) {
        
        queue<int>q;
        q.push(u);
        visited[u]=1;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(int i =0;i<adj[u].size();i++){
                int v = adj[curr][i];
                if(!visited[v]){
                    bfs(adj,v,visited);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        // graph (adjacency list) banao
        unordered_map<int, vector<int>> adj;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                }
            }
        }

        vector<bool> visited(n, false);
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                bfs(adj, i, visited); // poora ek province cover
                count++;              // province count
            }
        }

        return count;
    }
};
