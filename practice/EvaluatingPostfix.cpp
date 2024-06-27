#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Function to check if a character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to evaluate postfix expression
int evaluatePostfix(string exp) {
    stack<int> stack;

    for (char &c : exp) {
        if (isdigit(c)) {
            stack.push(c - '0'); // exp is string (it should be string to store +-*/) so convert to int if digit
        } else if (isOperator(c)) {
            // Operator encountered, pop two operands from stack
            int operand2 = stack.top();
            stack.pop();
            int operand1 = stack.top();
            stack.pop();

            // Evaluate based on the operator
            if (c == '+') {
                stack.push(operand1 + operand2);
            } else if (c == '-') {
                stack.push(operand1 - operand2);
            } else if (c == '*') {
                stack.push(operand1 * operand2);
            } else if (c == '/') {
                stack.push(operand1 / operand2);
            } else {
                cerr << "Invalid operator encountered: " << c << endl;
                return -1;
            }
        }
    }

    // Result is on top of the stack
    return stack.top();
}

int main() {
    string exp;
    cout << "Enter a postfix expression: ";
    cin >> exp;

    int result = evaluatePostfix(exp);
    cout << "Result: " << result << endl;

    return 0;
}
