/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        bool isCycle = false;
        while(fast!= NULL && fast->next!=NULL){
           slow =  slow->next;
           fast = fast->next->next;
           if(fast == slow){
            isCycle = true;
            break;
           }

        }
           if(!isCycle){
            return NULL;
           }

//agaer cycle hai 
//to startting point nikalna hai 

slow = head;
//YAHA MANA LO 1 2 3 4 5 //OR 3 SE LOOP START HAI 
//ABHI SLOW = HEAD LINE LIKHNE SE PHLE SLOW = HEAD YANI 4 PAR HAI 
//TO AB HAM SLOW KO STARTING POINT PAR LE GYA AND FAST 4 PAR HI HAI THEN DONO KO AB EK EK HI SSTEPS CHLAYNGE OKKK

while(slow!= fast){
    slow = slow->next;
    fast = fast->next;
}
return slow;


        }
 

};