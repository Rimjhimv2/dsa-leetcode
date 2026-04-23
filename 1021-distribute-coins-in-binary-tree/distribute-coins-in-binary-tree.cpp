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

    int moves =0;
    int dfs(TreeNode *root){
        if(root==NULL) return 0;
//root hi nhi hao toh koi coin exchange hi nhi hoga
        int left = dfs(root->left);
        //left dekhi
        int right = dfs(root->right);
//right dekhio
        moves += abs(left)+ abs(right);
//ab total moves nikalo
        return root->val + left + right -1;

        //root->val
//👉 Current node ke paas kitne coins hain
//2. left + right
//👉 Left aur right subtree ka net balance
//+ve → extra coins bhej rahe hain
//-ve → coins maang rahe hain
// -1
// Kyunki har node ko sirf 1 coin chahiye

        
    }
    int distributeCoins(TreeNode* root) {


        //agar root hi nahi hai toh coin 

        //question mai ye bol rahaa ki
        //Har node par coin hai
//exchange hi nhi hoga

        dfs(root);
        return moves;

        //ab yaha left subtree btaynge dior right subtre ki enke pass koi extra coin hai ya nhai hai


        
            //goal yeh hai hat node par ek coin hona chaiye..
            //coin ko parent ya child ke pass move karao
            //toh tumhe find karna hai ki minimum node kitne lagenge..

            // man lo root par e coin hai or left mai 0 hai and right mai 0 hai 
            // toh tumhe left mai 1 coin bhejna hai and right mai ek coin bhejna hai 
            // so total 2 move ho jaynge



            //Main intuition kya hai...
            //jiske pass jyada coin hai vo dega or jiske pass Kam coin hai vo legal

            //tumhe bas count karna hai total kitne move hi sakte hai that's it..
            
    }
};