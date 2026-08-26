/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {

        // Agar starting ke nodes delete hone hain
        while(head != NULL && head->val == val) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }
        
        ListNode*curr = head;
        ListNode*prev = NULL;
        while(curr!=NULL){
            if(curr->val == val){

      prev ->next = curr->next;
      
       ListNode* temp = curr;
curr = curr->next;
delete temp;
            }
            else{
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};