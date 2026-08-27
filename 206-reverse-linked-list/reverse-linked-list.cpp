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
//     ListNode* reverseList(ListNode* head) {
//         ListNode*curr = head;
//         stack<int>st;//stack mai value store karo 
//         while(curr!=NULL){
//             st.push(curr->val);
//             curr = curr->next;
//         }

//         curr = head;
//         while(curr!=NULL){
//             curr->val = st.top();
//             st.pop();
//                curr = curr->next;
//         }
//         return head;

//     }
// };

// Time Complexity: O(n)

// We traverse the linked list twice:

// First while loop → push all values → O(n)
// Second while loop → update all values → O(n)

// So:

// O(n) + O(n) = O(n)

// Space Complexity: O(n)

// The stack stores all n node values:

// stack<int> st;

// So extra space is O(n).

// Final:

// TC: O(n)
// SC: O(n)


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        ListNode*curr = head;
        ListNode*prev = NULL;

        while(curr!=NULL){
            ListNode*next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;

    }
};