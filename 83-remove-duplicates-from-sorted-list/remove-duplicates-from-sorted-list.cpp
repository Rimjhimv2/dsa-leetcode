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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* originalHead = head;
        
        while(head!= NULL && head->next!= NULL){
            if(head->val == head->next->val){
                head->next = head->next->next;

            }
            else{
                //ager koi dupliuicate hi value nhi hai toj 
                head = head ->next;
                //yaha se head apni ek position se aage hogya hai so 
            }
        }
        return originalHead;

    }
};