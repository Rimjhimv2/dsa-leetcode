class Solution {
public:
    ListNode* removeNodes(ListNode* head) {

        // Step 1: Put all nodes into stack
        stack<ListNode*> st;

        ListNode* curr = head;

        while (curr != NULL) {
            st.push(curr);
            curr = curr->next;
        }

        // Step 2: Rightmost node will always remain
        curr = st.top();
        st.pop();

        int maxVal = curr->val;

        // Result list
        ListNode* resultHead = new ListNode(curr->val);

        // Step 3: Process from right to left
        while (!st.empty()) {

            curr = st.top();
            st.pop();

            // If there is a greater value on the right
            if (curr->val < maxVal) {
                continue;
            }

            // Otherwise keep this node
            ListNode* newNode = new ListNode(curr->val);

            newNode->next = resultHead;
            resultHead = newNode;

            // Update maximum
            maxVal = curr->val;
        }

        return resultHead;
    }
};