#include "pieton.h"
#include "iostream"
#include "stdlib.h"



int main(){
    Imagine::openWindow(512,512);
    RectangleObstacleList RectObs = RectangleObstacleList();
    CircleObstacleList CircObs = CircleObstacleList();
    PietonList Piet = PietonList();
    RectangleObstacleList Exit = RectangleObstacleList();

    //RectObs.AddRectangleObstacle(200,150,200,200);
    RectObs.AddRectangleObstacle(0,0,12,512);
    RectObs.AddRectangleObstacle(0,0,200,12);
    RectObs.AddRectangleObstacle(300,0,212,12);
    RectObs.AddRectangleObstacle(0,500,512,12);
    RectObs.AddRectangleObstacle(500,0,12,512);

    Exit.AddRectangleObstacle(200,0,100,12);

    //CircObs.AddCircleObstacle(200,200,100);
    //for(int i = 0; i < 3 ; i ++){
    //    for(int j = 0; j < 5; j++){
    //        Piet.AddPieton(20 + 30*i, 300 + 30*i, std::rand()%10 + 5, std::rand()%10 + 5,0,0,0,std::rand()%20 + 5,0);
    //    }
    //}


    //Piet.AddPieton(150,300,10,10,0,0,0,20,-20);
    //Piet.AddPieton(300,200,10,20,0,0,0,-20,0);
    //Piet.AddPieton(400,100,10,20,0,0,0,-20,0);
    Piet.AddPieton(100,100,10,20,0,0,0,-20,0);
    Imagine::Timer t;
    while(true){
        Piet.draw();
        RectObs.draw();
        CircObs.draw();
        Exit.draw_as_exit();
        Piet.Updatespeed(RectObs,CircObs);



        Piet.Updatepos(RectObs,CircObs,Exit);

        double l = t.lap();
        if(l < 1/fps) Imagine::milliSleep(1000*(1.0/fps - l));
        t.reset();
    }
    Imagine::noRefreshEnd();
    Imagine::endGraphics();
    return 0;
}
