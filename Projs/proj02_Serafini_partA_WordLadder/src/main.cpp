#include "filelib.h"
#include "lexicon.h"
#include "queue.h"
#include "stack.h"
#include "strlib.h"
#include <iostream>

using namespace std;

void printHello() {
    cout << "=========================================================" << endl;
    cout << "Welcome to CS 106B Word Ladder." << endl;
    cout << "Please give me two English words, and I will change the" << endl;
    cout << "first into the second by changing one letter at a time." << endl;
    cout << "=========================================================" << endl;
    cout << endl;
}

void deduceFindNeighbours(Lexicon &dict, Lexicon &appeared,
                          Queue<Stack<string>> &q) {
    Stack<string> s = q.dequeue();
    string word = s.peek();
    int size = word.size();
    for (int i = 0; i < size; i++) {
        for (int t = 0; t < 26; t++) {
            string neighbour = word;
            neighbour[i] = 'a' + t;
            if (neighbour != word && dict.contains(neighbour) &&
                !appeared.contains(neighbour)) {
                Stack<string> possible = s;
                possible.push(neighbour);
                q.enqueue(possible);
                appeared.add(neighbour);
            }
        }
    }
}

void printRes(Queue<Stack<string>> &q) {
    Stack<string> s = q.dequeue();
    while (s.size() >= 2) {
        cout << s.pop() << " -> ";
    }
    cout << s.pop() << endl;
}

int main() {

    printHello();

    // load dictionary
    string dict_name;
    while (true) {
        cout << "Please Input Dictionary File Name: " << endl;
        cin >> dict_name;
        if (fileExists(dict_name)) {
            break;
        } else {
            cout << "Unable to open that file. Try again." << endl;
        }
    }
    Lexicon dict;
    dict.addWordsFromFile(dict_name);

    while (true) {
        // get two words
        string word1, word2;
        cout << "please input two words, or input 'q' to quit." << endl;
        cout << "please input word1" << endl;
        cin >> word1;
        if (word1 == "q")
            break;
        cout << "Please input word2" << endl;
        cin >> word2;
        if (word2 == "q")
            break;

        if (word1 == word2) {
            cout << "ERROR: The two words must be Different!" << endl << endl;
            continue;
        }

        if (word1.size() != word2.size()) {
            cout << "ERROR: The two words must be the Same Length" << endl
                 << endl;
            continue;
        }

        if (!dict.contains(word1) || !dict.contains(word2)) {
            cout << "ERROR: The two words must be Found in the dictionary."
                 << endl
                 << endl;
            continue;
        }

        word1 = toLowerCase(word1);
        word2 = toLowerCase(word2);

        // initialize
        Queue<Stack<string>> searchQue;
        Stack<string> possibleStack;
        possibleStack.push(word1);
        searchQue.enqueue(possibleStack);

        // search
        Lexicon appeared;
        while (!searchQue.isEmpty()) {
            if (searchQue.peek().peek() == word2) {
                break;
            } else {
                deduceFindNeighbours(dict, appeared, searchQue);
            }
        }

        if (searchQue.isEmpty()) {
            cout << "No word ladder found from azure back to metal." << endl;
        } else {
            printRes(searchQue);
        }
    }

    cout << "Have a Nice Day!" << endl;
    return 0;
}
