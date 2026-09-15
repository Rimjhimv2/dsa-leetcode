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
   int ans = 0;
   int findHeight(TreeNode*root){
    
    if(root == NULL){
        return 0;

    }
    int left = findHeight(root->left);
    int right = findHeight(root->right);
// i find the maximum path passing through that node and updaye the ans 
    ans = max(ans,left+ right);

    //. For the parent, I return the better of the left or right path."
    return 1+ max(left,right);
   }
    int diameterOfBinaryTree(TreeNode* root) {
        
       findHeight(root);
       return ans; 
    }
};