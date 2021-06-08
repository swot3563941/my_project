#ifndef __FOLLOWER__
#define __FOLLOWER__

#include "enviro.h"
#include <math.h>
#include <iostream>

using namespace enviro;
int  TOTAL_NUM = 0;


// The follower controller class used to control follower.
class FollowerController : public Process, public AgentInterface {

    public:
    // Inherite Process, AgentInterface
    FollowerController() : Process(), AgentInterface() {}

    // Initialize to watch leader position
    void init() {
        goal_x = 0;
        goal_y = 0;
        watch("goal_change", [this](Event e) {
            goal_x = e.value()["x"];
            goal_y = e.value()["y"];
        });
    }
    // Nothing to do in start
    void start() {}

    // Update to track leader, and teleport in some condition
    void update() {
        if(sqrt((goal_x-position().x)*(goal_x-position().x)+(goal_y-position().y)*(goal_y-position().y))>std::max(distance*2,100.0)){
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
    // Nothing to do when stop
    void stop() {}

    // Setting the following distance
    void set_distance(double input){
        distance = input;
        return;
    }

    double goal_x, goal_y;
    double distance;

};


// Follower class to follwe leader
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