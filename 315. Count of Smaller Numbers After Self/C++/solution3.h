// Fenwick Tree.
// Time: O(nlogn), Space: O(n)

class Solution {
public:
    struct FenwickTree {
        int len;
        vector<int> tree;
        
        FenwickTree(int n) {
            tree = vector<int>(n + 1, 0);
            len = n;
        }
        
        inline int LowBit(int idx) {
            return idx & -idx;
        }
        
        inline int Child(int idx) {
            return idx - LowBit(idx);
        }
        
        inline int Parent(int idx) {
            return idx + LowBit(idx);
        }
        
        void Update(int idx, int delta) {
            while (idx <= len) {
                tree[idx] += delta;
                idx = Parent(idx);
            }
        }
        
        int Query(int idx) {
            int sum = 0;
            
            while (idx > 0) {
                sum += tree[idx];
                idx = Child(idx);
            }
            
            return sum;
        }
    };
    
    static bool Comp(pair<int, int>& p1, pair<int, int>& p2) {
        return p1.second < p2.second;
    }

    vector<int> countSmaller(vector<int>& nums) {
        vector<int> result(nums.size(), 0), ranks(nums.size());
        vector<pair<int, int>> indexes(nums.size());
        FenwickTree fenwick_tree(nums.size());
        
        for (int i = 0; i < nums.size(); ++i) indexes[i] = make_pair(i, nums[i]);
        sort(indexes.begin(), indexes.end(), Comp);
        for (int i = 0, rank = 1; i < indexes.size(); ++i) {
            ranks[indexes[i].first] = rank;
            if (i < indexes.size() - 1 && indexes[i].second < indexes[i + 1].second) ++rank;
        }
        
        for (int i = indexes.size() - 1; i >= 0; --i) {
            result[i] = fenwick_tree.Query(ranks[i] - 1);
            fenwick_tree.Update(ranks[i], 1);
        }
        
        return result;
    }
};
