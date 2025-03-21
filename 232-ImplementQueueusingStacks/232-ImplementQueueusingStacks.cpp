// Last updated: 3/21/2025, 9:03:23 PM
class MyQueue {
private:
stack<int>s1,s2;
public:
    MyQueue() {  
    }
    
    void push(int x) {
        s1.push(x);
        
    }
    
    int pop() {
        //remove until 1 element
        while(!s1.empty()){
            int top = s1.top();
            s2.push(top);
            s1.pop();
        }
        int pop =  s2.top();
        s2.pop();
        while(!s2.empty()){
            int top = s2.top();
            s1.push(top);
            s2.pop();
        }
        return pop;
        
    }
    
    int peek() {
         while(!s1.empty()){
            int top = s1.top();
            s2.push(top);
            s1.pop();
        }
        int peek = s2.top();
        while(!s2.empty()){
            int top = s2.top();
            s1.push(top);
            s2.pop();
        }
        return peek;
        
        
    }
    
    bool empty() {
        return s1.empty();
        
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */