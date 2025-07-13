/*

The structure of the class is
class MyQueue {
private:
    int arr[100005];
    int front;
    int rear;

public :
    MyQueue(){front=0;rear=0;}
    void push(int);
    int pop();
};
 */

// Function to push an element x in a queue.
void MyQueue ::push(int x) {
    // Your Code
    int c = 1000005;
    if ((rear+1)% c == front) return;
    rear = (rear+1)% c; arr[rear] = x;
}

// Function to pop an element from queue and return that element.
int MyQueue ::pop() {
    // Your Code
    if (rear == front) return -1;
    int c = 100005;
    front = (front+1)% c;
    return arr[front];
}