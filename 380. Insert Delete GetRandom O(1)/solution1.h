class RandomizedSet {
public:
    unordered_map<int, int> m;
    vector<int> v;
    default_random_engine e;
    
    /** Initialize your data structure here. */
    RandomizedSet() {
        e.seed(time(0));
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (m.count(val) == 0) {
            m[val] = v.size();
            v.push_back(val);
            return true;
        } else return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (m.count(val) == 0) return false;
        else {
            int last_val = v[v.size() - 1], idx = m[val];
            
            v[idx] = last_val;
            m[last_val] = idx;
            
            v.pop_back();
            m.erase(val);
            
            return true;
        }
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return v[e() % v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
