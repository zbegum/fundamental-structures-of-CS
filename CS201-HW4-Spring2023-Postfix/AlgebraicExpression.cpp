/**
* Title: Algebraic Expression
* Author : Zeynep Begum Kara
* ID: 22003880
* Section : CS201 - 2
* Homework : 4
*/

#include <stack>
#include <iostream>
using namespace std;

bool isOperand(int asciiVal){ return 47 < asciiVal; }

bool isPrecedent(int op1, int op2){
    if((op1 == 42 || op1 == 47) && (op2 == 43 || op2 == 45)) {return false;}
    else{ return true; }
}
string infix2postfix ( const string exp ){
    stack<int> operatorStack;
    string postfixExpression = "";

    for (int i = 0; exp[i] != '\0'; i++) {
        int temp = exp[i];

        if (isOperand(temp)) {
            postfixExpression += (char)temp;
        }
        else if (temp == 40) { //'('
            operatorStack.push(temp);
        }
        else if (temp == 41) { //')'
            while (!operatorStack.empty() && operatorStack.top() != 40) {
                postfixExpression += (char)operatorStack.top();
                operatorStack.pop();
            }
            if (!operatorStack.empty() && operatorStack.top() == 40) {
                operatorStack.pop();
            }
        }
        else { //is operator
            while (!operatorStack.empty() && operatorStack.top() != 40 && isPrecedent(temp, operatorStack.top())) {
                postfixExpression += (char)operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.push(temp);
        }
    }

    while (!operatorStack.empty()) {
        postfixExpression += (char)operatorStack.top();
        operatorStack.pop();
    }

    return postfixExpression;
}

double evaluatePostfix(const string exp) {
    stack<double> operandStack;
    double operandOne;
    double operandTwo;

    for (int i = 0; exp[i] != '\0'; i++) {
        char expAdded = exp[i];

        if (isOperand(expAdded)) {
            operandStack.push(expAdded - 48); // char to int
        }
        else {
            operandOne = operandStack.top();
            operandStack.pop();
            operandTwo = operandStack.top();
            operandStack.pop();

            double result = 0;
            if (expAdded == 43) {   // '+'
                result = operandTwo + operandOne;
            }
            else if (expAdded == 45) {  // '-'
                result = operandTwo - operandOne;
            }
            else if (expAdded == 42) {  // '*'
                result = operandTwo * operandOne;
            }
            else if (expAdded == 47) {   // '/'
                result = operandTwo / operandOne;
            }

            operandStack.push(result);
        }
    }

    return operandStack.top();
}







