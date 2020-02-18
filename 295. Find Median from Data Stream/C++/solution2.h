// Retrieves median by inorder traversal in binary search tree.
// Time: O(logn), Space: O(n)

class MedianFinder {
public:
    multiset<int> ms;
    multiset<int>::iterator median;
    
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        ms.insert(num);
        
        if (ms.size() == 1) median = ms.begin();
        else if (num < *median) median = ms.size() & 1 ? median : prev(median);
        else median = ms.size() & 1 ? next(median) : median;
    }
    
    double findMedian() {
        return ms.size() & 1 ? *median : (*median + *next(median)) * 0.5;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
