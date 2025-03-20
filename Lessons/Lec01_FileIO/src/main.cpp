#include <iostream>
#include <fstream> 
using namespace std;

int main(){
    ifstream input;
    input.open("test.txt");

    if(input.fail()){
        cout << "oops" << endl;
    }

    string word;
    while(input >> word){
        cout << word << " ";
    }

    return 0;
}
