class MyStack {
    queue<int>q;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        
    }
    
    int pop() {
        int n=q.size();
        for(int i=1;i<n;i++){
            q.push(q.front());
            q.pop();
        } 
        int a=q.front();
        q.pop();
        return a;
    }
    int top() {
        int n=q.size();
        for(int i=1;i<n;i++){
            q.push(q.front());
            q.pop();
        } 
        int a= q.front();
        q.pop();
        q.push(a);
        return a;
    }
    
    bool empty() {
        return q.empty();
        
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