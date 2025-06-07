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
        return pre
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if not head or k==1:
            return head
        count=0
        temp=head
        while temp and count<k:
            temp=temp.next
            count+=1
        if count==k:
            new_head=self.reverse(head,temp)
            head.next=self.reverseKGroup(temp,k)
            return new_head
        else:
            return head        


        