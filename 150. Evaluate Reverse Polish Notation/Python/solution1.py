class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        
        for t in tokens:
            if t == '+':
                stack[-2:] = [stack[-2] + stack[-1]]
            elif t == '-':
                stack[-2:] = [stack[-2] - stack[-1]]
            elif t == '*':
                stack[-2:] = [stack[-2] * stack[-1]]
            elif t == '/':
                stack[-2:] = [int(stack[-2] / stack[-1])]
            else:
                stack.append(int(t))
        
        return stack[0]
