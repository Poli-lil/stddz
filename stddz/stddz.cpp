#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool isValid(const string& expression)
{
    stack<char> brackets;

    for (char ch : expression)
    {
        if (ch == '(' || ch == '[' || ch == '{')
        {
            brackets.push(ch);
        }
        else if (ch == ')' || ch == ']' || ch == '}')
        {
            if (brackets.empty())
            {
                return false;
            }
            char top = brackets.top();

            if ((ch == ')' && top != '(') ||
                (ch == ']' && top != '[') ||
                (ch == '}' && top != '{'))
            {
                return false;
            }

            brackets.pop();
        }
    }

    return brackets.empty();
}

int main()
{
    string expression;

    while (true)
    {
        cout << "Введіть рядок (exit для виходу): ";
        getline(cin, expression);

        if (expression == "exit")
        {
            break;
        }

        if (isValid(expression))
        {
            cout << "Коректно" << '\n';
        }
        else
        {
            cout << "Ошибка" << '\n';
        }
    }
}