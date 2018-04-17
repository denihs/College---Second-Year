#!/usr/bin/env bash
gcc -c DinamicAlocation.c -o DinamicAlocation.o &&
gcc -c Matriz_Inversa.c -o Matriz_Inversa.o -std=c11 &&
gcc DinamicAlocation.o Matriz_Inversa.o -o Matriz_Inversa &&
./Matriz_Inversa