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

    int minSwaps(vector<int>& arr) {

        int n = arr.size();

        vector<pair<int,int>> temp;

        for(int i=0;i<n;i++)
            temp.push_back({arr[i],i});

        sort(temp.begin(),temp.end());

        vector<bool> visited(n,false);

        int swaps=0;

        for(int i=0;i<n;i++){

            if(visited[i] || temp[i].second==i)
                continue;

            int cycle=0;
            int j=i;

            while(!visited[j]){

                visited[j]=true;

                j=temp[j].second;

                cycle++;
            }

            swaps+=cycle-1;
        }

        return swaps;
    }

    int minimumOperations(TreeNode* root) {

        queue<TreeNode*>q;
        q.push(root);

        int ans = 0; 
        while(!q.empty()){

            int size = q.size();

            vector<int>level(size);
            for(int i = 0 ;  i<size;i++){

                TreeNode*node = q.front();
                q.pop();

                level.push_back(node->val);

                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }

            }
            ans+= minSwaps(level);
        }
        return ans;
    }
};