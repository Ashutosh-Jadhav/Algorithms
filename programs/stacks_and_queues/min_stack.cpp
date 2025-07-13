class MinStack {
    stack<pair<int,int>> s1;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if (s1.empty()) s1.push({val,val});
        else {
            int min;
            min = s1.top().second;
            if (val < min) s1.push({val,val});
            else s1.push({val,min});
        }
    }
    
    void pop() {
        s1.pop();
    }
    
    int top() {
        return s1.top().first;
    }
    
    int getMin() {
        return s1.top().second;
    }
};