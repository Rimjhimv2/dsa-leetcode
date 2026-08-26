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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        

         // Find length
        int L = 0;
        
 vector<ListNode*>result;
 ListNode*curr = head;
        while(curr != NULL) {
            L++;
            curr = curr->next;
        }
      
        ListNode*prev = NULL;

        int extranodes = L%k;
curr = head;
       
        for(int i = 0 ; i<k;i++){
                 result.push_back(curr);
            for(int count = 0;
    count < L/k + (extranodes > 0 ? 1 : 0);
    count++){
                prev = curr;
                curr = curr->next;
            }
           if(prev != NULL)
    prev->next = NULL;
            extranodes--;

        }
        return result;
    }
};