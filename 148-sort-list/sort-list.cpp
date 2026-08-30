/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
//  */
// class Solution {
// public:
//     ListNode* sortList(ListNode* head) {

//         vector<int> arr;
//         ListNode* temp = head;

//         while (temp != NULL) {
//             arr.push_back(temp->val);
//             temp = temp->next;
//         }

//         sort(arr.begin(), arr.end());

//         int i = 0;
//         temp = head;

//         while (temp != NULL) {
//             temp->val = arr[i];
//             i++;
//             temp = temp->next;
//         }

//         return head;
//     }
// };



class Solution {
 public:

 ListNode*findMiddle(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head->next;
    //catch here in normally fast point to head but in this see coz i want middle to stop at the first middle so fast pointre one place ahead

    while(fast!= NULL && fast->next!= NULL){
        slow = slow ->next;
       fast = fast->next->next;
    }
    return slow;
 }

ListNode* mergeList(ListNode* left, ListNode* right) {

    if (left == NULL) {
        return right;
    }

    if (right == NULL) {
        return left;
    }

    if (left->val < right->val) {
        left->next = mergeList(left->next, right);
        return left;
    }
    else {
        right->next = mergeList(left, right->next);
        return right;
    }
}

   ListNode* sortList(ListNode* head) {

if(head == NULL || head->next == NULL){
    return head;
}
ListNode * middle = findMiddle(head);
ListNode* left = head ;
ListNode* right = middle->next;
middle->next = NULL;

left = sortList(left);
right = sortList(right);
return mergeList(left,right);

        }
 };