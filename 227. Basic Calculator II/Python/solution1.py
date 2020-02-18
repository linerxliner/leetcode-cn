class Solution:
    def read_num(self, nums, s, i):
        j = i
        while j < len(s) and s[j].isdigit():
            j += 1
        nums.append(int(s[i:j]))
        
        return j

    def calculate(self, s: str) -> int:
        s = ''.join(s.split(' '))
        nums = []
        
        i = 0
        while i < len(s):
            if s[i].isdigit():
                i = self.read_num(nums, s, i)
            else:
                op = s[i]
                i += 1
                i = self.read_num(nums, s, i)
                
                if op == '-':
                    nums[-1] = -nums[-1]
                elif op == '*':
                    nums[-2:] = [nums[-2] * nums[-1]]
                elif op == '/':
                    nums[-2:] = [int(nums[-2] / nums[-1])]
        
        return sum(nums)
        
        
