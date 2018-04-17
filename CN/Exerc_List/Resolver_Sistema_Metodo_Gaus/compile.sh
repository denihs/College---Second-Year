gcc -c DinamicAlocation.c -o DinamicAlocation.o &&
gcc -c Resolver_Determinante.c -o Resolver_Determinante.o -std=c11 &&
gcc DinamicAlocation.o Resolver_Determinante.o -o Resolver_Determinante &&
./Resolver_Determinante