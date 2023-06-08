
![image](https://github.com/xhelp00/so_long/assets/111277585/8a9f13ae-f9e0-4c09-8beb-44fd2aedfbf9)


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

