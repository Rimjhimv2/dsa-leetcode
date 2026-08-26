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
        //list sorted thi esiliye duplicates sath honge toh ye ass pass ki value compare kar 
      ListNode*curr = head;
      while(curr!=NULL && curr->next!=NULL){
        if(curr->val == curr->next->val){
            curr->next = curr->next->next;
        }
        else{
            //curr val dplicate nhi hai toh simply curr ko badha de 
            curr = curr->next;
        }
      } 
      return head; 
    }
};