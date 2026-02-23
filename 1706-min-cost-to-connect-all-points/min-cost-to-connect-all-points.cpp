class Solution {
public:

    int PrimsAlgo(vector<vector<pair<int,int>>> &adj, int V) {
        
        typedef pair<int,int> P;
        priority_queue<P, vector<P>, greater<P>> pq;
        vector<bool> inMST(V, false);
        
        pq.push({0,0});
        int sum = 0;

        while(!pq.empty()){
           
            auto p = pq.top();
            pq.pop();

            int wt = p.first;
            int node = p.second;
            
            if(inMST[node]) continue;

            inMST[node] = true;
            sum += wt;
            
            for(auto temp : adj[node]){
                int neighbor = temp.first;
                int weight = temp.second;

                if(!inMST[neighbor]){
                    pq.push({weight, neighbor});
                }
            }
        }
        return sum;
    }


    int minCostConnectPoints(vector<vector<int>>& points) {

        int V = points.size();
        typedef pair<int,int> P;

        vector<vector<P>> adj(V);

        for(int i = 0; i < V; i++){
            for(int j = i+1; j < V; j++){

                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];

                int dist = abs(x1-x2) + abs(y1-y2);

                adj[i].push_back({j, dist});
                adj[j].push_back({i, dist});
            }
        }

        return PrimsAlgo(adj, V);
    }
};