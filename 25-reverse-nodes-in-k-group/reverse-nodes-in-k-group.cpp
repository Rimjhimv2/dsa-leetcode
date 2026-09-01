class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* curr = head;
        ListNode* prevGroupEnd = NULL;

        while (curr != NULL) {

            // 1. Check karo k nodes available hain ya nahi
            ListNode* temp = curr;

            for (int i = 0; i < k; i++) {
                if (temp == NULL)
                    return head;

                temp = temp->next;
            }

            // temp = next group ka first node
            ListNode* nextGroup = temp;

            // 2. Current k nodes reverse karo
            ListNode* prev = nextGroup;
            ListNode* node = curr;

            for (int i = 0; i < k; i++) {
                ListNode* next = node->next;

                node->next = prev;
                prev = node;
                node = next;
            }

            // 3. First group hai toh head update karo
            if (prevGroupEnd == NULL) {
                head = prev;
            }
            else {
                prevGroupEnd->next = prev;
            }

            // 4. Current group ka end = curr
            prevGroupEnd = curr;

            // 5. Next group par jao
            curr = nextGroup;
        }

        return head;
    }
};