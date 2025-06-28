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
    bool isPalindrome(ListNode* head) {
        struct ListNode *temp= head;
        vector<int>ll;
        while(temp->next!=NULL){
            ll.push_back(temp->val);
            temp=temp->next;
        }
        ll.push_back(temp->val);
        int n=ll.size();
        int l=n-1;
        for(int i=0;i<n/2;i++){
            if(ll[i]!=ll[l]){
                return false;
            }
            l--;
        }
        return true;
    }
};