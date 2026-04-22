class MyStack {
public:
    std::queue<int> queue0;
    std::queue<int> queue1;
    bool flipflap;
    MyStack() {
       flipflap =0;
    }
    
    void push(int x) {
        if (!flipflap){
            queue0.push(x);
        }else{
            queue1.push(x);
        }
    }
    
    int pop() {
        int res;
        if (!flipflap){
            while(!queue0.empty()){
                if(queue0.size()!=1){
                    queue1.push(queue0.front());
                }else{
                    res = queue0.front();
                }
                queue0.pop();
            }
            flipflap = 1;
        }else{
            while(!queue1.empty()){
                if(queue1.size()!=1){
                    queue0.push(queue1.front());
                }else{
                    res = queue1.front();
                }
                queue1.pop();
            }
            flipflap = 0;
        }
        return res;
    }
    
    int top() {
        int res;
        if (!flipflap){
            while(!queue0.empty()){
                queue1.push(queue0.front());
                if(queue0.size()==1){
                    res = queue0.front();
                }
                queue0.pop();
            }
            flipflap = 1;
        }else{
            while(!queue1.empty()){
                queue0.push(queue1.front());
                if(queue1.size()==1){
                    res = queue1.front();
                }
                queue1.pop();
            }
            flipflap = 0;
        }
        return res;
    }
    
    bool empty() {
        if(queue0.empty()&&queue1.empty()){
            return true;
        }
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */