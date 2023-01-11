#!/bin/bash

#################### Variables Makefile ###################
NAME="Containers"
CC="clang++"
CFLAGS="-Wall -Werror -Wextra  -std=c++98"
INCLUDE="../main.cpp"

# cd ..

################### Make with ft ###################
echo "compiling with FT"
make="$CC $CFLAGS $INCLUDE -DLIB=ft -o $NAME"
${make}

echo "compilation FT done"

./Containers > result_ft

################### Make with std ################### 
echo "compiling with STD"

make="$CC $CFLAGS $INCLUDE -DLIB=std -o $NAME"
${make}

echo "compilation STD done"

./Containers > result_std

diff result_ft result_std > result_diff


rm -f -r Containers result_ft result_std
