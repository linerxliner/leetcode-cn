/* Complexity
 *   Time: O(1)
 *   Space: O(n)
 */

class AllOne {
public:
    unordered_map<string, list<pair<unordered_set<string>, int>>::iterator> key2node;
    list<pair<unordered_set<string>, int>> nodes;
    /** Initialize your data structure here. */
    AllOne() {

    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if (key2node.count(key) == 0) {
            if (!nodes.empty() && nodes.front().second == 1) nodes.front().first.insert(key);
            else nodes.emplace_front(make_pair(unordered_set<string>({key}), 1));
            key2node[key] = nodes.begin();
        } else {
            auto curr = key2node[key];
            int value = curr->second;
            
            if (next(curr) == nodes.end()) nodes.emplace_back(make_pair(unordered_set<string>({key}), value + 1));
            else next(curr)->first.insert(key);
            key2node[key] = next(curr);
            
            if (curr->first.size() == 1) nodes.erase(curr);
            else curr->first.erase(key);
        }
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if (key2node.count(key) > 0) {
            auto curr = key2node[key];
            int value = curr->second;
            
            if (value > 1) {
                if (curr == nodes.begin() || prev(curr)->second != value - 1) nodes.insert(curr, make_pair(unordered_set<string>({key}), value - 1));
                else prev(curr)->first.insert(key);
                key2node[key] = prev(curr);
            } else key2node.erase(key);
            
            if (curr->first.size() == 1) nodes.erase(curr);
            else curr->first.erase(key);
        }
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        return nodes.empty() ? "" : *nodes.back().first.begin();
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        return nodes.empty() ? "" : *nodes.front().first.begin();
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
