class Solution {
public:

bool checkBiapartiteBFS(vector<vector<int>>&adj,int curr,vector<int>&color,int currColor){
    queue<int>q;
    q.push(curr);
    color[curr]=currColor;

    while(!q.empty()){
        int u = q.front();
        q.pop();
for(int j=0;j<adj[u].size();j++){
        int v = adj[u][j];

        if(color[v]==color[u]){
            return false;
        }
        else if(color[v]==-1){
            color[v]=1-color[u];
            q.push(v);
        }

}
    }
    return true;
}



    bool isBipartite(vector<vector<int>>& adj) {
        
        //graph kitne size ka hai uske acc nodes ka graph bnega
        int V = adj.size();
        //color vector bnaya
        vector<int>color(V,-1);
        for(int i =0;i<V;i++){
            if(color[i]==-1){
                if(checkBiapartiteBFS(adj,i,color,1)==false){
                    return false;
                }
            }
        }
        return true;
    }
};