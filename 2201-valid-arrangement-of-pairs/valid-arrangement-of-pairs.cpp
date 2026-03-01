class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int,vector<int>>adj;

        unordered_map<int,int>indegree, outdegree;

        for(int i = 0;i<pairs.size();i++){
            int u = pairs[i][0];
            int v = pairs[i][1];

            adj[u].push_back(v);  //.u->v
            outdegree[u]++;
            indegree[v]++;

        }

        int startnode = pairs[0][0];
        for(auto it = adj.begin(); it!=adj.end();it++){
           int node = it->first;
            if(outdegree[node]-indegree[node] == 1){
            startnode = node;
            break;
            }
        }


        //simply do the khandani dfs 

        vector<int>path;
        stack<int>st;
        st.push(startnode);
        //main loop 
        while(!st.empty()){
            int curr = st.top();
            if(!adj[curr].empty()){
                int ngbr = adj[curr].back();
                adj[curr].pop_back();
                st.push(ngbr);
                

            }
            else {
    path.push_back(curr);
    st.pop();
}
        }
         // Build your result
        reverse(path.begin(), path.end());
        vector<vector<int>> result;
        for (int i = 0; i < path.size() - 1; i++) {
            result.push_back({path[i], path[i + 1]});
        }

        return result;

    }
};