class MyQueue {
    stack<int> s1,s2;
public:

    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        int x;
        if (!s2.empty()) {x = s2.top(); s2.pop(); return x;}
        if (s1.empty()) return -1;
        while(!s1.empty()) {
            x = s1.top(); s1.pop();
            s2.push(x);
        }
        s2.pop(); return x;
    }
    
    int peek() {
        int x;
        if (!s2.empty()) {x = s2.top(); return x;}
        if (s1.empty()) return -1;
        while(!s1.empty()) {
            x = s1.top(); s1.pop();
            s2.push(x);
        }
        return x;
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};