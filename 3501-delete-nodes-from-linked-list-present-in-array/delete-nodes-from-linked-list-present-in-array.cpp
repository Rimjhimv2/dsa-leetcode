
//classic recursion
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        
        unordered_set<int> st(begin(nums), end(nums));

       
        while(head != NULL && st.find(head->val) != st.end()){
            head = head->next;   
        }

        ListNode* curr = head;

        while(curr != NULL && curr->next != NULL){
            
            if(st.find(curr->next->val) != st.end()){
                curr->next = curr->next->next;   
            }
            else{
                curr = curr->next;
            }
        }

        return head;
    }
};
