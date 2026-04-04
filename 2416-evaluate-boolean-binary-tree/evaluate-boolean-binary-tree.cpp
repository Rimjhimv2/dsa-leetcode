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
    bool evaluateTree(TreeNode* root) {
       //base case 

       if( root->left == NULL || root-> right == NULL) {
        return root-> val;
       }
       int a = evaluateTree(root->left);
       int b = evaluateTree(root->right);

       if(root->val == 2 ){
        return a || b;
       }
       return a & b ;
    }
};
//kya krana hai root ke left subtree ki value nikal lo 0r root ke right subteree ki value nikal lo 
//use recuresion leap of faith 

 //agar root ki value 2 hai then  or operation and root ki value agar 3 hai toh and operation 
 //bs yhi return karna hai 


