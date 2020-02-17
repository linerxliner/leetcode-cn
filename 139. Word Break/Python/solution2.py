// BFS.
// Time: O(n^2), Space: O(n)

class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        s_len = len(s)
        visited = [False] * (s_len + 1)
        
        q = collections.deque()
        q.append(0)
        while len(q) > 0:
            begin = q.popleft()
            
            for w in wordDict:
                end = begin + len(w)
                if end <= s_len and s[begin : end] in wordDict:
                    if end == s_len:
                        return True
                    elif not visited[end]:
                        visited[end] = True
                        q.append(end)
            
        return False
