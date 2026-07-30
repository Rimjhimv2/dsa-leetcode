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

    struct Info {
        bool isBST;
        int sum;
        int mini;
        int maxi;
    };

    int ans = 0;

    Info solve(TreeNode* root) {

        // Empty tree
        if (root == NULL) {
            return {true, 0, INT_MAX, INT_MIN};
        }

        Info left = solve(root->left);
        Info right = solve(root->right);

        // Current subtree is BST
        if (left.isBST && right.isBST &&
            root->val > left.maxi &&
            root->val < right.mini) {

            int currSum = left.sum + right.sum + root->val;

            ans = max(ans, currSum);

            return {
                true,
                currSum,
                min(root->val, left.mini),
                max(root->val, right.maxi)
            };
        }

        // Not a BST
        return {false, 0, INT_MIN, INT_MAX};
    }

    int maxSumBST(TreeNode* root) {

        solve(root);

        return ans;
    }
};