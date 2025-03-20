#include <cctype>
#include <cmath>
#include <fstream>
#include <iostream>
/*#include <sstream>*/
#include <string>
/*#include "console.h"*/
#include "filelib.h"
#include "grid.h"
#include "gwindow.h"
/*#include "simpio.h"*/
#include "strlib.h"
#include "lifegui.h"
/*#include "vector.h"*/
using namespace std;

void sayHello();
void getGridFromFile(string filename, Grid<char>& e);
void printGrid(Grid<char>& e, LifeGUI& gui);
int countNeighbours(Grid<char>& e, int currRow, int currCol, bool isWrap);
void evolve(Grid<char>& e, LifeGUI& gui, bool isWrap);
void animatedEvolution(Grid<char>& e, int times, LifeGUI& gui, bool isWrap);

int main() {
    sayHello();

    string filename;
    cout << "Please input you initial file name: " << endl;
    cin >> filename;
    Grid<char> earth;
    getGridFromFile(filename, earth);

    LifeGUI gui;
    gui.resize(earth.numRows(), earth.numCols());
    printGrid(earth, gui);

    bool isWrap = false;
    cout << "is Wrap? t)rue or f)alse" << endl;
    char isWrapOption;
    cin >> isWrapOption;
    if(isWrapOption == 't' || isWrapOption == 'T'){
        isWrap = true;
        cout << "isWrap = " << isWrap << endl;
    }
    else if(isWrapOption == 'f' || isWrapOption == 'F') isWrap = false;
    else {
        cout << "illegal input" << endl;
        return 0;
    }

    char modeOption;
    while(true){
        cout << "t)ick; a)nimate; q)uit" << endl;
        cin >> modeOption;
        if (modeOption == 't' || modeOption == 'T'){
            evolve(earth, gui, isWrap);
            printGrid(earth, gui);
            cout << endl;
        }
        else if (modeOption == 'a' || modeOption == 'A'){
            int times;
            cout << "Please Input animate Times: ";
            cin >> times;
            animatedEvolution(earth, times, gui, isWrap);
            cout << "animate finished" << endl;
        }
        else if (modeOption == 'q' || modeOption == 'Q'){
            break;
        }
        else{
            cout << "illegal input! Please input anain" << endl;
        }
    }

    cout << "Have a nice Life!" << endl;
    return 0;
}

void sayHello(){
    cout << "*==============================*" << endl;
    cout << "This is CS106B proj01 Life" << endl;
    cout << "Simulates the life evolution" << endl;
    cout << "author: geqian" << endl;
    cout << "*==============================*" << endl;
    cout << endl;
}

void getGridFromFile(string filename, Grid<char>& e){
    ifstream input;
    openFile(input, filename);
    if(input.fail()){
        cout << "File Not Exists." << endl;
    }

    // Read first two lines to Get Row nums and Col nums
    string line;
    getline(input, line);
    int numRows = stringToInteger(line);
    getline(input, line);
    int numCols = stringToInteger(line);

    // Get the grid
    e.resize(numRows, numCols);
    for(int i = 0; i < numRows; i++){
        getline(input, line);
        for(int t = 0; t < numCols; t++){
            e[i][t] = line[t];
        }
    }
}

void printGrid(Grid<char>& e, LifeGUI& gui){
    int nRows = e.numRows();
    int nCols = e.numCols();
    for (int i = 0; i < nRows; i++){
        for (int t = 0; t < nCols; t++){
            cout << e[i][t] << " ";
            if(e[i][t] == 'X') gui.drawCell(i, t, true);
            else gui.drawCell(i, t, false);
        }
        cout << endl;
    }
}

int countNeighbours(Grid<char>& e, int currRow, int currCol, bool isWrap){
    int count = 0;
    for(int i = currRow-1; i <= currRow+1; i++){
        for(int t = currCol-1; t <= currCol+1; t++){
            int row = i;
            int col = t;
            if(isWrap){
                row = (row + e.numRows()) % e.numRows();
                col = (col + e.numCols()) % e.numCols();
            }
            if(e.inBounds(row, col) && !(i == currRow && t == currCol) && e[row][col] == 'X'){
                count++;
            }
        }
    }
    return count;
}

void evolve(Grid<char>& e, LifeGUI& gui, bool isWrap){
    int count;
    int nRows = e.numRows();
    int nCols = e.numCols();
    Grid<char> temp = e;
    for(int i = 0; i < nRows; i++){
        for(int t = 0; t < nCols; t++){
            count = countNeighbours(e, i, t, isWrap);
            if(count == 2){}
            else if(count == 3){
                temp[i][t] = 'X';
                gui.drawCell(i, t, true);
            }
            else{
                temp[i][t] = '-';
                gui.drawCell(i, t, false);
            }
        }
    }
    e = temp;
}

void animatedEvolution(Grid<char> &e, int times, LifeGUI& gui, bool isWrap){
    for(int i = 0; i < times; i++){
        printGrid(e, gui);
        pause(50);
        evolve(e, gui, isWrap);
        /*clearConsole();*/
    }
}

