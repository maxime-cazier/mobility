#include "pieton.h"
#include "iostream"



int main(){
    Imagine::openWindow(512,512);
    Pieton p(200,200,10,5,3,3);
    RectangleObstacleList RectObs = RectangleObstacleList();
    Imagine::Timer t;
    while(true){
        p.Draw();
        p.UpdatePos(RectObs);
        std::cout << p.get_x() ;

        double x = t.lap();
        if(x < 1/fps) Imagine::milliSleep(1000*(1/fps - x));
        t.reset();
    }
    Imagine::noRefreshEnd();
    Imagine::endGraphics();
    return 0;
}
