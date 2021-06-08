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
<img width=90%
     src="https://github.com/swot3563941/my_project/blob/main/images/start.png">
<img width=90%
     src="https://github.com/swot3563941/my_project/blob/main/images/aproaching.png">
<img width=90%
     src="https://github.com/swot3563941/my_project/blob/main/images/escape.png">
## Key challenges
