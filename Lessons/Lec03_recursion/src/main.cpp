#include <iostream>
#include <stack.h>
using namespace std;
const int height = 5;

void initTower(int height, Stack<int> &init) {
    int num = height;
    for (int i = 0; i < height; i++) {
        init.push(num);
        num--;
    }
}

void printTower(Stack<int> &start, Stack<int> &end, Stack<int> &mid) {
    cout << "======================" << endl;
    cout << start << endl;
    cout << mid << endl;
    cout << end << endl;
    cout << "======================" << endl;
}

void moveTower(int height, Stack<int> &start, Stack<int> &end, Stack<int> &mid) {
    if (height == 0) {

    } else if(height == 1){
        end.push(start.pop());
        printTower(start, end, mid);
    } else {
        moveTower(height - 1, start, mid, end);
        printTower(start, end, mid);
        moveTower(1, start, end, mid);
        printTower(start, end, mid);
        moveTower(height - 1, mid, end, start);
        printTower(start, end, mid);
    }
}

int main_tower() {
    Stack<int> a, b, c;
    initTower(height, a);
    moveTower(height, a, c, b);
    return 0;
}
