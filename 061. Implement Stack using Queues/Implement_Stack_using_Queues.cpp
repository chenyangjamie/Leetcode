/*
Implement the following operations of a stack using queues.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
empty() -- Return whether the stack is empty.
Notes:
You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is empty operations are valid.
Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).
*/
class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        que.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        if(empty()) return;
        for(int i=0;i<que.size()-1;i++) {
            que.push(que.front());
            que.pop();
        }
        que.pop();
    }

    // Get the top element.
    int top() {
        if(empty()) return -1;
        for(int i=0;i<que.size()-1;i++) {
            que.push(que.front());
            que.pop();
        }
        int temp = que.front();
        que.push(que.front());
        que.pop();
        return temp;
    }

    // Return whether the stack is empty.
    bool empty() {
        return que.empty();
    }
private:
    queue<int> que;
};
