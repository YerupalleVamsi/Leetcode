# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if not head or not head.next or k == 0:
            return head

        temp=head
        size=1

        while(temp.next):
            temp=temp.next
            size+=1

        k=k%size

        if k==0:
            return head

        loop=size-k
        tail=head

        while(loop-1):
            tail=tail.next
            loop-=1
            
        curr_head=tail.next
        tail.next=None
        temp.next=head
        return curr_head
       






        