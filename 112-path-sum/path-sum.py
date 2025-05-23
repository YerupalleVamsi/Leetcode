# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def helper(self,root:Optional[TreeNode],target:int,currsum:int)->bool:
        if not root:
            return False
        currsum+=root.val
        if not root.left and not root.right:
            return currsum==target
        return (self.helper(root.left,target,currsum) or self.helper(root.right,target,currsum))

    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        return self.helper(root,targetSum,0)
        