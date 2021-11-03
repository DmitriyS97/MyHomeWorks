#include <iostream>
#include <string>
#include <stack>
using namespace std;


string toPoland(const string& str) {
    string res;
    stack<char> st;

    for (const char ch : str) {
        if (isdigit(ch)) {
            res += ch;
        }
        else
        {
            switch (ch)
            {

            case '(':
                st.push(ch);
                break;

            case ')':
                while (st.top() != '(')
                {
                    res += st.top();
                    st.pop();
                }
                st.pop();
                break;

            case '+':
                while (!st.empty() && (st.top() == '+' || st.top() == '-' || st.top() == '*' || st.top() == '/'))
                {
                    res += st.top();
                    st.pop();
                }
                st.push('+');
                break;

            case '-':
                while (!st.empty() && (st.top() == '+' || st.top() == '-' || st.top() == '*' || st.top() == '/'))
                {
                    res += st.top();
                    st.pop();
                }
                st.push('-');
                break;

            case '*':
                while (!st.empty() && (st.top() == '*' || st.top() == '/'))
                {
                    res += st.top();
                    st.pop();
                }
                st.push('*');
                break;

            case '/':
                while (!st.empty() && (st.top() == '*' || st.top() == '/'))
                {
                    res += st.top();
                    st.pop();
                }
                st.push('/');
                break;
            default:
                break;
            }
        }
    }

    while (!st.empty()) {
        res += st.top();
        st.pop();
    }
    return res;
}

auto operations(double a, double b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    default:
        break;
    }
}
double solv(const string& str)
{
    string polandString = toPoland(str);
    stack<double> st;    
    for (const char ch : polandString)
    {
        if (isdigit(ch))
        {
            int number = ch - '0';
            st.push(number);
        }
        else
        {
            double num2 = st.top();
            st.pop();
            if (!st.empty())
            {
                double num1 = st.top();
                st.pop();
                st.push(operations(num1, num2, ch));
            }
            else
            {
                st.push(num2*(-1));
            }
        }
    }
    double res = st.top();

    return res;
}

int main() {
    string str;
    cin >> str;
    cout << solv(str);

    return 0;
}