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
    int pairSum(ListNode* head) {
        vector<ListNode*>v;
        ListNode*curr = head;
        
        while(curr!=NULL){
        v.push_back(curr);
        curr = curr->next;
        }

        int i = 0 ;
        int j = v.size()-1;
        int result = 0;
        while(i<j){
          result = max(result,v[i]->val+ v[j]->val);
          i++;
          j--;
        }
        return result;
    }
};