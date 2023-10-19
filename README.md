# so_long
https://github.com/dardangerguri/RandomThings/assets/117037140/5774ef81-377c-40b4-b3fc-3f85a7ac8ce2
## About the project
The so_long project at Hive (42 school) is a 2D game development project that introduces us to graphics programming using the Minilibx library. Its purpose is to make us work with textures, sprites, and some other very basic gameplay elements.

"so_long" is a simple game where the player navigates through a maze while collecting collectibles and avoiding obstacles. The goal is to reach the exit to win the game.

In the mandatory segment of the game, player is a thief. The core mission of the player is to gather coins throughout the maze. Victory is achieved when all coins have been collected, and the player stands at the exit door.

The bonus segment, in addition to coin collection and exit door navigation, player must avoid an enemy patrol, a police car. Moreover, the exit door in this stage is animated. It unlocks only after all collectibles have been collected.

Floodfill algorithm is used to validate the maze's navigability, ensuring a possible path for the player to collect all the collectibles and reach the exit.

## Play the game
#### Install
``` bash
git clone git@github.com:dardangerguri/so_long.git so_long
cd so_long
```
To compile manadatory part:
```bash
make
```
To compile the bonus part:
```bash
make bonus
```
Run the game:
```bash
./so_long valid_map.ber
```
#### Maps
You will be able to play the game with any map, that follows the rules below:
* is a ``.ber`` file, 
* only contains 1 -Wall, 0 - Empty space, C - Collectible, E - Exit, P - Player, and D - Enemy.
* is sorrounded by walls,
* has only one player, exit, and enemy (optional),
* and at least one collectible.

There are some valid maps, in the [`maps`](maps) directory!

#### Controls
To move the player use the ``WASD`` keys. The player will move on all the directions, expect on through the walls.
