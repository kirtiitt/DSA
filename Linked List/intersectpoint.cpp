/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//brute force: traverse in one list and for each element check address in the second list
//TC: O(n1* n2), SC: O(1)

//using hash table: store the address of any one list, traverse in other and see if address is present in hash
//TC: O(n1+ n2), SC: O(n1) or O(n2) depending on which lists address is stored

//optimized method 1
//count length of list let them be n1, n2 traverse n1- n2 distance in bigger list
//then traverse both list together and see where d1== d2 and return
//TC: O(max(n1, n2))+ O(n1-n2)+ O(min(n1, n2)), worst: O(2* max(n1, n2)) for no intersection node, SC: O(1)
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

//optimized method 2
//d1 and d2 pointers traverse in two lists respectively and other list when any one becomes NULL, this way the list difference is covered
//no intersection node means d1 and d2 are NULL
//TC: O(2* max(n1, n2)), SC: O(1)
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
