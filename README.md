
![image](https://github.com/xhelp00/so_long/assets/111277585/8a9f13ae-f9e0-4c09-8beb-44fd2aedfbf9)

The Game
- The player’s goal is to collect every collectible present on the map, then escape chosing the shortest possible route.
- The W, A, S, and D keys (or arrow keys) must be used to move the main character.
- The player should be able to move in these 4 directions: up, down, left, right.
- The player should not be able to move into walls.
- At every move, the current number of movements must be displayed in the shell.
- You have to use a 2D view (top-down or profile).
- The game doesn’t have to be real time.

Maps
- The map has to be constructed with 3 components: walls, collectibles, and free space.
- The map can be composed of only these 5 characters:
	- 0 for an empty space,
	- 1 for a wall,
	- C for a collectible,
	- E for a map exit,
	- P for the player’s starting position.
- The map must contain 1 exit, at least 1 collectible, and 1 starting position to be valid.
- Here is a simple valid map:

![image](https://github.com/xhelp00/so_long/assets/111277585/ee48b858-22cd-40bb-ae7d-d74b83eff845)
- The map must be rectangular.
- The map must be closed/surrounded by walls. If it’s not, the program must return an error.
- You have to check if there’s a valid path in the map.
- You must be able to parse any kind of map, as long as it respects the above rules.
- Map file has to be *.ber 

Bonus
- Make the player lose when they touch an enemy patrol.
- Add some sprite animation.
- Display the movement count directly on screen instead of writing it in the shell.

***********************************************
HOW TO make MLX42 library working (spec 42Prague) 

This might be handy in case you decide to use MLX42 in your project (so_long or FdF or fract-ol or any other)

1. ask staff to run sudo apt
➜  ~ sudo apt update
➜  ~ sudo apt install build-essential libx11-dev libglfw3-dev libglfw3 xorg-dev 
2. git clone https://github.com/codam-coding-college/MLX42.git
3. cmake -DCMAKE_C_COMPILER=/usr/bin/gcc -DCMAKE_CXX_COMPILER=/usr/bin/g++ -B build
4. cmake --build build -j4
5. result is file libmlx42.a in a build folder of MXL42
6. try to compile together with test program using all these flags
gcc test.c libmlx42.a -Iinclude -ldl -lglfw -pthread -lm
7. when you run ./a.out you should get the gui running

other details here:
https://github.com/codam-coding-college/MLX42

#########################################################################################

Compile with minilibx
gcc main.c libmlx.a -L/usr/include/../lib -lXext -lX11 -lm -lbsd

*******************************************************
1. Create STDIN Error Checker  - must have 2 STDIN Arguments, ./so_long and the Map with Extension .ber
2. Create Map Checker 
	1. - check that each Line has the Same Length 
	2. - check that the Map is a Rectangle  
	3. - check that a P, C, and E exists  
	4. - check that there are Walls surrounding the Map  
	5. - check that there are not any other Characters except P,C,E, 1 and 0;
	6. - check that there is a valid path *consider flood-fill  
3. Initialize MLX, Creating the Window  
4. Designing and Finding the Images  
5. Converting Images to xpm42 * xpm->xpm42 convertor is in MLX42 tools
6. Display the Pixel Art on the corresponding Map Coordinates  
7. Mapping the Keys to the Game  
8. Create the Rules  
9. Free Allocated Memmory

&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
MLX42 compiled successfully on Mac (not M1)
- followed steps on https://github.com/codam-coding-college/MLX42
- when did cmake - B build got warning on missing glfw - even tho the cmake seemed to install it, it was missing
- then install it manually by: brew install glfw
- again:
~ cmake -B build 
~ cmake --build build -j4 
- important is the flag -Iinclude -lglfw (works even without -framework Cocoa -framework OpenGL -framework IOKit)
- make sure you have Xcode installed and updated

******************************************************
MLX42 compile on Linux: cc test.c libmlx42.a -Iinclude -ldl -lglfw -pthread -lm
MLX42 compile on Mac: cc test.c libmlx42.a -Iinclude -lglfw
******************************************************
checking leaks in detail:
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./so_long

