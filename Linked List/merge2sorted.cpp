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

//brute force: merge the two lists into a new list
//TC: O(n1+ n2), SC: O(n1+ n2)

//optimized space: l1 denotes the smaller element list and l2 the bigger, swap if not the case and keep changing the link
//TC: O(n1+ n2), SC: O(1)
//method 1: recursion
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        if(l1->val > l2->val)
            swap(l1, l2);
        l1->next= mergeTwoLists(l1->next, l2);
        return l1;
    }
};

//method 2: iterative
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        if(l1->val > l2->val)
            swap(l1, l2);
        ListNode *head= l1;
        while(l1 && l2) {
            ListNode *temp= NULL;
            while (l1 && l1->val<= l2->val) {
                temp= l1;
                l1= l1->next;
            }
            temp->next= l2;
            swap(l1, l2);
        }
        return head;
    }
};
