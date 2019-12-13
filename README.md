# BlockJumpAI

A Flappy Bird clone that plays itself and gets better with time.

Made for a COMP6065 (Artificial Intelligence) group project.

## Disclaimers
- Code quality probably stinks worse than a septic tank
- The game window steals focus every time it opens
- There is no way of stopping the program outside of killing it or waiting for it to finish

## Learning method

4-variable Linear Regression

The variables are:
1. Distance to the next wall
2. Position of hole in the next wall
3. Distance to ground
4. Vertical speed

### The actual process
The AI makes a choice every frame and stores a history of the latest 1000 (arbitrarily chosen number) choices it made.
Every time the AI crashes itself into something, it finds the latest non-optimal choice it made and uses it as a data point.

e.g. When the AI crashes above the pipe hole, it looks through its history of choices and finds the latest jump it made, and uses that as an SGD data point.


## Libraries used
[simple2d](https://github.com/simple2d/simple2d) - for 2D graphics

## Credits
- Everyone in the group for their help and ideas
- Whichever god / deity / ancestor / whatever gave me the big brain moment that led to this project
