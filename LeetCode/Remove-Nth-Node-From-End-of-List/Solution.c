struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
      
    struct ListNode temp;
    temp.next=head;
    struct ListNode *first = &temp;
    struct ListNode *second = &temp;

   
    for (int i = 0; i <= n; i++) {
        first = first->next;
    }

    
    while (first != NULL) {
        first = first->next;
        second = second->next;
    }

    struct ListNode *nodeToRemove = second->next;
    second->next = second->next->next;

   
    free(nodeToRemove);

    return temp.next;
}