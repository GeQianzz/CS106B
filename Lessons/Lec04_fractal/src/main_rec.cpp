#include <gwindow.h>
using namespace std;

void fractal(GWindow& gw, int x, int y, int size, int order){
    if(order >= 0) {
        fractal(gw, x - size/4, y - size/4, size/2, order - 1);
        fractal(gw, x + size/4*3, y + size/4*3, size/2, order - 1);
        gw.fillRect(x, y, size, size);
        fractal(gw, x + size/4*3, y - size/4, size/2, order - 1);
        fractal(gw, x - size/4, y + size/4*3, size/2, order - 1);
    }
}

int main(){
    GWindow gw(1000, 500);
    gw.setTitle("Title");
    fractal(gw, 500, 250, 100, 3);
    return 0;
}
