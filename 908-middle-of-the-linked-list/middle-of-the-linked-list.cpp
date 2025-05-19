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
    ListNode* middleNode(ListNode* head) {
        int size=1;
        struct ListNode * temp = head;
        while(temp!=NULL){
            temp=temp->next;
            size++;
        }
        int mid;
        if (size%2==0){
            mid=(size/2)+1;
        }
        mid=size/2;
        struct ListNode * cur=head;
        int count=1;
        while(count!=mid){
            cur=cur->next;
            count++;
        }
        return (size%2==0)? cur : cur->next  ;
    }
};