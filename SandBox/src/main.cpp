#include <iostream>
#include <fstream>

using namespace std;

int main(){
    std::locale::global(std::locale(""));
    std::wcout.imbue(std::locale(""));

    wifstream input;
    input.open("中文测试.txt");
    
    wchar_t ch;
    while (input.get(ch)){
        wcout << ch << " ";
    }

    input.close();
    return 0;
}
