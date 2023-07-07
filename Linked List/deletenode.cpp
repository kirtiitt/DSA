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
    void deleteNode(ListNode* node) {
        //just copy the next node into given node
        //TC: O(1), SC: O(1)
        ListNode *N=node->next;
        node->val= N->val;
        node->next= N->next;
    }
};
