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
    ListNode* reverseList(ListNode* head) {
        //TC: O(n), SC: O(1)
        ListNode *d= NULL;
        while(head) {
            ListNode *Next= head->next;
            head->next= d;
            d= head;
            head= Next;
        }
        return d;
    }
};
