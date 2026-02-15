class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        
        unordered_set<int> st(begin(nums), end(nums));

        // Remove from beginning
        while(head != NULL && st.find(head->val) != st.end()){
            head = head->next;   // delete removed
        }

        ListNode* curr = head;

        while(curr != NULL && curr->next != NULL){
            
            if(st.find(curr->next->val) != st.end()){
                curr->next = curr->next->next;   // delete removed
            }
            else{
                curr = curr->next;
            }
        }

        return head;
    }
};
