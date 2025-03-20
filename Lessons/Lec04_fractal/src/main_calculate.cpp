#include "stack.h"
#include "strlib.h"
#include <iostream>
using namespace std;

int calculate(string &str) {
    int res = 0;
    Stack<int> num;
    Stack<char> op;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            num.push(charToInteger(str[i]));
        } else if (str[i] == '+') {
            op.push(str[i]);
        } else if (str[i] == '*') {
            i++;
            num.push(charToInteger(str[i]));
            num.push(num.pop() * num.pop());
        }
    }
    while(!op.isEmpty()){
        op.pop();
        num.push(num.pop() + num.pop());
    }
    res = num.pop();
    return res;
}

int calculate_quoted(string& str){
    string sub = str.substr(1, str.length() - 2);
    int res;
    if(str[0] == '('){
        res = calculate(sub);
    }
    return res;
}

int main_calcu() {
    string expression;
    cin >> expression;

    cout << calculate_quoted(expression) << endl;

    return 0;
}
