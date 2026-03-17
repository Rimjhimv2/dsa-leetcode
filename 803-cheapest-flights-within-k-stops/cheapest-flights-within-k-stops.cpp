#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Build adjacency list: node -> {neighbor, cost}
        vector<vector<pair<int,int>>> adj(n);
        for (auto &f : flights) {
            adj[f[0]].push_back({f[1], f[2]});
        }

        // Distance array: minimum cost to reach each node
        vector<int> distance(n, INT_MAX);
        distance[src] = 0;

        // Queue: {current city, current cost}
        queue<pair<int,int>> que;
        que.push({src, 0});

        int steps = 0; // Number of edges traveled

        while (!que.empty() && steps <= k) {
            int N = que.size();
            vector<int> temp = distance; // temp array to prevent overwriting same level
            while (N--) {
                int u = que.front().first;
                int d = que.front().second;
                que.pop();

                for (auto &P : adj[u]) {
                    int v = P.first;
                    int cost = P.second;
                    if (d + cost < temp[v]) {
                        temp[v] = d + cost;
                        que.push({v, d + cost});
                    }
                }
            }
            distance = temp;
            steps++;
        }

        return distance[dst] == INT_MAX ? -1 : distance[dst];
    }
};