# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverse(self,head:ListNode,stop:ListNode)->ListNode:
        curr=head
        pre=None
        nxt=None
        while curr!=stop:
            nxt=curr.next
            curr.next=pre
            pre=curr
            curr=nxt
        curr.next=pre
        return curr
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        if head.next==None or head==None or left==right:
            return head 
        dummy=ListNode(0)
        dummy.next=head
        prev=dummy
        for _ in range(left-1):
            prev=prev.next
        start=prev.next
        end=start
        for _  in range(right-left):
            end=end.next
        after=end.next
        new_head=self.reverse(start,end)
        prev.next=new_head
        start.next=after
        return dummy.next

        
        

        