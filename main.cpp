#include "util.h"



void __init__(){
    Imagine::openWindow(512,512);
}

void __update__(){

}

void __draw__(){

}




int main(){
    Imagine::noRefreshBegin();
    __init__();
    Imagine::Timer t;
    while(true){
        __update__();
        __draw__();

        double x = t.lap();
        if(x < 1/fps) Imagine::milliSleep(1000*(1/fps - x));
        t.reset();
    }
    Imagine::noRefreshEnd();
    Imagine::endGraphics();
    return 0;
}
