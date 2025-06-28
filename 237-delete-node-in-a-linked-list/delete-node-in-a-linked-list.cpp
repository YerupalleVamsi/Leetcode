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
    void deleteNode(ListNode* node) {
        ListNode *temp=node;
        if(temp->next->next==NULL)
        {
            temp->val=temp->next->val;
            temp->next=NULL;
        }
        else{
            temp->val=temp->next->val;
            temp->next=temp->next->next;
        }
    }
};