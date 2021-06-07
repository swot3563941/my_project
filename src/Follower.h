#ifndef __FOLLOWER__
#define __FOLLOWER__

#include "enviro.h"
#include <math.h>
#include <iostream>

using namespace enviro;
int  TOTAL_NUM = 0;

class FollowerController : public Process, public AgentInterface {

    public:
    FollowerController() : Process(), AgentInterface() {}

    void init() {
        goal_x = 0;
        goal_y = 0;
        watch("goal_change", [this](Event e) {
            goal_x = e.value()["x"];
            goal_y = e.value()["y"];
        });
    }
    void start() {}
    void update() {
        if(sqrt((goal_x-position().x)*(goal_x-position().x)+(goal_y-position().y)*(goal_y-position().y))>std::max(distance*2,200.0)){
            teleport(goal_x-distance*0.9, goal_y,0);
        }
        if(sqrt((goal_x-position().x)*(goal_x-position().x)+(goal_y-position().y)*(goal_y-position().y))>distance)
        //if(sensor_value(0)>distance)
        {
            move_toward(goal_x, goal_y, 25, 100);
        }
        else{
            damp_movement();
        } 
    }
    void stop() {}
    void set_distance(double input){
        distance = input;
        return;
    }

    double goal_x, goal_y;
    double distance;

};

class Follower : public Agent {
    public:
    Follower(json spec, World& world) : Agent(spec, world) {
        c.set_distance(TOTAL_NUM*12+15);
        TOTAL_NUM++;
        add_process(c);
    }
    private:
    FollowerController c;
};

DECLARE_INTERFACE(Follower)

#endif