// //iterative approch

// class Solution {
// public:
//     ListNode* insertGreatestCommonDivisors(ListNode* head) {

//         if(!head || !head->next) {
//             return head;
//         }

//         ListNode* currNode = head;

//         while(currNode && currNode->next) {

//             ListNode* nextNode = currNode->next;

//             int gcdValue = __gcd(currNode->val, nextNode->val);

//             ListNode* temp = new ListNode(gcdValue);

//             currNode->next = temp;
//             temp->next = nextNode;

//             currNode = nextNode;   // move 2 steps ahead
//         }

//         return head;
//     }
// };

//recursive approch
 class Solution {
public:
     ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head || !head->next){
            return head;
        }

ListNode* temp = insertGreatestCommonDivisors(head->next);

ListNode* gcdNode= new ListNode(__gcd(head->val,head->next->val));

gcdNode->next = temp;
head->next = gcdNode;
return head;


     }
 };