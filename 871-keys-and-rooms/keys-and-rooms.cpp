class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        int V = rooms.size();
        queue<int>q;
        vector<int>visited(V,0);


        q.push(0);
        visited[0] = 1;
        

        int count =1;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(int i = 0 ; i< rooms[node].size() ; i++){
                int neighbour = rooms[node][i];
                if(visited[neighbour]==0){
                    visited[neighbour]=1;
                    q.push(neighbour);
                    count++;
                }
            }
        }
        return count == V ;
    }
};