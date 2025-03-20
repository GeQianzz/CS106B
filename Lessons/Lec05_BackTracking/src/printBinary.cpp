#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void printAllBinaryHelper(int n, queue<vector<int>> &res) {
    if (n == 0) {
    } else {
        int size = res.size();
        if (size == 0) {
            vector<int> tmpA, tmpB;
            tmpA.push_back(0);
            tmpB.push_back(1);
            res.push(tmpA);
            res.push(tmpB);
        }
        for (int i = 0; i < size; i++) {
            vector<int> tmp = res.front();
            res.pop();
            vector<int> tmpA = tmp;
            vector<int> tmpB = tmp;
            tmpA.push_back(0);
            tmpB.push_back(1);
            res.push(tmpA);
            res.push(tmpB);
        }
        printAllBinaryHelper(n - 1, res);
    }
}

void printAllBinary(int n) {
    queue<vector<int>> res;
    printAllBinaryHelper(n, res);
    int size = res.size();
    for (int i = 0; i < size; i++) {
        vector<int> tmp = res.front();
        res.pop();
        int length = tmp.size();
        for (int t = 0; t < length; t++) {
            cout << tmp[t] << " ";
        }
        cout << endl;
    }
}


void printBinaryHelper(int digits, string output){
    if(digits == 0){
        cout << "helper " << digits << ": " << output << endl;
    }
    else{
        printBinaryHelper(digits - 1, output + "0");
        printBinaryHelper(digits - 1, output + "1");
    }
}

void printBinary(int digits){
    printBinaryHelper(digits, "");
}



int main_printB() {
    printAllBinary(10);
    return 0;
}
