class MedianFinder {
public:

priority_queue<int>leftHeap;//max heap hai ye 
priority_queue<int,vector<int>,greater<int>>rightHeap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        leftHeap.push(num);

        rightHeap.push(leftHeap.top());
        leftHeap.pop();

        if(rightHeap.size()> leftHeap.size()){
            leftHeap.push(rightHeap.top());
            rightHeap.pop();
        }
    }
    
    double findMedian() {
        
        if(leftHeap.size()> rightHeap.size()){
            return leftHeap.top();
        }
        return  (leftHeap.top() + rightHeap.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */