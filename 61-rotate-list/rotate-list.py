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
        temp1=head
        while(loop-1):
            temp1=temp1.next
            loop-=1
        curr_head=temp1.next
        temp1.next=None
        temp.next=head
        return curr_head
       






        