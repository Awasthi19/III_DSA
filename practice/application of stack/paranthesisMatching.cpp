#include <iostream>
#include <stack>
#include <string>

bool isMatchingPair(char opening, char closing) {
    if (opening == '(' && closing == ')')
        return true;
    else if (opening == '{' && closing == '}')
        return true;
    else if (opening == '[' && closing == ']')
        return true;
    else
        return false;
}

bool isBalancedParentheses(const std::string& expression) {
    std::stack<char> stack;
    for (char ch : expression) {
        if (ch == '(' || ch == '{' || ch == '[') {
            stack.push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (stack.empty() || !isMatchingPair(stack.top(), ch)) {
                return false;
            } else {
                stack.pop();
            }
        }
    }
    return stack.empty();
}

int main() {
    std::string expression;
    std::cout << "Enter an expression: ";
    std::cin >> expression;

    if (isBalancedParentheses(expression)) {
        std::cout << "Parentheses are balanced." << std::endl;
    } else {
        std::cout << "Parentheses are not balanced." << std::endl;
    }

    return 0;
}