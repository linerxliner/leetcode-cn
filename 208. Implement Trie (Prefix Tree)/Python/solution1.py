class Trie:
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self._root = {}

    def insert(self, word: str) -> None:
        """
        Inserts a word into the trie.
        """
        curr = self._root
        
        for l in word:
            if l not in curr:
                curr[l] = {}
            curr = curr[l]
        curr['end'] = True

    def search(self, word: str) -> bool:
        """
        Returns if the word is in the trie.
        """
        curr = self._root
        
        for l in word:
            if l not in curr:
                return False
            else:
                curr = curr[l]
        
        return 'end' in curr

    def startsWith(self, prefix: str) -> bool:
        """
        Returns if there is any word in the trie that starts with the given prefix.
        """
        curr = self._root
        
        for l in prefix:
            if l not in curr:
                return False
            else:
                curr = curr[l]
        
        return True


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)
