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
    ListNode* rev(ListNode *head,ListNode* stop){
        ListNode * curr=head;
        ListNode * prev=NULL,*nxt=NULL;
        while(curr!=stop){
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k==1){
            return head;
        }
        int cnt=0;
        ListNode* temp=head;
        while(temp!=NULL && cnt<k){
            temp=temp->next;
            cnt++;
        }
        if(cnt==k){
            ListNode* newhead=rev(head,temp);
            head->next=reverseKGroup(temp,k);
            return newhead;
        }
        else{
            return head;
        }
    }
};