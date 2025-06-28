struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *past = NULL;
    struct ListNode *current = head;
    struct ListNode *future = NULL;

    while (current != NULL) {
        future = current->next;
        current->next = past;
        past = current;
        current = future;
    }
    
    return past;
}
