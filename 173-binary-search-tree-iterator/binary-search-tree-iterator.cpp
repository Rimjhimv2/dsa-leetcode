class BSTIterator {
public:
    stack<TreeNode*> st;

    // Left path ko stack me push karne wala function
    void pushAll(TreeNode* node) {
        while (node != NULL) {
            st.push(node);
            node = node->left;
        }
    }

    // Constructor
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }

    // Agla smallest element return karega
    int next() {
        TreeNode* temp = st.top();
        st.pop();

        // Agar right subtree hai to uska left path push karo
        if (temp->right != NULL) {
            pushAll(temp->right);
        }

        return temp->val;
    }

    // Kya aur elements bache hain?
    bool hasNext() {
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */



//  Tumhee ek bst iterator bnana hai 
//  iterator ka matlab hai ek ek element ko sequence mai return karna hai 
//  bst ke liye sequence hoga inorder traversal

//  or hume pura inorder vector phle se return nhi karna hai 
// Sirf ye functions dene hain:
// next()
// hasNext()