/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//brute force: using hash table, hash the address if address already present cycle otherwise no
//TC: O(n), SC: O(n)

class Solution {
public:
    bool hasCycle(ListNode *head) {
        //optimized: f moves by 2 and s by 1, f catches up to s where cycle is present, if no cycle the f is NULL
        //TC: O(n), SC: O(1)
        if(head==NULL)
            return 0;
        ListNode *s= head, *f= head;
        while(f && f->next) {
            s= s->next;
            f= f->next->next;
            if(f==s)
                return 1;
        }
        return 0;
    }
};
