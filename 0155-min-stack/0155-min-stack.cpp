#include <stack>
using namespace std;
class MinStack {
private:
    stack<int> st;     // Main stack
    stack<int> minSt;  // Stack to store minimums

public:
    MinStack() {
        // Constructor - no initialization needed
    }
    
    void push(int val) {
        st.push(val);
        if (minSt.empty() || val <= minSt.top()) {
            minSt.push(val);
        } else {
            minSt.push(minSt.top()); // Push the current minimum again
        }
    }
    
    void pop() {
        if (!st.empty()) {
            st.pop();
            minSt.pop();
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};