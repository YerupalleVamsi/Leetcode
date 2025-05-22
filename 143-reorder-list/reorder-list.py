# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    # reversing the linked list
    def reverse(self,head:ListNode) -> ListNode:
         prev=None
         curr=head
         while(curr):
            next=curr.next
            curr.next=prev
            prev=curr
            curr=next
         return prev

    def reorderList(self, head: Optional[ListNode]) -> None:
        if not head or not head.next:
            return
        fast=head
        slow=head
        while(fast and fast.next):
            fast=fast.next.next
            slow=slow.next
        rev=self.reverse(slow)
        while(rev.next):
            temp1=head.next
            temp2=rev.next
            
            head.next=rev
            rev.next=temp1
            
            head=temp1
            rev=temp2
        

        
        