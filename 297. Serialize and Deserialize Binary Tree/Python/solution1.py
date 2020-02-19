# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        if root is None:
            return '[]'
        
        result = []
        deq = collections.deque()
        
        deq.append(root)
        
        while len(deq) > 0:
            curr = deq.popleft()
            
            if curr:
                result.append(str(curr.val))
                deq.append(curr.left)
                deq.append(curr.right)
            else:
                result.append('null')
        
        return '[' + ','.join(result) + ']'

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        data = data[1: -1].split(',')
        if not data[0]:
            return None
        
        deq = collections.deque()
        root = TreeNode(int(data[0]))
        child_idx = 1
        
        deq.append(root)
        
        while len(deq) > 0:
            curr = deq.popleft()
            
            if data[child_idx] != 'null':
                curr.left = TreeNode(int(data[child_idx]))
                deq.append(curr.left)
            child_idx += 1
            
            if data[child_idx] != 'null':
                curr.right = TreeNode(int(data[child_idx]))
                deq.append(curr.right)
            child_idx += 1
        
        return root
                

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))
