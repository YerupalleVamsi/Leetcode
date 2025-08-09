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
    ListNode* reverse(ListNode* head){
        ListNode * curr=head;
        ListNode * prev=NULL;
        ListNode * nxt=NULL;
        while(curr!= NULL){
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        return prev;

    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * dummy = new ListNode();
        ListNode* ans=dummy;
        ListNode * rl1=reverse(l1);
        ListNode * rl2=reverse(l2);
        int carry=0;
        int sum=0;
        while (rl1 || rl2 || carry) {
            sum = carry;
        if (rl1) {
            sum += rl1->val;
            rl1 = rl1->next;
        }
        if (rl2) {
            sum += rl2->val;
            rl2 = rl2->next;
        }
        int v = sum % 10;
        carry = sum / 10;
        dummy->next = new ListNode(v);
        dummy = dummy->next;
        }

        ListNode*res=reverse(ans->next);
        delete ans;
        return res;
    }
};