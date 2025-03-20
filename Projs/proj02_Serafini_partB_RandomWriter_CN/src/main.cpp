#include "fstream"
#include "hashmap.h"
#include "map.h"
#include "queue.h"
#include "vector.h"
#include <fstream>
#include <iostream>

using namespace std;

// Find the most frequent next Word.
wchar_t findFreq(HashMap<Vector<wchar_t>, Vector<wchar_t>> &countMap,
                 Vector<wchar_t> &key) {
    Vector<wchar_t> resVec = countMap[key];
    Map<wchar_t, int> freqMap;
    int maxFreq = 0;
    wchar_t res;
    for (wchar_t word : resVec) {
        freqMap[word] += 1;
        srand((time(0)));
        if (freqMap[word] > maxFreq) {
            maxFreq = freqMap[word];
            srand(time(0));
            int min = 0;
            int max = 100;
            int poss = rand() % (max - min);
            if (poss > 10) {
                res = word;
            }
        }
    }
    return res;
}

void printMap(HashMap<Vector<wchar_t>, Vector<wchar_t>> &countMap) {
    for (Vector<wchar_t> item : countMap) {
        cout << item << ": " << countMap[item] << endl;
    }
    for (Vector<wchar_t> item : countMap) {
        cout << item << ": (freq)" << findFreq(countMap, item) << endl;
    }
}

void randomWriting(HashMap<Vector<wchar_t>, Vector<wchar_t>> &countMap, int n) {
    // random init
    srand((time(0)));
    int min = 0;
    int max = countMap.keys().size() - 1;
    int randKeyNum = min + (rand() % (max - min + 1));
    Vector<wchar_t> init = countMap.keys().get(randKeyNum);

    if (!countMap.containsKey(init)) {
        wcout << "There's No such init word" << endl;
        return;
    }

    for (wchar_t item : init) {
        wcout << item;
    }
    for (int i = 0; i < n; i++) {
        wchar_t nextWord = findFreq(countMap, init);
        wcout << nextWord;
        init.remove(0);
        init.add(nextWord);
    }
}

int main() {
    // setting
    std::locale::global(std::locale(""));
    std::wcout.imbue(std::locale(""));

    // Read file
    wifstream input;
    input.open("res/刘慈欣作品集.txt");
    if (input.fail()) {
        wcout << "oops" << endl;
        return 1;
    }

    // input N-Gram
    int nGram;
    while (true) {
        wcout << "Please input N-Gram" << endl;
        cin >> nGram;
        if (nGram < 2) {
            wcout << "N-Gram should be >= 2" << endl;
        } else {
            break;
        }
    }

    // initialization
    HashMap<Vector<wchar_t>, Vector<wchar_t>> countMap;
    Queue<wchar_t> winQue;

    // Read word
    wchar_t word;
    while (input >> word) {
        if (winQue.size() < nGram - 1) {
            winQue.enqueue(word);
        } else {
            Queue<wchar_t> cpQue = winQue;
            Vector<wchar_t> keyVector;
            for (wchar_t item : cpQue) {
                keyVector.add(cpQue.dequeue());
            }
            countMap[keyVector].add(word);
            winQue.dequeue();
            winQue.enqueue(word);
        }
    }

    while (true) {
        int repeatNum;
        wcout << "Input Repeat Num: " << endl;
        cin >> repeatNum;
        if (repeatNum <= nGram) {
            wcout << "RepeatNum should greater than nGram" << endl;
            continue;
        }
        randomWriting(countMap, repeatNum);
        wcout << endl;
    }

    input.close();
    return 0;
}
