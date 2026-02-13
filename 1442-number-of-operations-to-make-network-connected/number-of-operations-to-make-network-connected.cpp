class Solution {
public:
    vector<int> parent;
    vector<int> rank;

   
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    
    bool Union(int x, int y) {
        int parent_x = find(x);
        int parent_y = find(y);

        if (parent_x == parent_y)
            return false;  // already connected

        if (rank[parent_x] > rank[parent_y]) {
            parent[parent_y] = parent_x;
        } else if (rank[parent_x] < rank[parent_y]) {
            parent[parent_x] = parent_y;
        } else {
            parent[parent_y] = parent_x;
            rank[parent_x]++;
        }

        return true;  // union done
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
     
        if (connections.size() < n - 1) return -1;

        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        int components = n;

        for (auto &vec : connections) {
            if (Union(vec[0], vec[1])) {
                components--;  // two components merged
            }
        }

        return components - 1;  // minimum operations needed
    }
};