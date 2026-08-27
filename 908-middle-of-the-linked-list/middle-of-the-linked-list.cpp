/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//     ListNode* middleNode(ListNode* head) {
//         ListNode* curr = head ;
//         int len = 0 ;
//         while(curr!=NULL){
            
//             len++;
//             curr = curr->next;
//         }
//         int middle = len/2;
//         curr = head;
       
//             for(int i = 0 ; i< middle ; i++){
//                 curr= curr->next;
//             }
        
//         return curr;
//     }
// };


class Solution {
public:
    ListNode* middleNode(ListNode* head) {


ListNode*slow = head;
ListNode*fast = head;

while(fast!=NULL && fast->next!=NULL){
    slow = slow->next;
    fast = fast->next->next;
}
return slow;
             }
 };