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
    ListNode* rotateRight(ListNode* head, int k) {
        
        //phle length calculate karo 
        ListNode*temp = head;
         if (head == NULL || head->next == NULL) {
            return head;
        }

        int length =1 ;
        while(temp->next!= NULL){
           temp =  temp->next;
           length++;
        }

        k = k% length;//remove unneccessary rotation

        if(k == 0){
            return head;
            //kuch rotation karna hi nhui hai 
        }

        temp->next = head;

        ListNode*curr = head;
        for(int i = 1; i< length-k ; i++){
            curr = curr->next;
        }
      ListNode*newHead = curr->next;
        curr->next = NULL;
        return newHead;
    }
};