class LRUCache:

    def __init__(self, capacity: int):
        self._capacity = capacity
        self._data = collections.OrderedDict()

    def get(self, key: int) -> int:
        if key in self._data:
            value = self._data[key]
            self._data.pop(key)
            self._data[key] = value
        else:
            value = -1
        
        return value

    def put(self, key: int, value: int) -> None:
        if key in self._data:
            self._data.pop(key)
        elif len(self._data) >= self._capacity:
                self._data.popitem(last=False)
        self._data[key] = value
            


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
