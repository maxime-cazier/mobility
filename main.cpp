#include "pieton.h"
#include "iostream"



int main(){
    Imagine::openWindow(512,512);
    Pieton p(150,150,10,5,20,3);
    RectangleObstacleList RectObs = RectangleObstacleList();
    std::cout << RectObs.get_L() << std::endl;
    RectObs.AddRectangleObstacle(500,0,12,512);
    std::cout << RectObs.get_L() << std::endl;
    RectangleObstacle Rect = RectObs.get_ith_obstacle(0);
    std::cout << Rect.get_width() << std::endl;
    Imagine::Timer t;
    while(true){
        p.Erase();
        p.Draw();
        RectObs.draw();
        p.UpdatePos(RectObs);
        double l = t.lap();
        if(l < 1/fps) Imagine::milliSleep(1000*(1.0/fps - l));
        t.reset();
    }
    Imagine::noRefreshEnd();
    Imagine::endGraphics();
    return 0;
}
