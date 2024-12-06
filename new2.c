
/*make file commands. no comment shud be der
a.exe: p1.o p1_main.o
	gcc p1.o p1_main.o
p1.o: p1.c p1.h
	gcc -c p1.c
p1_main.o: p1_main.c p1.h
	gcc -c p1_main.c

mingw32-make -f p1.mk*/

#include <stdio.h>
int main()
{
printf("%d %f %f %f\n", 25 / 4, 25.0 / 4.0, 25.0 / 4, 25 / 4.0);
return 0;
}