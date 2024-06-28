#!/bin/bash

SRC_DIR="src"
INCLUDE_DIR="$SRC_DIR/include"
OBJ_DIR="objects"
C_FLAGS=" -Lwin-raylib/lib -Iwin-raylib/include -lraylib -lopengl32 -lgdi32 -lwinmm"
CC=x86_64-w64-mingw32-gcc

mkdir -p $OBJ_DIR

for file in $SRC_DIR/*.c; do
	$CC -c $file -I $INCLUDE_DIR -o "$OBJ_DIR/$(basename $file .c).o" -Wall $C_FLAGS
done

$CC $OBJ_DIR/*.o -o main.exe $C_FLAGS

rm -r $OBJ_DIR
