class Solution {
public:    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        bool has_end = false;
        
        for (auto& s: wordList) {
            if (s == endWord) {
                has_end = true;
                break;
            }
        }
        if (!has_end) return 0;
        
        int ladder_len = 1;
        unordered_set<string> from, to, words(wordList.begin(), wordList.end());
        
        from.insert(beginWord); words.erase(beginWord);
        to.insert(endWord); words.erase(endWord);
        
        while (!from.empty() && !to.empty()) {
            unordered_set<string> tmp;
            
            ++ladder_len;
            for (auto& s: from) {
                for (int i = 0; i < s.size(); ++i) {
                    string to_s = s;
                    
                    for (char c = 'a'; c <= 'z'; ++c) {
                        to_s[i] = c;
                        if (to.count(to_s) > 0) return ladder_len;
                        else if (words.count(to_s) > 0) {
                            tmp.insert(to_s);
                            words.erase(to_s);
                        }
                    }
                }
            }
            
            if (tmp.size() < to.size()) from = tmp;
            else {
                from = to;
                to = tmp;
            }
        }
        
        return 0;
    }
};
