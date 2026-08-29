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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        
        ListNode*prev = head;
        ListNode*curr = head->next;
        int currpos = 0 ;
        int prevcp = -1;
        int firstcp =-1;
        int mindis = INT_MAX;


        while(curr->next!=NULL){
            if(curr->val < prev->val && curr->val < curr->next->val || curr->val > prev->val && curr->val > curr->next->val ){

                //ager hume abbhi tak koi critical point nhi mila toh 
                if(prevcp == -1){
                    prevcp = currpos;
                    firstcp = currpos;
                }
                else{
                    //ab hume mil chuka hai critical point toh 
                    
                    mindis = min(mindis , currpos - prevcp);
                    prevcp = currpos;
                }
            }
            currpos ++;
            prev = curr;
            curr = curr->next;
        }

        if(mindis == INT_MAX){
            return {-1,-1};
        }
        return {mindis,prevcp-firstcp};

    }
};