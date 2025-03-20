#include "fstream"
#include "hashmap.h"
#include "map.h"
#include "queue.h"
#include "vector.h"
#include <iostream>
using namespace std;

// Find the most frequent next Word.
string findFreq(HashMap<Vector<string>, Vector<string>> &countMap,
                Vector<string> &key) {
    Vector<string> resVec = countMap[key];
    Map<string, int> freqMap;
    int maxFreq = 0;
    string res;
    for (string word : resVec) {
        freqMap[word] += 1;
        srand((time(0)));
        if (freqMap[word] > maxFreq) {
            maxFreq = freqMap[word];
            res = word;
        }
    }
    return res;
}

void printMap(HashMap<Vector<string>, Vector<string>> &countMap) {
    for (Vector<string> item : countMap) {
        cout << item << ": " << countMap[item] << endl;
    }
    for (Vector<string> item : countMap) {
        cout << item << ": (freq)" << findFreq(countMap, item) << endl;
    }
}

void randomWriting(HashMap<Vector<string>, Vector<string>> &countMap, int n) {
    srand((time(0)));
    int min = 0;
    int max = countMap.keys().size();
    int randKeyNum = min + (rand() % (max - min + 1));
    Vector<string> init = countMap.keys().get(randKeyNum);
    if (!countMap.containsKey(init)) {
        cout << "There's No such init word" << endl;
        return;
    }
    cout << "...";
    for (string item : init) {
        cout << item << " ";
    }
    for (int i = 0; i < n; i++) {
        string nextWord = findFreq(countMap, init);
        cout << nextWord << " ";
        init.remove(0);
        init.add(nextWord);
    }
    cout << "..." << endl;
}

int main() {
    // Read file
    ifstream input;
    input.open("res/刘慈欣作品集.txt");
    if (input.fail()) {
        cout << "oops" << endl;
    }

    // initialization
    HashMap<Vector<string>, Vector<string>> countMap;
    Queue<string> winQue;

    // input N-Gram
    int nGram;
    while (true) {
        cout << "Please input N-Gram" << endl;
        cin >> nGram;
        if (nGram < 2) {
            cout << "N-Gram should be >= 2" << endl;
        } else {
            break;
        }
    }

    // Read word
    string word;
    while (input >> word) {
        if (winQue.size() < nGram - 1) {
            winQue.enqueue(word);
        } else {
            Queue<string> cpQue = winQue;
            Vector<string> keyVector;
            for (string item : cpQue) {
                keyVector.add(cpQue.dequeue());
            }
            countMap[keyVector].add(word);
            winQue.dequeue();
            winQue.enqueue(word);
        }
    }

    while (true) {
        int repeatNum;
        cout << "Input Repeat Num: " << endl;
        cin >> repeatNum;
        if(repeatNum <= nGram) {
            cout << "RepeatNum should greater than nGram" << endl;
            continue;
        }
        randomWriting(countMap, repeatNum);
        cout << "==============================================" << endl;
    }

    input.close();
    return 0;
}

