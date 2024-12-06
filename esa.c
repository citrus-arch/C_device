#include<stdio.h>
#include<stddef.h>
union A
{ int x; int y[2]; int z; };
int main()
{
union A a1; a1.z = 100;
printf("%d %d %lu\n", a1.y[0],offsetof(union A,y[0]), offsetof(union A,y[1]) );
return 0;
}
		


