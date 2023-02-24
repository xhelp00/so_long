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

*******************************************************
1. Create STDIN Error Checker  - must have 2 STDIN Arguments, ./so_long and the Map with Extension .ber
2. Create Map Checker 
	1. - check that each Line has the Same Length 
	2. - check that the Map is a Rectangle  
	3. - check that a P, C, and E exists  
	4. - check that there are Walls surrounding the Map  
	5. - check that there are not any other Characters except P,C,E, 1 and 0;  
3. Initialize MLX, Creating the Window  
4. Designing and Finding the Images  
5. Converting Images to .xml  
6. Display the Pixel Art on the corresponding Map Coordinates  
7. Mapping the Keys to the Game  
8. Create the Rules  
9. Free Allocated Memmory