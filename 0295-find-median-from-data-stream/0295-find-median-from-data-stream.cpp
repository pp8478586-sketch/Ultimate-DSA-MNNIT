class MedianFinder {
    priority_queue<int,vector<int>>left;
    priority_queue<int,vector<int>,greater<int>>right;
public:
    MedianFinder() {

    }
    void addNum(int num) {
        if(!left.empty()&&num<=left.top()){
            left.push(num);
        }
        else {
            right.push(num);
        }
        int leftSize=left.size();
        int rightSize=right.size();
        if(leftSize-rightSize>1){
            right.push(left.top());
            left.pop();
        }
        else if(rightSize-leftSize>1){
            left.push(right.top());
            right.pop();
        }
    }
    
    double findMedian() {
        int leftSize=left.size();
        int rightSize=right.size();
        if(leftSize==rightSize){
            return (left.top()+right.top())/2.0;
        }
        else if(leftSize<rightSize){
            return right.top();
        }
        else {
            return left.top();
        }
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */