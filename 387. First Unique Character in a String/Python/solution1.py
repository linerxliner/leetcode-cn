class Solution:
    def firstUniqChar(self, s: str) -> int:
        idx = -1
        first_idx = [-1] * 26
        letter_cnt = [0] * 26
        
        for i, l in enumerate(s):
            t = ord(l) - ord('a')
            
            if first_idx[t] == -1:
                first_idx[t] = i
            letter_cnt[t] += 1
            
        for i, cnt in enumerate(letter_cnt):
            if cnt == 1 and (idx == -1 or first_idx[i] < idx):
                idx = first_idx[i]
        
        return idx
