# so_short<br>
<br>
A project i made during my cursus at 42Angoulême<br>
<br>
![Screenshot from 2025-04-07 14-33-51](https://github.com/user-attachments/assets/57256e75-7075-4c78-a281-59f1cd068232)<br>
<br>
## Table of Contents<br>
1. [Installation](#installation)<br>
2. [Run the project](#runtheproject)<br>
3. [The project](#theproject)<br>
<br>
<br>
# Installation<br>
<br>
To install so_short, you have to clone this repo on your computer using the following command : <br>
<br>
  https://github.com/nin9rz/so_long.git<br>
<br>
After that, you just have to install the minilibx (the graphic library i used to code this game) available on this page :<br>
<br>
  https://github.com/42Paris/minilibx-linux <br>
<br>
Then you'll have the project on your computer and you just have to run it !<br>
<br>
# Run so_short
<br>
To run so_short, you just have to type "make" in your terminal in the main folder. It should compile the files correctly.<br>
After that all you have to do is to write "./so_long maps/*whatever map you want*" in your terminal and now you can play !!<br>
You're free to create a map if you want to :)<br>
<br>
# The project
<br>
So_long is a project where you have to code a little 2D game from a map designed like this : <br>
<br>
1111111111111<br>
10010000000C1<br>
1000011111001<br>
1P0011E000001<br>
1111111111111<br>
<br>
'1' are the walls.<br>
'0' are the parts of the floor.<br>
'P' is the player position when the game is starting.<br>
'C' are the collectibles.<br>
'E' is the exit of the map.<br>
<br>
In your terminal, the number of mooves that you've made is displayed and updated everytime you change you position on the map.<br>
To finish a map you have to take every collectible on the map and use the exit. <br>
To make this obvious, i designed a close box for the exit wich stays closed is you don't take all the collectibles on the map. <br>
If you take all the collectibles, the texture of the box changes and now you have an opened cardboard box wich means that you can take the exit.<br>
<br>
I hope you liked this project, i think i'll make one at home if i have the time because i'd like to make a better version.<br>
