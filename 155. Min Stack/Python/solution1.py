class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.stack = []
        self.min_top = []

    def push(self, x: int) -> None:
        self.stack.append(x)
        if len(self.min_top) == 0 or x <= self.min_top[-1]:
            self.min_top.append(x)

    def pop(self) -> None:
        if len(self.stack) > 0:
            top = self.stack.pop()
            if top == self.min_top[-1]:
                self.min_top.pop()

    def top(self) -> int:
        if len(self.stack) > 0:
            return self.stack[-1]

    def getMin(self) -> int:
        if len(self.min_top) > 0:
            return self.min_top[-1]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
