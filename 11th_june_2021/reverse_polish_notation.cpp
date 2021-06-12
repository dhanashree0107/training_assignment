/*
problem Statement : write a program to evaluate reverse polish notation
Date: 12/06/2021

Reverse Polish notation (RPN), also known as Polish postfix notation or 
simply postfix notation, is a mathematical notation in which operators follow 
their operands

*/

#include <iostream>
#include <stack>
using namespace std;
 
int evalPostfix(string exp)
{
    // create an empty stack
    stack<int> stack;
 
    // traverse the given expression
    for (int i = 0; i < exp.length(); i++)
    {
        if (exp[i] >= '0' && exp[i] <= '9') {            // if the current character is an operand, push it into the stack
            stack.push(exp[i] - '0');
        }
        else {                                          // if the current character is an operator
            int x = stack.top();
            stack.pop();                                // remove the top two elements from the stack
 
            int y = stack.top();
            stack.pop();
 
            // evaluate the expression x op y, and push the
            // result back to the stack
            if (exp[i] == '+') {
                stack.push(y + x);
            }
            else if (exp[i] == '-') {
                stack.push(y - x);
            }
            else if (exp[i] == '*') {
                stack.push(y * x);
            }
            else if (exp[i] == '/') {
                stack.push(y / x);
            }
        }
    }
 
    // At this point, the stack is left with only one element, i.e.,
    // expression result
    return stack.top();
}
 
int main()
{
    string exp;
    cout<<"Enter the expression: ";
    cin>>exp;
    cout << evalPostfix(exp);
 
    return 0;
}
