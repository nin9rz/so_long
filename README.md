# so_short

A project i made during my cursus at 42Angoulême

![Screenshot from 2025-04-07 14-33-51](https://github.com/user-attachments/assets/57256e75-7075-4c78-a281-59f1cd068232)

## Table of Contents
1. [Installation](#installation)
2. [Run the project](#runtheproject)
3. [The project](#theproject)


# Installation

To install so_short, you have to clone this repo on your computer using the following command : 
  https://github.com/nin9rz/so_long.git
After that, you just have to install the minilibx (the graphic library i used to code this game) available on this page :
  https://github.com/42Paris/minilibx-linux 
Then you'll have the project on your computer and you just have to run it !

# Run so_short

To run so_short, you just have to type "make" in your terminal in the main folder. It should compile the files correctly.
After that all you have to do is to write "./so_long maps/*whatever map you want*" in your terminal and now you can play !!
You're free to create a map if you want to :)

# The project

So_long is a project where you have to code a little 2D game from a map designed like this : 

1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111

'1' are the walls.
'0' are the parts of the floor.
'P' is the player position when the game is starting.
'C' are the collectibles.
'E' is the exit of the map.

In your terminal, the number of mooves that you've made is displayed and updated everytime you change you position on the map.
To finish a map you have to take every collectible on the map and use the exit. 
To make this obvious, i designed a close box for the exit wich stays closed is you don't take all the collectibles on the map. 
If you take all the collectibles, the texture of the box changes and now you have an opened cardboard box wich means that you can take the exit.

I hope you liked this project, i think i'll make one at home if i have the time because i'd like to make a better version.
