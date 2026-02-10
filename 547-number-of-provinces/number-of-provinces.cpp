// class Solution {
// public:
// void dfs(unordered_map<int,vector<int>> &adj, int u, vector<bool>& visited){

//     visited[u]=1;//phle node visited hoti hai
//     for(int i =0;i<adj[u].size();i++){ //check for neighbour
//         int v = adj[u][i];//padhosi
//         if(!visited[v]){//visited hai ya nhi 
//             dfs(adj,v,visited); // dfs padhosi se apply krenge 
//         }

//     }

// }
//     int findCircleNum(vector<vector<int>>& isConnected) {
//        int n = isConnected.size() ;

//        //ek yaha unorederd graph bna 

//        unordered_map<int,vector<int>>adj);
//         for(int i =0;i<n;i++){
//             for(int j =0;j<n;j++){
//                 if(isConnected[i][j]==1){
//                     adj[i].push_back(j);
//                     adj[j].push_back(i);
//                 }
//             }
//         }


//         //ab graph bn gya 
//         vector<int>visited(n,false);
//         int count =0;
//         for(int i =0;i<n;i++){
//             if(!visited[i]){
//                 dfs(i,adj,visited);
//             }
//             count++;
//         }

//        }
//        return count;
//     }
// };
class Solution {
public:

    void dfs(unordered_map<int, vector<int>> &adj, int u, vector<bool>& visited) {
        visited[u] = true;  // pehle node ko visited mark karo

        for (int i = 0; i < adj[u].size(); i++) {  // neighbours check
            int v = adj[u][i];  // padosi city
            if (!visited[v]) { // agar visit nahi hui
                dfs(adj, v, visited);
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
                dfs(adj, i, visited); // poora ek province cover
                count++;              // province count
            }
        }

        return count;
    }
};
