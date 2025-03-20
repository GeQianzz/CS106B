#include <iostream>
#include <recursion.h>
#include <vector.h>
/*#include <console.h>*/
using namespace std;

int calls = 0;

void diceSumHelper(int dice, int desiredSum, Vector<int> chosen) {
    calls++;
    if (dice == 0) {
        // cout desired result
        if (desiredSum == 0) {
            cout << chosen << endl;
        }
    } else if (desiredSum >= dice * 1 && desiredSum <= dice * 6){
        for (int i = 1; i <= 6; i++) {
            // choose i
            chosen.add(i);

            // explore the remaining decisions which comes after i
            diceSumHelper(dice - 1, desiredSum - i, chosen);

            // unchoose i -> backtracking
            chosen.remove(chosen.size() - 1);
        }
    }
}

void diceSum(int dice, int desiredSum) {
    Vector<int> chosen;
    diceSumHelper(dice, desiredSum, chosen);
}

int main_dice() {
    diceSum(4, 4);
    cout << "total calls: " << calls << endl;

    return 0;
}
