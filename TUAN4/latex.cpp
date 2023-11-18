#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

bool isValidLatex(const string& expression) {
    stack<char> brackets;
    unordered_map<char, char> closingBrackets = {{'}', '{'}, {')', '('}, {']', '['}};

    for (char c : expression) {
        if (c == '{' || c == '(' || c == '[') {
            brackets.push(c);
        } else if (c == '}' || c == ')' || c == ']') {
            if (brackets.empty() || brackets.top() != closingBrackets[c]) {
                return false;
            }
            brackets.pop();
        }
    }

    return brackets.empty();
}

int main() {
    string expression;

    cout << "Enter a LaTeX expression: ";
    getline(cin, expression);

    if (isValidLatex(expression)) {
        cout << "The LaTeX expression is valid." << endl;
    } else {
        cout << "The LaTeX expression is invalid." << endl;
    }

    return 0;
}