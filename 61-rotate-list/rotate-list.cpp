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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head==NULL || k==0 || head->next==NULL) return head;
        ListNode * temp=head;
        int size=1;
        while(temp->next!=NULL){
            temp=temp->next;
            size+=1;
        }
        k%=size;
        if(k==0)return head;
        ListNode * tail=head;
        int loop=size-k-1;
        while(loop>0){
            tail=tail->next;
            loop-=1;
        }
        ListNode * new_head=tail->next;
        tail->next=NULL;
        temp->next=head;
        return new_head;
    }
};