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
    int getDecimalValue(ListNode* head) {
        ListNode * temp=head;
        int size=0;
        while(temp->next!=NULL){
            temp=temp->next;
            size++;
        }
        int bin=0;
        temp=head;
        while(temp!=NULL){
            if(temp->val!=0)
            bin+=(1<<size);
            size--;
            temp=temp->next;
        }
        return bin;
    }
};