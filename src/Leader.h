#ifndef __LEADER__
#define __LEADER__

#include <string>
#include <math.h>
#include "enviro.h"

namespace {
    int direction = 0;
    using namespace enviro;

    class MovingForward : public State, public AgentInterface {
        public:
        void entry(const Event& e) {}
        void during() { 
            track_velocity(4,0);
            if ( sensor_value(1) < 40 ) {
                direction = 1; //right
                emit(Event(tick_name));
            } 
            else if ( sensor_value(2) < 40 ) {
                direction = 0; //left
                emit(Event(tick_name));
            } 
            else if ( sensor_value(0) < 10 ) {
                direction = rand() % 2; 
                emit(Event(tick_name));
            }            
        }
        void exit(const Event& e) {}
        void set_tick_name(std::string s) { tick_name = s; }
        std::string tick_name;
    };

    class Rotating : public State, public AgentInterface {
        public:
        void entry(const Event& e) { rate = direction == 0 ? 5 : -5; }
        void during() { 
            track_velocity(0,rate); 
            if ( sensor_value(0) > 70 ) {
                emit(Event(tick_name));
            }
        }
        void exit(const Event& e) {}
        double rate;
        void set_tick_name(std::string s) { tick_name = s; }
        std::string tick_name;        
    };

    class LeaderController : public StateMachine, public AgentInterface {

        public:
        LeaderController() : StateMachine() {

            set_initial(moving_forward);
            tick_name = "tick_" + std::to_string(rand()%1000); // use an agent specific generated 
                                                               // event name in case there are 
                                                               // multiple instances of this class
            add_transition(tick_name, moving_forward, rotating);
            add_transition(tick_name, rotating, moving_forward);
            moving_forward.set_tick_name(tick_name);
            rotating.set_tick_name(tick_name);

        }

        void init() {
            watch("screen_click", [this](Event e) {
                teleport(e.value()["x"], e.value()["y"], double(rand()%5-2)/5);
                emit(Event("goal_change", {
                    { "x", e.value()["x"] },
                    { "y", e.value()["y"] }
                }));
            });
            StateMachine::init();  
        }

        
        void update() {
            //if ( rand() % 100 <= 1 ) {
            //    emit(Event(tick_name));
            //}
            emit(Event("goal_change", {
                { "x", position().x },
                { "y", position().y }
            }));
            if(sqrt(velocity().x*velocity().x + velocity().y*velocity().y)<0.2){
                counter++;
            }
            else{
                counter=0;
            }
            if(counter>60){
                int x = rand() % 2 == 0 ? (rand() % 300) : -(rand() % 300);
                int y = rand() % 2 == 0 ? (rand() % 300) : -(rand() % 300);
                teleport(x, y, double(rand()%5-2)/5);
                counter=0;
            }
            if(sqrt((position().x-425)*(position().x-425) + (position().y+150)*(position().y+150))<30){
                teleport(650, -150, 0);
            }
            StateMachine::update();
        }
        

        MovingForward moving_forward;
        Rotating rotating;
        std::string tick_name;
        int counter = 0;

    };

    class Leader : public Agent {

        public:
        Leader(json spec, World& world) : Agent(spec, world) {
            add_process(wc);
        }

        LeaderController wc;

    };

    DECLARE_INTERFACE(Leader);

}

#endif