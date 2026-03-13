class Solution {
public:
void dfs(vector<vector<int>>& stones,int i , vector<bool>&visited){
    visited[i]=true;
    for(int j =0;j<stones.size();j++){
        if(visited[j]==true){
            continue;
        }
        if(stones[i][0]==stones[j][0]||
        stones[i][1]==stones[j][1]){
            dfs(stones,j,visited);
        }
    }
}
    int removeStones(vector<vector<int>>& stones) {
        
int n = stones.size();
vector<bool>visited(n,false);
int group = 0;
for(int i =0;i<n;i++){
    if(visited[i]==true){
        continue;
    }
    dfs(stones,i,visited);
    group++;
}
return n -group;


    }
};