# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    

            
    def findTarget(self, root: Optional[TreeNode], k: int) -> bool:
        order = []
        
        
        def inorder(root : Optional[TreeNode], order : List[int]):
            if not root : 
                return

            if root.left :
                inorder(root.left,order)
            order.append(root.val)

            if root.right:
                inorder(root.right,order)
        
        inorder(root,order)
        temp = {}
        
        for i,num in enumerate(order):
            if k-num in temp:
                return True
            
            temp[num] = 1
        
        return False
        
        