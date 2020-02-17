class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        if len(board) == 0 or len(board[0]) == 0:
            return []
        
        trie_root = {}
        
        def insert(word):
            curr = trie_root
            
            for l in word:
                if l not in curr:
                    curr[l] = {}
                curr = curr[l]
            
            curr['end'] = True
        
        for w in words:
            insert(w)
        
        directions = [[0, -1], [1, 0], [0, 1], [-1, 0]]
        solution = []
        results = []
        visited = [[False] * len(board[0]) for _ in range(len(board))]
        
        def enter(r, c, trie_node):
            visited[r][c] = True
            solution.append(board[r][c])
            dfs(r, c, trie_node[board[r][c]])
            solution.pop()
            visited[r][c] = False
        
        def dfs(r, c, trie_node):
            if 'end' in trie_node and 'visited' not in trie_node:
                results.append(''.join(solution))
                trie_node['visited'] = True
            elif not trie_node:
                return
            
            for d in directions:
                n_r = r + d[0]
                n_c = c + d[1]
                
                if n_r >= 0 and n_r < len(board) and n_c >= 0 and n_c < len(board[0]) and board[n_r][n_c] in trie_node and not visited[n_r][n_c]:
                    enter(n_r, n_c, trie_node)
        
        for r in range(len(board)):
            for c in range(len(board[0])):
                if board[r][c] in trie_root:
                    enter(r, c, trie_root)
        
        return results
