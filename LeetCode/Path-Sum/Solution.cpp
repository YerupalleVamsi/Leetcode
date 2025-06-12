# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        if not root:
            return False
        def helper(node:Optional[TreeNode],currsum:int)->bool:
            if not node:
                return False
        
            currsum+=node.val
            if not node.left and not node.right:
                return currsum==targetSum
            return (helper(node.left,currsum) or helper(node.right,currsum))

        return helper(root,0)
        