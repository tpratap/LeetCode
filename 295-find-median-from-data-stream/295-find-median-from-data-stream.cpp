class MedianFinder {
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxHeap.empty() || maxHeap.top() > num) { //It satisfiy if num is smaller value
            maxHeap.push(num);
        }
        else
            minHeap.push(num);
        
        //Balancing trees
        if(maxHeap.size() > minHeap.size()+1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if(maxHeap.size() + 1 < minHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if(maxHeap.size() == minHeap.size()) {
            if(maxHeap.empty())
                return 0;
            else
                return (maxHeap.top()+minHeap.top())/2.0;
        }
        else {
            if(maxHeap.size() > minHeap.size())
                return maxHeap.top();
            else
                return minHeap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */