#include <iostream>
#include <stack>
#include <string>

using namespace std;

stack<int> Chuyen(const string &str)
{
    stack<int> chuyen;

    for(const char &ch : str)
    {
        chuyen.push(ch - 48);
    }

    return chuyen;
}

void Plus(stack<int> &result, stack<int> &st, int &mem)
{
    int s;
    while(!st.empty())
    {
        s = st.top() + mem;
        if(s >= 10)
        {
            mem = 1;
            s %= 10;
        }   
        else mem = 0;
        st.pop();
        result.push(s);
    }
}

int main()
{
    stack<int> a, b;
    stack<int> result;
    string _a, _b;
    cin >> _a >> _b;
    a = Chuyen(_a);
    b = Chuyen(_b);

    int s; int mem = 0;
    while(!(a.empty() || b.empty()))
    {
        s = a.top() + b.top() + mem;
        if(s >= 10)
        {
            mem = 1;
            s %= 10;
        }
        else mem = 0;
        result.push(s);
        a.pop(), b.pop();
    }
    Plus(result, a, mem);
    Plus(result, b, mem);

    if(mem == 1) result.push(mem);

    while(!result.empty())
    {
        cout << result.top();
        result.pop();
    }

    return 0;
}