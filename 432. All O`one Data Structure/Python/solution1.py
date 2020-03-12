# Complexity
#   Time: O(1)
#   Space: (n)

class LinkedListNode(object):

    def __init__(self, data=None, pred=None, succ=None):
        self._data = data if data else {}
        self.pred = pred
        self.succ = succ

    def __getattr__(self, key):
        return self.__dict__['_data'].get(key)

    def __setattr__(self, key, value):
        if key in ('_data', 'pred', 'succ'):
            self.__dict__[key] = value
        else:
            self._data[key] = value

    def insert_after(self, lln):
        lln.pred = self
        lln.succ = self.succ
        self.succ.pred = lln
        self.succ = lln

    def insert_before(self, lln):
        self.pred.insert_after(lln)

    def delete(self):
        self.pred.succ = self.succ
        self.succ.pred = self.pred


class LinkedList(object):

    def __init__(self):
        self._header = LinkedListNode()
        self._trailer = LinkedListNode()
        self._header.succ = self._trailer
        self._trailer.pred = self._header

    def insert_first(self, lln):
        self._header.insert_after(lln)

    def insert_last(self, lln):
        self._trailer.insert_before(lln)

    def is_header(self, lln):
        return lln is self._header

    def is_trailer(self, lln):
        return lln is self._trailer

    @property
    def first(self):
        return self._header.succ if self._header.succ is not self._trailer else None

    @property
    def last(self):
        return self._trailer.pred if self._trailer.pred is not self._header else None

class AllOne:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.key2lln = {}
        self.linked_list = LinkedList()

    def inc(self, key: str) -> None:
        """
        Inserts a new key <Key> with value 1. Or increments an existing key by 1.
        """
        if key in self.key2lln:
            lln = self.key2lln[key]

            if self.linked_list.is_trailer(lln.succ) or lln.succ.count != lln.count + 1:
                lln.insert_after(LinkedListNode({'keys': set([key]), 'count': lln.count + 1}))
            else:
                lln.succ.keys.add(key)

            self.key2lln[key] = lln.succ
            lln.keys.remove(key)
            if len(lln.keys) == 0:
                lln.delete()
        else:
            first = self.linked_list.first

            if not first or first.count != 1:
                self.linked_list.insert_first(LinkedListNode({'keys': set([key]), 'count': 1}))
            else:
                first.keys.add(key)
            self.key2lln[key] = self.linked_list.first


    def dec(self, key: str) -> None:
        """
        Decrements an existing key by 1. If Key's value is 1, remove it from the data structure.
        """
        if key in self.key2lln:
            lln = self.key2lln[key]

            if lln.count > 1:
                if self.linked_list.is_header(lln.pred) or lln.pred.count != lln.count - 1:
                    lln.insert_before(LinkedListNode({'keys': set([key]), 'count': lln.count - 1}))
                else:
                    lln.pred.keys.add(key)
                self.key2lln[key] = lln.pred
            else:
                self.key2lln.pop(key)

            lln.keys.remove(key)
            if len(lln.keys) == 0:
                lln.delete()

    def getMaxKey(self) -> str:
        """
        Returns one of the keys with maximal value.
        """
        return list(self.linked_list.last.keys)[0] if self.linked_list.last else ""


    def getMinKey(self) -> str:
        """
        Returns one of the keys with Minimal value.
        """
        return list(self.linked_list.first.keys)[0] if self.linked_list.first else ""


# Your AllOne object will be instantiated and called as such:
# obj = AllOne()
# obj.inc(key)
# obj.dec(key)
# param_3 = obj.getMaxKey()
# param_4 = obj.getMinKey()
