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
    int result = 0;

    void solve(TreeNode* root, vector<int>& count) {
        if (!root) return;

        // Step 1: include current node
        count[root->val]++;

        // Step 2: check if leaf
        if (root->left == NULL && root->right == NULL) {
            int oddFreq = 0;

            // count odd frequencies
            for (int i = 1; i <= 9; i++) {
                if (count[i] % 2 != 0) {
                    oddFreq++;
                }
            }

            // Step 3: check palindrome condition
            if (oddFreq <= 1) {
                result++;
            }
        }

        // Step 4: DFS
        solve(root->left, count);
        solve(root->right, count);

        // Step 5: backtrack
        count[root->val]--;
    }

    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> count(10, 0); // digits 1–9
        solve(root, count);
        return result;
    }
};