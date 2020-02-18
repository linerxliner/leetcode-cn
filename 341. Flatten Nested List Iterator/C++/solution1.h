/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
    int idx;
    vector<NestedInteger>* curr;
    stack<pair<vector<NestedInteger>*, int>> s;
    
    NestedIterator(vector<NestedInteger> &nestedList) {
        curr = &nestedList;
        idx = 0;
    }

    int next() {
        return (*curr)[idx++].getInteger();
    }

    bool hasNext() {
        while (!s.empty() || idx < curr->size()) {
            if (idx >= curr->size()) {
                curr = s.top().first;
                idx = s.top().second;
                s.pop();
            } else if (!(*curr)[idx].isInteger()) {
                s.push(make_pair(curr, idx + 1));
                curr = &(*curr)[idx].getList();
                idx = 0;
            } else break;
        }
        
        return idx < curr->size() && (*curr)[idx].isInteger();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
