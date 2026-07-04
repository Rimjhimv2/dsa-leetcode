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


ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        
        if(head1 == NULL){
            return head2;
        }
        if(head2 == NULL){
            return head1;
        }

        if(head1->val <= head2->val){
            head1->next = mergeTwoLists(head1->next, head2);
            return head1;
        }

        else{
             head2->next = mergeTwoLists(head2->next, head1);
            return head2;
        }
        return NULL;
    }

    ListNode* partitionAndmerge( int start,int end,vector<ListNode*>& lists){
        if(start> end){
            return NULL;
        }
       if(start== end){
        return lists[start];
       }

      int mid = start + (end - start) / 2;

      ListNode* l1 = partitionAndmerge(start, mid, lists);
        ListNode* l2 = partitionAndmerge(mid+1,end,lists);

        return mergeTwoLists(l1,l2);

    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        

        if(lists.size()==0){
            return NULL;
        }

        return partitionAndmerge(0, lists.size() - 1, lists);
    }
};