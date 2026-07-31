/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {


        if(root == NULL){
            return NULL ;
        }
        queue<Node*>q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            //jaise hi level change hogi prev re ininialize hoga null par 
            
             Node* prev = NULL;
            for(int i = 0 ; i<size ; i++){
               
                Node* curr = q.front();

                q.pop();

                if(prev!=NULL){
                    prev->next = curr;

                }
                prev = curr;

                if(curr->left){
                    q.push(curr->left);
                }

                if(curr->right){
                    q.push(curr->right);
                }
            }

            prev->next = NULL;
        }

        return root;
        
    }
};

///har node ka next pointer uske right side wale node ki taraf point karta hai

//ager next node ke right mai koi node nahi hai toh next = NULL hogaaa

///perfect binary tree ke 2 children hota hai and leaf node sare same level par hote hai 

