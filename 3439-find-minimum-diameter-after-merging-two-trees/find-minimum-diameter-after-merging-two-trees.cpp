class Solution {
public:

    unordered_map<int, vector<int>> buildAdj(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;

        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return adj;
    }

    int bfs(int start, unordered_map<int, vector<int>>& adj, int &farthest) {
        queue<int> q;
        unordered_set<int> visited;

        q.push(start);
        visited.insert(start);

        int dist = -1;

        while(!q.empty()) {
            int size = q.size();
            dist++;

            while(size--) {
                int node = q.front();
                q.pop();
                farthest = node;

                for(int i = 0; i < adj[node].size(); i++) {
                    int nei = adj[node][i];

                    if(!visited.count(nei)) {
                        visited.insert(nei);
                        q.push(nei);
                    }
                }
            }
        }

        return dist;
    }

    int findDiameter(unordered_map<int, vector<int>>& adj) {

        if(adj.empty()) return 0;   // ⭐ important fix

        int farthest = adj.begin()->first;

        bfs(farthest, adj, farthest);

        return bfs(farthest, adj, farthest);
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {

        auto adj1 = buildAdj(edges1);
        auto adj2 = buildAdj(edges2);

        int d1 = findDiameter(adj1);
        int d2 = findDiameter(adj2);

        int combined = (d1 + 1)/2 + (d2 + 1)/2 + 1;

        return max({d1, d2, combined});
    }
};