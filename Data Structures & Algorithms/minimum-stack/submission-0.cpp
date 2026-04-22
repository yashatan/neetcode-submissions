class MinStack {
private:
     stack<int> stackData;
     stack<int> minValues;
public:

    MinStack() {}
    
    void push(int val) {
        stackData.push(val);
        
        if (stackData.size() == 1){
            minValues.push(val);
        }
        else{
            if((stackData.top() <=  minValues.top())){
                minValues.push(val);
            }
        }
    }
    
    void pop() {
        if((stackData.top() == minValues.top())){
            minValues.pop();
        }
        stackData.pop();
    }
    
    int top() {
            return stackData.top();
    }
    
    int getMin() {
            return minValues.top();
    }
};
