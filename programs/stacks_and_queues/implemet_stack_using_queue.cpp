class MyStack {
    queue<int> q1;
    queue<int> q2;
public:
    MyStack() {
        int x;
    }
    
    void push(int x) {
        if (!q1.empty()) q1.push(x);
        else q2.push(x);
    }
    
    int pop() {
        int x,f = 0;
        while(!q2.empty()) {
            if (q2.size() == 1) {x = q2.front();q2.pop();break;}
            x = q2.front(); q2.pop();
            q1.push(x);f = 1;
        }
        if (f == 1) return x;
        // if (q1.empty()) return -1;
        while(!q1.empty()) {
            if (q1.size() == 1) {x = q1.front();q1.pop();break;}
            x = q1.front(); q1.pop();
            q2.push(x);
        }
        return x;
    }
    
    int top() {
        int x,f=0;
        while(!q2.empty()) {
            if (q2.size() == 1) {x = q2.front();}
            x = q2.front(); q2.pop();
            q1.push(x);f = 1;
        }
        if (f ==1) return x;
        // if (q1.empty()) return -1;
        while(!q1.empty()) {
            if (q1.size() == 1) {x = q1.front();}
            x = q1.front(); q1.pop();
            q2.push(x);
        }
        return x;
    }
    
    bool empty() {
        return q1.empty() && q2.empty();
    }
};

// 1 stack

class MyStack {
    queue<int> q1;
public:
    void push(int x) {
        int x1;
        int s = q1.size();
        q1.push(x);
        while(s > 0) {
            x1 = q1.front(); q1.pop(); q1.push(x1);s--;
        }
    }
    
    int pop() {
        int x = q1.front(); q1.pop(); return x;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};