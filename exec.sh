#!/bin/bash

make
gcc -o 00 main.c libftprintf.a
./00 > tests