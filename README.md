# BlockJumpAI

A Flappy Bird clone that plays itself.

Made for a COMP6065 (Artificial Intelligence) group project.

## Disclaimers
- Code quality probably stinks worse than a septic tank
- The game window steals focus every time it opens
- There is no way of stopping the program outside of killing it or waiting for it to finish

## Branches
- *preset-values*: Default branch, pre-trained instance.
- *training*: No graphics for faster training.
- *master*: Live training, buggy
- *gui*: Play it yourself
- *ai*: Useless old branch

## Running this project
***Windows is not supported!***

Requirements:
- CMake version 3.14 or better
- GCC with C++17 support
- [simple2d](https://github.com/simple2d/simple2d)

Compilation:
1. Clone the repo into a folder
2. Navigate to said folder
3. Run CMake on it
4. Execute the compiled file

## Learning method

4-variable Single-layer Perceptron

The variables are:
1. Distance to the next wall
2. Position of hole in the next wall
3. Distance to ground
4. Vertical speed

### The actual process
The AI makes a choice every frame and stores a history of the latest 1000 (arbitrarily chosen number) choices it made.
Every time the AI crashes itself into something, it finds the latest non-optimal choice it made and uses it for SGD.

e.g. When the AI crashes above the hole in the pipe, it looks through its history of choices and finds the latest jump it made, and uses that as an SGD data point.


## Libraries used
[simple2d](https://github.com/simple2d/simple2d) - for 2D graphics

## Credits
- Everyone in the group for their help and ideas
- Whichever god / deity / ancestor / whatever gave me the big brain moment that led to this project
