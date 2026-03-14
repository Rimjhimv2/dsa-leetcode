class Solution {
public:

bool dfs(vector<vector<int>>& adj, vector<int>& color, int node, int currColor){
    
    color[node] = currColor;

    for(int i = 0; i < adj[node].size(); i++){

        int neigh = adj[node][i];

        if(color[neigh] == currColor){
            return false;
        }

        if(color[neigh] == -1){

            int nextColor = 1 - currColor;

            if(!dfs(adj, color, neigh, nextColor)){
                return false;
            }
        }
    }

    return true;
}

bool possibleBipartition(int n, vector<vector<int>>& dislikes){

    vector<vector<int>> adj(n+1);

    for(int i = 0; i < dislikes.size(); i++){
        int u = dislikes[i][0];
        int v = dislikes[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> color(n+1, -1);

    for(int i = 1; i <= n; i++){

        if(color[i] == -1){

            if(!dfs(adj, color, i, 0)){
                return false;
            }
        }
    }

    return true;
}
};