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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>>res(m,vector<int>(n,-1));
        int top = 0,bottom=m-1;
        int left = 0,right=n-1;
        while(head!=NULL){
            for(int c=left;c<=right && head;c++){
                res[top][c] = head->val;
                head=head->next;
            }
            top++;
            for(int r=top;r<=bottom && head;r++){
                res[r][right]=  head->val;
                head=head->next;
            }
            right--;
            for(int c=right;c>=left && head;c--){
                res[bottom][c] = head->val;
                head=head->next;
            }
            bottom--;
            for(int r=bottom;r>=top && head;r--){
                res[r][left]=head->val;
                head=head->next;
            }
            left++;
        }
        return res;
    }
};