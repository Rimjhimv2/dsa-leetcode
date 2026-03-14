

//ye dfs approch hai

// class Solution {
// public:
// //////ab yaha dfs call kro
//    void dfs(vector<vector<int>>& rooms,int source,vector<bool>&visited){
//     ////////sabse phle source ko mark karlo
//     visited[source ]= true;
//     ///////ab for loop lagao

//     for(int j = 0; j<rooms[source].size();j++){
//         int node= rooms[source][j];
//         if(!visited[node]){
//             ///////dfs call akro
//             dfs(rooms,node,visited);
//         }

//     }
//    }
//     bool canVisitAllRooms(vector<vector<int>>& rooms) {
//         ///////room ka size nikalo 
//         int n = rooms.size();
//         ///////ab ek visited array banao
//         vector<bool>visited(n,false);
//         ///////ab dfs call kro
//         dfs(rooms,0,visited);
//         //////ab pure room mai dekho koi ek single room khali toh nahi hai 
//         for(int i =0;i<n;i++){
//             if(!visited[i]){
//                 return false;
//             }
//         }
//         return true;
//     }
// };



//ab 2nd approch bfs

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        //room ka size nikal lo 
        int n = rooms.size();
        //visited array bnao

        vector<int>visited(n,false);
        queue<int>que;
        que.push(0);
        visited[0]=true;
        while(!que.empty()){
            int curr = que.front();
            que.pop();
            for(int i =0;i<rooms[curr].size();i++){

              int it = rooms[curr][i];
              if(!visited[it]){
                visited[it]=true;
                que.push(it);
              }
            }

        }
        for(int i = 0 ; i<n ;i++){
            if(!visited[i]){
                return false;
            }
        }
return true;


    }
};