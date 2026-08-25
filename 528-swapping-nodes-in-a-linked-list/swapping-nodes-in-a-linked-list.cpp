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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode*first = head;
        for(int i = 1; i<k; i++){
            first = first->next;
            //ab first pahuch gaya hai kth position par 
        }
        //ab lst kth pos ke liye 2 pointer ki need
        
        ListNode* fast = first;
               ListNode* slow = head;
        while(fast->next != NULL){
    fast = fast->next;
    slow = slow->next;
}
        //ab slow pahuch gaya hai last kth par 
        swap(first->val, slow->val);
        return head;
    }
};