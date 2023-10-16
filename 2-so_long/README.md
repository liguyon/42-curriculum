# so_long (WIP)

Our initial dive into graphics programming with a 2D top-down minigame.

## TODO
- parse map valid path
- add assets: collectible
- render map
- collectibles
- enemies w/ anmimation & patrol
- player w/ animations
- side panel for text infos
- add readme preview

## Overview

Kyky is transported during his sleep to a dungeon. Naked and powerless, he must climb the floors, avoiding skeletons and collecting coins to unlock the doors and escape.

### Features
- **Simple controls**: Kyky can use his feets to run and hide. That's all.

- **Skeletons are deadly**: Even a single attack from a skeleton can kill Kyky. He is only human after all.

- **Patrolling enemies**: Enemies will patrol their assigned areas. If Kyky enters their line of sight, they will pursue him. 

In so_long, touching enemies is fatal. The goal is to collect all the coins while staying hidden from enemies. Use the game mechanics to your advantage to help Kyky escape and regain his dignity.

## Build

### Dependencies

- [MinilibX](https://github.com/42Paris/minilibx-linux)  
`git clone https://github.com/42Paris/minilibx-linux.git lib/minilibx-linux`

### Compile

- `make all`

## Usage

`./so_long assets/maps/file.ber`

### Controls

Shortcut | Action
:---: | ---
`w`, `a`, `s`, `d` | Move
`Space` | Shout

## Credits

- [Medieval fantasy character sprite](https://opengameart.org/content/lpc-medieval-fantasy-character-sprites) by [wulax](https://opengameart.org/users/wulax), Creative Commons license
- [Dungeon Tileset](https://opengameart.org/content/dungeon-tileset) by [Buch](https://opengameart.org/users/buch)
- [Good Neighbors font](https://opengameart.org/content/good-neighbors-pixel-font) by [Clint Bellanger](https://opengameart.org/users/clint-bellanger)