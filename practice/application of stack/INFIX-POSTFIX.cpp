#include <iostream>
#include <stack>
#include <string>

bool isOperator(char token) {
    return token == '+' || token == '-' || token == '*' || token == '/';
}

int precedence(char token) {
    if (token == '+' || token == '-') {
        return 1;
    } else if (token == '*' || token == '/') {
        return 2;
    }
    return 0;
}

std::string infixToPostfix(const std::string& infix) {
    std::string postfix;
    std::stack<char> operatorStack;

    for (char token : infix) {
        if (isOperator(token)) {
            while (!operatorStack.empty() && precedence(operatorStack.top()) >= precedence(token)) {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.push(token);
        } else if (token == '(') {
            operatorStack.push(token);
        } else if (token == ')') {
            while (operatorStack.top() != '(') {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.pop();
        } else {
            postfix += token;
        }
    }

    while (!operatorStack.empty()) {
        postfix += operatorStack.top();
        operatorStack.pop();
    }

    return postfix;
}

int main() {
    std::string infixExpression;
    std::cout << "Enter an infix expression: ";
    std::cin >> infixExpression;

    std::string postfixExpression = infixToPostfix(infixExpression);
    std::cout << "Postfix expression: " << postfixExpression << std::endl;

    return 0;
}