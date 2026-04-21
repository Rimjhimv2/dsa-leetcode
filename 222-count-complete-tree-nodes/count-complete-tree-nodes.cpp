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

    int getLeftHeight(TreeNode*root){
        TreeNode*temp = root;
        int lh = 0 ; 
        while(temp){
            temp= temp->left;
            lh++;
        }
        return lh;
    }
    int getRightHeight(TreeNode*root){
        TreeNode*temp = root;//root se start kro 
        //root par ek temp pointer leliey jo ki ab sirf right hi jata rahega 
        
        int rh = 0 ; 
        while(temp){
            //jab tak node exist kar raha tab tak right jate raho 
            temp= temp->right;
            rh++;
        }
        return rh;
    }


    int countNodes(TreeNode* root) {
        if(root == NULL){
            return 0 ; 
        }

        int lh = getLeftHeight(root);
        ///left side se seedha height nikalega
        int rh = getRightHeight(root);
        if(lh == rh){
            //ab yaha left height and right height same hai toh yeh complete binary tree hai matlab har level completely filled hoga 

            //so agar tree perfect hota hai to total nodes = by this formula
            return(pow(2,lh)-1);
        }

    return countNodes(root->left) + countNodes(root->right) + 1;

    }
};