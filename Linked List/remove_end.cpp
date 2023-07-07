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
    //brute force: count the length, say size. move size- n and then d->next= d->next->next
    //edge case: first node to be deleted when n==c
    //TC: O(n)+ O(n), SC: O(1)
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //optimized: f moves for n and then s and f move till list exists i.e. f->next
        //then s->next= s->next->next i.e. delete node
        //TC: O(n), SC: O (1)
        ListNode *d= new ListNode();
        d->next= head;
        ListNode *f= d, *s=d;
        for (int i=0; i<n; i++)
            f= f->next;
        while(f->next) {
            f= f->next;
            s= s->next;
        }
        s->next= s->next->next;
        return d->next;
    }
};
