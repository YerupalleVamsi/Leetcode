/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL || head->next==NULL)
        return NULL;
        // first check there is a cycle or not 
        // nigga it is imp for edge cases where there is no cycle
        
        ListNode* slow=head;
        ListNode* fast=head;
        bool check=false;
        // Floyd's algo 
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                check=true;
                break;
            }
        }
        if(!check)return NULL;
        while(head!=slow){
            head=head->next;
            slow=slow->next;
        }
        return head;
        
    }
};