class Solution {
public:

    // we will solve this in three steps nigga check it 

    // read floyd's tortoise and hare algo also you will get it
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;

        // Step 1: Find middle (slow ends at middle)
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse second half
        ListNode* prev = NULL;
        ListNode* curr = slow;
        while (curr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }

        // Step 3: Compare both halves
        ListNode* firstHalf = head;
        ListNode* secondHalf = prev;
        while (secondHalf) {
            if (firstHalf->val != secondHalf->val) {
                return false;
            }
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }

        return true;
    }
};
