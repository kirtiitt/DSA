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
    //brute force: count the length n, then move n/2
    //TC: O(n)+ O(n/2), SC: O(1)
    ListNode* middleNode(ListNode* head) {
        //f moves by 2, s moves by 1 and when f reaches NULL (even length) or last element (odd length) s is at middle
        //TC: O(n/2), SC: O(1)
        ListNode *slow= head, *fast=head;
        while(fast && fast->next) {
            slow= slow->next;
            fast= fast->next->next;
        }
        return slow;
    }
};
