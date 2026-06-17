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
int gettingLengthOfNode(ListNode* head){
      int len = 0;
      while(head!= NULL){
        len++;
        head=head->next;
      }
      return len;
}
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int L = gettingLengthOfNode(head);
        //base case 
        if(L == n){
            ListNode*temp = head->next;
            delete(head);
            return temp;
        }
        int travel_front = L-n;
        ListNode*prev = NULL;
        ListNode*temp = head;

        while(travel_front--){
             prev = temp;
             temp = temp->next;

        }
        //jese hi apni particular position par pahuch haye 
        prev ->next= temp->next;
        delete(temp);

        return head;

    }
};