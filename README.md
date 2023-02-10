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
