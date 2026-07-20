class MedianFinder {
private:
    // Max heap
    priority_queue<int, vector<int>> left;
    // Min heap
    priority_queue<int, vector<int>, greater<int>> right;

public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        if(left.empty() || num <= left.top())
            left.push(num);
        else
            right.push(num);

        // Balancing the elements
        if(left.size() > right.size() + 1) {
            right.push(left.top());
            left.pop();
        }

        if(right.size() > left.size()) {
            left.push(right.top());
            right.pop();
        }
    }
    
    double findMedian() {
       // Odd elements
       if(left.size() > right.size())
        return left.top();

        return (double)(left.top() + right.top())/2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */