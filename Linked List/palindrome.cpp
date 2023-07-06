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
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return 1;
        ListNode *s=head, *f=head;
        //middle
        while(f && f->next) {
            f=f->next->next;
            s=s->next;
        }
        if(f!=NULL)
            s=s->next;
        //reverse
        ListNode *prev=NULL;
        while(s) {
            ListNode *temp= s->next;
            s->next= prev;
            prev= s;
            s= temp;
        }
        while(prev) {
            if(prev->val!= head->val)
                return 0;
            prev=prev->next;
            head=head->next;
        }
        return 1;
    }
};
