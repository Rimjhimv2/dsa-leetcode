// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//     bool isPalindrome(ListNode* head) {
//         vector<int>temp;

//         ListNode*curr = head;
//         while(curr){

//             temp.push_back(curr->val);
//             curr = curr->next;

//         }
//         int i = 0 ;
//         int j = temp.size()-1;
//         while(i<j){
//             if(temp[i]!=temp[j]){
//                 return false;
//             }
//             i++;
//             j--;
//         }
//         return true;

//     }
// };

//ye bruteforce approch hai 

class Solution {
public:

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    bool isPalindrome(ListNode* head) {

        if(!head || !head->next)
            return true;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        while(fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // odd length
        if(fast) {
            slow = slow->next;
        }

        ListNode* tail = reverseList(slow);

        while(tail) {
            if(tail->val != head->val) {
                return false;
            }

            tail = tail->next;
            head = head->next;
        }

        return true;
    }
};