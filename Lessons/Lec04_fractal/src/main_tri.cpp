#include "gwindow.h"
#include <cmath>
using namespace std;

void drawSierpinskiTriangle(GWindow &gw, double x, double y, double size,
                            int order) {
    if (order == 0) {

    } else {
        gw.drawLine(x, y, x + size, y);
        gw.drawLine(x, y, x + 0.5 * size, y + sqrt(3) / 2 * size);
        gw.drawLine(x + size, y, x + 0.5 * size, y + sqrt(3) / 2 * size);
        drawSierpinskiTriangle(gw, x, y, size / 2, order - 1);
        drawSierpinskiTriangle(gw, x + size / 2, y, size / 2, order - 1);
        drawSierpinskiTriangle(gw, x + size / 4, y + sqrt(3) / 4 * size,
                               size / 2, order - 1);
    }
}

void drawTree(GWindow &gw, double x, double y, double size, int order){
    if(order == 0) {

    } else if (order == 1){
        gw.drawLine(x + size / 2, y + size, x + 0.5 * size, y + 0.5 * size);
    } else {
        
    }
}



int main_tree() {
    GWindow gw(1000, 800);
    /*drawTree(gw, 100, 100, 500, 1);*/
    gw.drawPolarLine(100, 100, 500, -45);

    return 0;
}
