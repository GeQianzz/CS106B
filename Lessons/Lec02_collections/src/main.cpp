/*#include "console.h"*/
#include "hashmap.h"
#include "strlib.h"
#include <fstream>
#include <iostream>

using namespace std;

int main() {
    HashMap<string, int> count;

    ifstream input;
    input.open("bible.txt");
    if (input.fail()) {
        cout << "oops" << endl;
        return 0;
    }

    string word;
    while (input >> word) {
        word = toLowerCase(word);
        if (!count.containsKey(word)) {
            count.put(word, 1);
        } else {
            count[word] += 1;
        }
    }

    for (string s : count) {
        if (count[s] >= 1000) {
            cout << s << ": " << count[s] << endl;
        }
    }

    while(true){
        cout << "search for: " << endl;
        string search;
        cin >> search;
        if(search == "q"){
            break;
        }

        cout << search << ": " << count[search] << endl;
    }

    input.close();
    return 0;
}
