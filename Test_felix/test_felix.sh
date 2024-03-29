#!/bin/bash

#################### Variables Makefile ###################
NAME="Containers"
CC="c++"
CFLAGS="-Wall -Werror -Wextra  -std=c++98"
INCLUDE="../main.cpp 
	 ../srcs_main/vec_constructors.cpp
	 ../srcs_main/vec_assign.cpp
	 ../srcs_main/vec_pushpop.cpp
	 ../srcs_main/vec_resize.cpp
	 ../srcs_main/vec_insert.cpp
	 ../srcs_main/vec_modifiers.cpp
	 ../srcs_main/map_size.cpp
	 ../srcs_main/map_insert.cpp
	 ../srcs_main/map_bounds.cpp
	 ../srcs_main/map_erase.cpp
	 ../srcs_main/map_iterators.cpp

	 "

# cd ..

################### Make with ft ###################
echo "compiling with FT"
make="$CC $CFLAGS $INCLUDE -DLIB=ft -o $NAME" 
#-fsanitize=leak -fsanitize=address
${make}

echo "compilation FT done"

#valgrind --leak-check=full --track-origins=yes
./Containers > result_ft

################### Make with std ################### 
echo "compiling with STD"

make="$CC $CFLAGS $INCLUDE -DLIB=std -o $NAME"
${make}

echo "compilation STD done"

#valgrind
./Containers > result_std

diff result_ft result_std > result_diff

#rm -f -r Containers result_ft result_std
