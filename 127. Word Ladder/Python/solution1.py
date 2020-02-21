// BiBFS.
// Time: O(k * n), Space: O(k * n)

class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        from_set, to_set = {beginWord}, {endWord}
        word_set = set(wordList)
        letters = [chr(ord('a') + i) for i in range(26)]

        if beginWord in word_set:
            word_set.remove(beginWord)
        if endWord in word_set:
            word_set.remove(endWord)
        else:
            return 0
        
        ladder_length = 2
        while len(from_set) > 0 and len(to_set) > 0:
            tmp_set = set()
            for w in from_set:
                for i in range(len(w)):
                    new_w_list = list(w)[:]
                    for l in letters:
                        new_w_list[i] = l
                        new_w = ''.join(new_w_list)
                        if new_w in to_set:
                            return ladder_length
                        elif new_w in word_set:
                            tmp_set.add(new_w)
                            word_set.remove(new_w)
            from_set = tmp_set
            if len(from_set) > len(to_set):
                from_set, to_set = to_set, from_set
            ladder_length += 1
        
        return 0
