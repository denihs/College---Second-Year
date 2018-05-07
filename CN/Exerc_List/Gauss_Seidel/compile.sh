#!/usr/bin/env bash
gcc -c DinamicAlocation.c -o DinamicAlocation.o &&
gcc -c gaussSeidel.c -o gaussSeidel.o -std=c11 &&
gcc DinamicAlocation.o gaussSeidel.o -o gaussSeidel &&
./gaussSeidel