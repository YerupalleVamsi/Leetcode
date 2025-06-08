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
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* nxt=NULL;
        while(curr!=NULL){
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        return prev;
    }
    ListNode* removeNodes(ListNode* head) {
        ListNode* rev=reverse(head);
        ListNode* temp=rev;
        ListNode* prev=rev;
        int maxi=INT_MIN;
        while(temp!=NULL){
            if(temp->val<maxi){
                prev->next=temp->next;
            }else{
                maxi=temp->val;
                prev=temp;
            }
            
            temp=temp->next;
            
        }
        return reverse(rev);
    }
};