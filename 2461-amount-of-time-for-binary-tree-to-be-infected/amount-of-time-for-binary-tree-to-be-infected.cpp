/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    void makeGraph(unordered_map<int, vector<int>> &adj, int parent, TreeNode *root) {
        if (!root) return;

        if (parent != -1) {
            adj[root->val].push_back(parent);
            adj[parent].push_back(root->val);
        }

        makeGraph(adj, root->val, root->left);
        makeGraph(adj, root->val, root->right);
    }

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, vector<int>> adj;

        makeGraph(adj, -1, root);

        queue<int> que;
        unordered_set<int> visited;

        que.push(start);
        visited.insert(start);

        int time = -1;

        while (!que.empty()) {
            int size = que.size();
            time++;

            for (int i = 0; i < size; i++) {
                int curr = que.front();
                que.pop();

                for (auto &neighbour : adj[curr]) {
                    if (!visited.count(neighbour)) {
                        visited.insert(neighbour);
                        que.push(neighbour);
                    }
                }
            }
        }

        return time;
    }
};