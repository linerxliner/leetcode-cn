class LRUCache {
public:
    int capacity;
    unordered_map<int, list<pair<int, int>>::iterator> lru_hash;
    list<pair<int, int>> lru_list;
    
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (lru_hash.count(key) == 0) return -1;
        else {
            pair<int, int> data = *lru_hash[key];
            
            lru_list.erase(lru_hash[key]);
            lru_list.push_front(data);
            
            lru_hash[key] = lru_list.begin();
            
            return data.second;
        }
    }
    
    void put(int key, int value) {
        auto it = lru_hash.find(key);
        
        if (lru_hash.count(key) == 0) {
            if (lru_list.size() >= capacity) {
                lru_hash.erase(lru_list.back().first);
                lru_list.pop_back();
            }
            
            lru_list.push_front(make_pair(key, value));
            lru_hash[key] = lru_list.begin();
        } else {
            get(key);
            lru_list.front().second = value;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
