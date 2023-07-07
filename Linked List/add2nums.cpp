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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //sum is calculated as sum% 10, the last digit and carry as sum/ 10 i.e. first digit (only 2 digit number in sum, always)
        //TC: O(max(n1, n2)), SC: O(n) for new list containing ans
        ListNode *head= NULL, *temp= NULL;
        int carry= 0;
        while(l1|| l2|| carry) {
            int sum=0;
            if(l1) {
                sum+= l1->val;
                l1= l1->next;
            }
            if(l2) {
                sum+= l2->val;
                l2= l2->next;
            }
            sum+= carry;
            carry= sum/10;
            ListNode *node= new ListNode(sum%10);
            if(head==NULL)
                head=temp= node;
            else {
                temp->next= node;
                temp= node;
            }
        }
        return head;
    }
};
