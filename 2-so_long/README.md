# so_long (WIP)

Our initial dive into graphics programming with a 2D top-down game.

## TODO
- parse map valid path
- add assets: tileset, collectible
- render map
- collectibles w/ animation
- enemies w/ anmimation & patrol
- player w/ animations
- add readme preview

## Overview

Kyky is transported during his sleep to a dungeon. Naked and powerless, he must climb the floors, avoiding skeletons and collecting gems to unlock the doors and escape.

### Features
- **Simple controls**: Kyky can move and shout insults.

- **Skeletons are deadly**: Even a single attack from a skeleton can kill Kyky. He is only human after all.

- **Patrolling enemies**: Enemies will patrol their assigned areas. If Kyky enters their line of sight, they will attack.

- **Distract enemies**: Kyky is a certified thug. He can shout insults at enemies to distract and lure them.

In so_long, touching enemies is fatal. Use the game mechanics to your advantage to help Kyky escape and regain his dignity.

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