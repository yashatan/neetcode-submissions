using std::vector;
using std::priority_queue;
using std::greater;
class MedianFinder {
public:
    priority_queue<int> smallH; // max heap
    priority_queue<int, vector<int>, greater<int>> largeH; // min heap
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        smallH.push(num);
        if (!smallH.empty() && !largeH.empty() && smallH.top()> largeH.top()){
            largeH.push(smallH.top());
            smallH.pop();
        }

        if(smallH.size() > largeH.size() +1){
            largeH.push(smallH.top());
            smallH.pop();
        }

        if(largeH.size() > smallH.size() +1){
            smallH.push(largeH.top());
            largeH.pop();
        }
    }
    
    double findMedian() {
        if(largeH.size() > smallH.size()){
            return largeH.top();
        }
        if(smallH.size() > largeH.size()){
            return smallH.top();
        }

        return (double)(((double)smallH.top() + (double)largeH.top())/2);
    }
};
