class Solution {
public:
    Node* copyRandomList(Node* head) {

        if(head == NULL)
            return NULL;

        unordered_map<Node*, Node*> mp;

        Node* newHead = new Node(head->val);

        mp[head] = newHead;

        Node* oldTemp = head->next;
        Node* newTemp = newHead;

        // Create copied linked list and store mapping
        while(oldTemp != NULL) {

            Node* copyNode = new Node(oldTemp->val);

            mp[oldTemp] = copyNode;

            newTemp->next = copyNode;

            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }

        // Set random pointers
        oldTemp = head;
        newTemp = newHead;

        while(oldTemp != NULL) {

            if(oldTemp->random)
                newTemp->random = mp[oldTemp->random];

            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }

        return newHead;
    }
};