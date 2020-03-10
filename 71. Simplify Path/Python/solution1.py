# Complexity
#   Time: O(n)
#   Space: O(n)

class Solution:
    def simplifyPath(self, path: str) -> str:
        dirs = []

        tokens = path.split('/')
        for t in tokens:
            if t == '..':
                if len(dirs) > 0:
                    dirs.pop()
            elif t != '.' and t != '':
                dirs.append(t)

        return '/' + '/'.join(dirs)
