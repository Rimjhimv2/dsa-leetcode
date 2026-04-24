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
string result = "";
void dfs(TreeNode*root, string curr){

    //means we are exploring every path 
    // i.e root = current node 
    // and curr = string formed from leaf->current node

    //or agr koi node hi nhi to stop ho jao 
    if(!root)return ;

    //ab umber ko string mai convert karo 
    curr = char(root->val + 'a') + curr;
    //👉 “We are moving top → bottom, but string needs bottom → top, so we build it backwards using PREPEND.”

    if(!root->left && !root->right){
        if(result == "" || result > curr){
            result = curr;
        }
        return;
    }
//     What is happening?
// We check:
// if result is empty → take first string
// OR
// if new string is smaller → update
// 👉 result > curr = lexicographic comparison
    // explore children
        dfs(root->left, curr);
        dfs(root->right, curr);
}
    string smallestFromLeaf(TreeNode* root) {
        
      
//       You need to:
// Start from any leaf node
// Go up to the root
// Form a string
// Return the lexicographically smallest string

dfs(root,"");
return result;



    }
};