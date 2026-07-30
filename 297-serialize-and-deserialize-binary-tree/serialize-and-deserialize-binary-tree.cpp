/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
public:

    // Serialize using Preorder Traversal
    void preorder(TreeNode* root, string &ans) {

        if (root == NULL) {
            ans += "N,";
            return;
        }

        ans += to_string(root->val) + ",";

        preorder(root->left, ans);
        preorder(root->right, ans);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {

        string ans = "";

        preorder(root, ans);

        return ans;
    }

    // Deserialize helper
    TreeNode* build(string &data, int &i) {

        // Base case
        if (i >= data.size())
            return NULL;

        // NULL node
        if (data[i] == 'N') {
            i += 2;      // Skip "N,"
            return NULL;
        }

        // Read number
        string num = "";

        while (i < data.size() && data[i] != ',') {
            num += data[i];
            i++;
        }

        i++; // Skip comma

        TreeNode* root = new TreeNode(stoi(num));

        root->left = build(data, i);

        root->right = build(data, i);

        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

        int i = 0;

        return build(data, i);
    }
};

/**
 * Your Codec object will be instantiated and called as such:
 * Codec ser, deser;
 * string tree = ser.serialize(root);
 * TreeNode* ans = deser.deserialize(tree);
 */