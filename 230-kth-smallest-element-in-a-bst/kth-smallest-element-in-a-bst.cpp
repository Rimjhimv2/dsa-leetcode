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


//e global variable hai.
// Jab hume kth smallest mil jayega, uski value isme store kar denge.
int ans;
void inorder(TreeNode* root ,int &k){


//ager node hi nhi hai toh wapas aajao
if(root == NULL){
            return;
        }

         inorder(root->left, k);
        k--;


//Jab kth node mil jaye
// to uski value answer me store kar do.
        if(k == 0 ){
            ans = root->val;
            return;
        }
         inorder(root->right, k);
}
    int kthSmallest(TreeNode* root, int k) {
        


            inorder(root, k);

        return ans;

    }
};