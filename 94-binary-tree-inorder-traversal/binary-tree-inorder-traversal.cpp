class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {

        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* curr = root;

        while (curr != NULL || !st.empty()) {

            // Push all left nodes
            while (curr != NULL) {
                st.push(curr);
                curr = curr->left;
            }

            // Visit node
            curr = st.top();
            st.pop();

            ans.push_back(curr->val);

            // Move to right subtree
            curr = curr->right;
        }

        return ans;
    }
};