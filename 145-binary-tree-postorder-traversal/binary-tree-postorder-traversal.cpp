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
void post(TreeNode* root,vector<int>&ans){
    if(root==NULL){
        return ;
    }
    post(root->left,ans);
    //phle left subtree traverse karo 
    post(root->right,ans);
    //fir right subtree traverse karo 
    ans.push_back(root->val);
    //and then root ki value dalde

    //phle left dekho fir right dekho and fir root ki value add kardo 
}
    vector<int> postorderTraversal(TreeNode* root) {
        
        vector<int>ans;
        post(root,ans);
        return ans;
    }
};