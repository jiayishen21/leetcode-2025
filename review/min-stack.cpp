#include <stack>

using namespace std;

class MinStack
{
public:
    stack<int> vals;
    stack<int> minVals;

    MinStack()
    {
        vals = stack<int>();
        minVals = stack<int>();
    }

    void push(int val)
    {
        if (vals.size() == 0)
        {
            minVals.push(val);
        }
        else
        {
            minVals.push(min(val, minVals.top()));
        }
        vals.push(val);
    }

    void pop()
    {
        vals.pop();
        minVals.pop();
    }

    int top()
    {
        return vals.top();
    }

    int getMin()
    {
        return minVals.top();
    }
};
