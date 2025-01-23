class MedianFinder {
public:
    priority_queue<int> maxh; // for left elements
    priority_queue<int, vector<int>, greater<int>> minh; // for right elements
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxh.empty() || num < maxh.top()){
            maxh.push(num);
        }
        else{
            minh.push(num);
        }

        if(maxh.size() > minh.size() + 1){
            minh.push(maxh.top());
            maxh.pop();
        }
        else if(maxh.size() < minh.size()){
            maxh.push(minh.top());
            minh.pop();
        }
    }
    
    double findMedian() {
        if(maxh.size() == minh.size()){
            return (double) (maxh.top() + minh.top())/2 ;
        }
        
        return maxh.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */