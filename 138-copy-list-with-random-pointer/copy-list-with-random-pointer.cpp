
class Solution {
public:

    void insertCopyInBetween(Node* head) {

        Node* temp = head;

        while (temp != NULL) {

            Node* copyNode = new Node(temp->val);

            copyNode->next = temp->next;
            temp->next = copyNode;

            temp = copyNode->next;
        }
    }

    void connectRandomPointers(Node* head) {

        Node* temp = head;

        while (temp != NULL) {

            Node* copyNode = temp->next;

            if (temp->random != NULL) {
                copyNode->random = temp->random->next;
            }

            temp = temp->next->next;
        }
    }

    Node* getDeepCopyList(Node* head) {

        Node* temp = head;

        Node* dummyNode = new Node(-1);
        Node* res = dummyNode;

        while (temp != NULL) {

            res->next = temp->next;
            res = res->next;

            temp->next = temp->next->next;
            temp = temp->next;
        }

        return dummyNode->next;
    }

    Node* copyRandomList(Node* head) {

        if (head == NULL) {
            return NULL;
        }

        insertCopyInBetween(head);
        connectRandomPointers(head);

        return getDeepCopyList(head);
    }
};