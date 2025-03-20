#include <gwindow.h>
using namespace std;

void cantorSet(GWindow& gw, int x, int y, int length, int levels){
    if (levels == 0){ }
    else {
        cantorSet(gw, x+length*2/3, y+20, length/3, levels - 1);
        cantorSet(gw, x, y+20, length/3, levels - 1);
        gw.drawLine(x, y, x+length, y);
    }
}

int main_line(){
    GWindow gw(1000, 500);
    cantorSet(gw, 100, 100, 600, 15);
    return 0;
}
