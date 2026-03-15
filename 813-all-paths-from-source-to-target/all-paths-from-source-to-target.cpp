class Solution {
public:

vector<vector<int>>ans;
    void dfs(int node,vector<int>&path,vector<vector<int>>& graph){
        path.push_back(node);
        if(node == graph.size()-1){
       ans.push_back(path);
            
        }
        else{
            for(int i =0;i<graph[node].size();i++){
                int curr=graph[node][i];
                dfs(curr,path,graph);
            }
        }
        path.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int>path;
        dfs(0,path,graph);
        return ans;
    }
};