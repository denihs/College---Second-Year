#!/usr/bin/env bash
gcc -c DinamicAlocation.c -o DinamicAlocation.o &&
gcc -c Calc_Determinante.c -o Calc_Determinante.o -std=c11 &&
gcc DinamicAlocation.o Calc_Determinante.o -o Calc_Determinante &&
./Calc_Determinante