class MedianFinder {
private:
    // Max Heap (stores the smaller half)
    priority_queue<int> left;
    // Min Heap (stores the larger half)
    priority_queue<int, vector<int>, greater<int>> right;

public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        // Step 1: Decide which heap to insert into
        if (left.empty() || num <= left.top()) {
            left.push(num);
        } else {
            right.push(num);
        }

        // Step 2: Balance the heaps

        // Left has more than one extra element
        if (left.size() > right.size() + 1) {
            right.push(left.top());
            left.pop();
        }

        // Right has more elements
        if (right.size() > left.size()) {
            left.push(right.top());
            right.pop();
        }
    }
    
    double findMedian() {
        // Odd number of elements
        if (left.size() > right.size()) {
            return left.top();
        }

        // Even number of elements
        return (left.top() + right.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */