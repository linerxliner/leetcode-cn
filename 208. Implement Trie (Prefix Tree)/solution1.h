class Trie {
public:
    static const int kLetterNum = 26;
    
    struct TrieNode {
        bool is_end = false;
        TrieNode * succ[kLetterNum];
        
        TrieNode() {
            memset(succ, NULL, sizeof(succ));
        }
    };
    
    TrieNode root;
    
    /** Initialize your data structure here. */
    Trie() {
        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode * curr = & root;
        
        for (auto c: word) {
            if (curr->succ[c - 'a'] == NULL) curr->succ[c - 'a'] = new TrieNode;
            curr = curr->succ[c - 'a'];
        }
        
        curr->is_end = true;
    }
    
    TrieNode * probe(const string & word) {
        TrieNode * curr = & root;
        
        for (auto c: word) {
            if (curr->succ[c - 'a'] != NULL) curr = curr->succ[c - 'a'];
            else return NULL;
        }
        
        return curr;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode * trie_node = probe(word);
        
        return trie_node != NULL && trie_node->is_end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode * trie_node = probe(prefix);
        
        return trie_node != NULL;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
