#include "pieton.h"
#include "iostream"



int main(){
    Imagine::openWindow(512,512);
    RectangleObstacleList RectObs = RectangleObstacleList();
    CircleObstacleList CircObs = CircleObstacleList();
    PietonList Piet = PietonList();

    //RectObs.AddRectangleObstacle(200,150,200,200);
    CircObs.AddCircleObstacle(200,200,100);
    Piet.AddPieton(350,194,10, 5, -20,0);
    Piet.AddPieton(310,200,10,5,0,0);
    Imagine::Timer t;
    while(true){
        Piet.draw();
        RectObs.draw();
        CircObs.draw();

        Piet.Updatepos(RectObs,CircObs);
        double l = t.lap();
        if(l < 1/fps) Imagine::milliSleep(1000*(1.0/fps - l));
        t.reset();
    }
    Imagine::noRefreshEnd();
    Imagine::endGraphics();
    return 0;
}
