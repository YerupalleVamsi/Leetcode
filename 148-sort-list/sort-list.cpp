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
    ListNode* sortList(ListNode* head) {
        vector<int>vec;
        ListNode* temp=head;
        ListNode*cur=head;
        while(temp!=NULL){
            vec.push_back(temp->val);
            temp=temp->next;
        }
        sort(vec.begin(),vec.end());
        int i=0;
        while(cur!=NULL){
            cur->val=vec[i];
            cur=cur->next;
            i++;
        }
        return head;

    }
};