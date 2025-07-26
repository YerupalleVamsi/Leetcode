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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int,vector<int>,greater<int>>minheap;
        for (ListNode* node : lists) {
        while(node){
            minheap.push(node->val);
            node=node->next;
        }
    }
    ListNode* res=new ListNode(); // like a dummy node mowa
    ListNode * curr=res;
    while(!minheap.empty()){
        curr->next=new ListNode(minheap.top());
        minheap.pop();
        curr=curr->next;
    }

return res->next;

    }
};