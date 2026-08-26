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
    ListNode* mergeNodes(ListNode* head) {

ListNode* curr = head->next;
ListNode* result = new ListNode(0);
ListNode* temp = result;
int sum = 0;

while(curr!=NULL){
    if(curr->val !=0){

        sum+=curr->val;

    }
    else{
        temp->next = new ListNode(sum);
        temp = temp->next;
         // New group starts
                sum = 0;
    }
    curr = curr->next;
}
return result->next;

    }
};