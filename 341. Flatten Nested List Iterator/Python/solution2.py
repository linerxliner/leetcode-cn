// Generator.
// Time: O(n), Space: O(n)

# """
# This is the interface that allows for creating nested lists.
# You should not implement it, or speculate about its implementation
# """
#class NestedInteger:
#    def isInteger(self) -> bool:
#        """
#        @return True if this NestedInteger holds a single integer, rather than a nested list.
#        """
#
#    def getInteger(self) -> int:
#        """
#        @return the single integer that this NestedInteger holds, if it holds a single integer
#        Return None if this NestedInteger holds a nested list
#        """
#
#    def getList(self) -> [NestedInteger]:
#        """
#        @return the nested list that this NestedInteger holds, if it holds a nested list
#        Return None if this NestedInteger holds a single integer
#        """

class NestedIterator:
    def __init__(self, nestedList: [NestedInteger]):
        def generator(nested_list):
            for elem in nested_list:
                if elem.isInteger():
                    yield elem.getInteger()
                else:
                    elem_nested_list = elem.getList()
                    for value in generator(elem_nested_list):
                        yield value
        
        self.gen = generator(nestedList)
        self.deq = collections.deque()
    
    def next(self) -> int:
        return self.deq.popleft()
    
    def hasNext(self) -> bool:
        try:
            self.deq.append(next(self.gen))
            return True
        except:
            return False

# Your NestedIterator object will be instantiated and called as such:
# i, v = NestedIterator(nestedList), []
# while i.hasNext(): v.append(i.next())
