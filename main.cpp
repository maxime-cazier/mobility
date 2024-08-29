#include "pieton.h"
#include "iostream"



int main(){
    Imagine::openWindow(512,512);
    Pieton p(430,300,10,5,-20,-3);
    RectangleObstacleList RectObs = RectangleObstacleList();
    CircleObstacleList CircObs = CircleObstacleList();

    //RectObs.AddRectangleObstacle(200,150,200,200);
    CircObs.AddCircleObstacle(200,200,100);

    Imagine::Timer t;
    while(true){
        p.Erase();
        p.Draw();
        RectObs.draw();
        CircObs.draw();

        p.UpdatePos(RectObs,CircObs);
        double l = t.lap();
        if(l < 1/fps) Imagine::milliSleep(1000*(1.0/fps - l));
        t.reset();
    }
    Imagine::noRefreshEnd();
    Imagine::endGraphics();
    return 0;
}
