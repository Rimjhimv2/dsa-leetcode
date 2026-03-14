// class Solution {
// public:


//  bool dfs(unordered_map<int,vector<int>>&mp,int s,int d,vector<bool>&visited){

//             if(s == d){
//                 return true;
//             }
//             if(visited[s]==true){
//                 return false;
//             }
//             //agar visited nahi hai toh visit mark karo
//             visited[s]=true;
//             for(int j=0;j<mp[s].size();j++){
//                 int it = mp[s][j];
//                 if (dfs(mp,it,d,visited)){
//                     return true;
//                 }
//             }
//             return false;
//         }
//     bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
       

//         ///adjacency list banao
//         unordered_map<int,vector<int>>mp; 
//         for(int i =0;i<edges.size();i++){
//             int u = edges[i][0];
//             int v = edges[i][1];
//             mp[u].push_back(v);
//             mp[v].push_back(u);
//            ////visited array bnao check karne ke liye ki vo abhi mark toh nahii hua

           

//         }
//         vector<bool>visited(n,false);
//            return dfs(mp,source,destination,visited);
//     }
// };

//es ques m bola hai ki source se desyination koi path hai ya nahi toh ham ye bfs or dfs se solve karte hai 
//2nd point ==== graph bidirectional hai toh ham u se v or v se u pahuch sakte 
//3rd point adjacency list bnao...agar source se destination pahuch gaye toh true otherwise false
//visited array ki bhi need hai 

///////////////////////2nd method
class Solution {
public:
 bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
unordered_map<int,vector<int>>mp; 
       for(int i =0;i<edges.size();i++){
           int u = edges[i][0];
             int v = edges[i][1];
            mp[u].push_back(v);
            mp[v].push_back(u);
//            ////visited array bnao check karne ke liye ki vo abhi mark toh nahii hua
}
        vector<bool>visited(n,false);
        queue<int>que;
        //ab queue mai source ko push karo
        que.push(source);
        //ab use visited mark karo
        visited[source]=true;


        while(!que.empty()){

            //yaha se hamne ek edge nikal li 
        int node = que.front();
        que.pop();
/////check most imp check remeber 
       if(node == destination){;
        return true;
       }
        for(int i = 0; i<mp[node].size();i++){
            int it = mp[node][i];
            //ab hamne nei mai check kar liye toh  ab ham visited mark karenge an dqueue mai push karenge phle check akenge ki vo visited mark hai ya nahi


            if(!visited[it]){
                visited[it]=true;
                que.push(it);
            }
        }
        }
        return false;
    }
 };
