#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

vector<string> strToVector(const string& str)
{
    vector<string> temp(0);
    string s;

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '-' && i == 0)
        {
            s += str[i];
            continue;
        }
        if (str[i] == '-')
        {
            if (!isdigit(str[i - 1]))
            {
                if (!isdigit(str[i - 2]))
                {
                    s += str[i];
                    continue;
                }
            }
        }
        if (isdigit(str[i]))
        {
            s += str[i];
            continue;
        }
        if (str[i] == '.')
        {
            s += str[i];
            continue;
        }
        if (str[i] == '(' || str[i] == ')')
        {
            if (i!=0 && s!="") temp.push_back(s);
            s = "";
            s += str[i];
            temp.push_back(s);
            s = "";
        }
        else
        {
            if (s!="") temp.push_back(s);
            s = "";
            s += str[i];
            temp.push_back(s);
            s = "";
        }
    }
    if (s!="")temp.push_back(s);
    return temp;
}


vector<string> toPoland(const string& str) {
    stack<string> st;
    vector<string> temp =strToVector(str);
    vector<string> res(0);

    for (int i = 0; i < temp.size(); i++) 
    {               
        if (temp[i] == "(") st.push(temp[i]);
        else if (temp[i] == ")")
        {
            while (st.top() != "(")
            {
                res.push_back(st.top());
                st.pop();
            }
            st.pop();
        }
        else if (temp[i] == "+")
        {
            while (!st.empty() && (st.top() == "+" || st.top() == "-" || st.top() == "*" || st.top() == "/"))
            {
                res.push_back(st.top());
                st.pop();
            }
            st.push("+");
        }
        else if (temp[i] == "-")
        {
            while (!st.empty() && (st.top() == "+" || st.top() == "-" || st.top() == "*" || st.top() == "/"))
            {
                res.push_back(st.top());
                st.pop();
            }
            st.push("-");
        }
        else if (temp[i] == "*")
        {
            while (!st.empty() && (st.top() == "*" || st.top() == "/"))
            {
                res.push_back(st.top());
                st.pop();
            }
            st.push("*");
        }
        else if (temp[i] == "/")
        {
            while (!st.empty() && (st.top() == "*" || st.top() == "/"))
            {
                res.push_back(st.top());
                st.pop();
            }
            st.push("/");
        }
        else res.push_back(temp[i]);
        
    }

    while (!st.empty()) {
        res.push_back(st.top());
        st.pop();
    }
    return res;
}

auto operations(double a, double b, string op)
{
    
    if (op == "+") return a + b;
    if (op == "-") return a - b;
    if (op == "*") return a * b;
    if (op == "/") return a / b;
    
}
double solv(const string& str)
{
    vector<string> polandString = toPoland(str);
    stack<double> st;
    for (int i=0;i<polandString.size();i++)
    {
        if (polandString[i] == "(" || polandString[i] == ")" || polandString[i] == "+" || polandString[i] == "-" || polandString[i] == "*" || polandString[i] == "/")
        {
            double num2 = st.top();
            st.pop();
            double num1 = st.top();
            st.pop();
            string op = polandString[i];
            st.push(operations(num1, num2, op));
        }
        else
        {            
            double number = stof(polandString[i]);
            st.push(number);
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