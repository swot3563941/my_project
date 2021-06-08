# Fish in the maze(filnal project)
This is my final project of embedded programming class. It is a combination of option 1(escaping maze) and option 3(leader and follower).

## Project description and goal
A small fish call bony is trying to get out of the maze. Bony is made by a blue head(leader) and red body(follower) following a tail(follower). Each of the followers is following by a different distance, so his body won't sqeeze all together. A maze is constructed by static objects, with a yellow goal that can free bony when he touches it. Bony will get stuck in some places sometimes, but don't worry, he will teleport himself to a new place after a few seconds. You can also help bonny by clicking the screen.

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
Then key in http://localhost/ on your browser. You will now seeing bony wandering around in the maze.

## How to use
## Key challenges
