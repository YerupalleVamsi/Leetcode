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
    ListNode* swapNodes(ListNode* head, int k) {
    ListNode * temp=head;
    int s=0;
    while(temp!=NULL){
        temp=temp->next;
        s++;
    }
    ListNode* temp2=head;
    ListNode* temp3=head;
    int cnt1=0;
    int cnt2=0;
    while(cnt1!=k-1){
        temp2=temp2->next;
        cnt1++;
    }
    while(cnt2!=s-k){
        cnt2++;
        temp3=temp3->next;
    }
    int tval = temp3->val;
    temp3->val=temp2->val;
    temp2->val=tval;
    return head;
    }
};