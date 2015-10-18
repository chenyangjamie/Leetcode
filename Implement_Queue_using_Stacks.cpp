/*
Implement the following operations of a queue using stacks.

push(x) -- Push element x to the back of queue.
pop() -- Removes the element from in front of queue.
peek() -- Get the front element.
empty() -- Return whether the queue is empty.
Notes:
You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).
*/

class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        sta.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if (empty()) return;
        if (!sta_rev.empty()) {
            sta_rev.pop();
            return;
        } else {
            while(!sta.empty()) {
                sta_rev.push(sta.top());
                sta.pop();
            }
            sta_rev.pop();
        }
    }

    // Get the front element.
    int peek(void) {
        if (empty()) return -1;
        if (!sta_rev.empty()) {
            return sta_rev.top();;
        } else {
            while(!sta.empty()) {
                sta_rev.push(sta.top());
                sta.pop();
            }
            return sta_rev.top();
        }
    }

    // Return whether the queue is empty.
    bool empty(void) {
        if (sta.empty() && sta_rev.empty())
            return true;
        return false;
    }
private:
    stack<int> sta;
    stack<int> sta_rev;
};
