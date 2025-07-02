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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* check1=headA;
        ListNode* check2=headB;
        int lenA=0;
        int lenB=0;
        while(check1->next!=NULL){
            check1=check1->next;
            lenA++;
        }
        while(check2->next!=NULL){
            check2=check2->next;
            lenB++;
        }
        if(check1!=check2)return NULL;

        ListNode * currA=headA;
        ListNode * currB=headB;

        if(lenA>lenB){
            for(int i=0;i<lenA-lenB;i++){
                currA=currA->next;
            }
        }
        else{
            for(int i=0;i<lenB-lenA;i++){
                currB=currB->next;
            }
        }
        while(currA!=currB){
            currA=currA->next;
            currB=currB->next;
        }
        return currA;

    }
};