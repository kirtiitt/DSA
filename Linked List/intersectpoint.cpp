/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//method 1
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL || headB==NULL)
            return NULL;
        ListNode *d1= headA;
        ListNode *d2= headB;
        int l1= 0, l2= 0;
        while(d1) {
            d1= d1->next;
            l1++;
        }
        while(d2) {
            d2= d2->next;
            l2++;
        }
        int diff=0;
        d1= headA;
        d2= headB;
        if(l1> l2) {
            diff= l1- l2;
            for(int i=0; i<diff; i++)
                d1= d1->next;
        }
        else if(l1< l2) {
            diff= l2- l1;
            for(int i=0; i<diff; i++)
                d2= d2->next;
        }
        while(d1 && d2) {
            if(d1== d2)     return d1;
            d1= d1->next;
            d2= d2->next;
        }
        return NULL;
    }
};

//method 2
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL || headB==NULL)
            return NULL;
        ListNode *d1= headA;
        ListNode *d2= headB;
        while(d1!=d2) {
            d1= d1==NULL? headB: d1->next;
            d2= d2==NULL? headA: d2->next;
        }
        return d1;
    }
};
