class Solution {
public:
    struct Comp {
        bool operator() (pair<int, int> & p1, pair<int, int> & p2) const {
            return p1.second > p2.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        priority_queue<pair<int, int>, vector<pair<int, int>>, Comp> min_heap;
        vector<int> result(k);
        
        for (auto i: nums) ++count[i];
        
        for (const auto & p: count) {
            min_heap.push(p);
            if (min_heap.size() > k) min_heap.pop();
        }
        
        for (int i = 0; i < k; ++i) {
            result[k - 1 - i] = min_heap.top().first;
            min_heap.pop();
        }
        
        return result;
    }
};
