# Fish in the maze(final project)
This is my final project of embedded programming class. It is a combination of option 1(escaping maze) and option 3(leader and follower).

## Project goal
A small fish called bony is trying to get out of the maze. Bony is made by a blue head(leader) and red body(follower) following a tail(follower). The followers are following by different distances, so his body won't squeeze all together. A maze is constructed by static objects, with a yellow goal that can free bony when he touches it. Bony will get stuck in some places sometimes, but don't worry, he will teleport himself to a new place after a few seconds. You can also help bonny by clicking the screen.

## How to install and run
To install this project, please follow these steps on the terminal.
```bash
cd my_project
docker run -p80:80 -p8765:8765 -v $PWD:/source -it klavins/enviro:alpha bash
make clean
make
```
To run this project, please follow these steps on the terminal.
```bash
esm start
enviro
```
And you will see 'Listening on port 8765' on the terminal. 
Then go to http://localhost/ on your browser. You will now see bony wandering around in the maze.

## How to use
Basically bony can make his way out of the maze, he just needs some time. So you can do nothing but watch how he does it. If you want to participate, you can click the screen, bony will teleport to that location.
#### Advance usage
If you want to make the body of bony longer, you can modify the 'config.jason' file. You can add the following in the middle of the head and tail.
```c++
{
  "definition": "defs/Follower.json",
  "style": { "fill": "red", "stroke": "red" },
  "position": {
    "x": 100, 
    "y": 100, 
    "theta": 1
  }
}, 
```
#### How it looks like
(1) Bony wandering in the maze
<img width=90%
     src="https://github.com/swot3563941/my_project/blob/main/images/start.png">  
(2) Bony approaching the goal
<img width=90%
     src="https://github.com/swot3563941/my_project/blob/main/images/aproaching.png">  
(3) Bony escape the maze
<img width=90%
     src="https://github.com/swot3563941/my_project/blob/main/images/escape.png">  
## Key challenges

There are some key challenges when buliding this project.
#### Object get stock in places
- When more and more objects are created in the robot world. They are more likely to squeeze together and stock, since objects are basically moving by simple criteria. So I use the teleport function to solve this. When Bony is moving at a low speed for over a threshold of seconds, he will automatically teleport to a new location. Similarly his body will teleport when they are stock and far from the head.
#### The physical dynamics of enviro
- The enviro tries to mimic the physical dynamic of the real world, however weird things happen when using large or small values. For example, when I tried to set the mass of an object to 0.3, the object started rotating crazily, when I set it to an even smaller value, the enviro started to crash. And it also took a while to figure out a good combination of mass, friction and force, so that Bony can move smoothly. 
#### The inheritance of classes
- Most of the classes inherit the 'AgentInterface' class, this makes communication with the enviro simple. But at the same time it adds limitations to what you can do with the enviro. So you have to figure out a way to achieve your goal by a limited range of functions.

## Acknowedges
#### References
-https://github.com/tbonaciUW/EEP_520_Spring2021  
-https://www.w3schools.com/CPP/default.asp  
-http://klavinslab.org/elma/index.html  
-https://www.cplusplus.com/  
-https://stackoverflow.com/  
