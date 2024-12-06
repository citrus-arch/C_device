
/*make file commands. no comment shud be der
a.exe: p1.o p1_main.o
	gcc p1.o p1_main.o
p1.o: p1.c p1.h
	gcc -c p1.c
p1_main.o: p1_main.c p1.h
	gcc -c p1_main.c

mingw32-make -f p1.mk*/

#include <stdio.h>
// program to print a 2D array in C
int main()
{
int i;
char a[]={'C',' ','P','r','o','g','r','a','m','m','i','n','g','\0'};
char b[]="C Programming";  //14. bcoz null is default
printf("sizeof a is %d\n",sizeof(a));
printf("sizeof b is %d\n",sizeof(b));

char a2[]={'a','t','m','a'};
printf("sizeof a2 is %d\n",sizeof(a2));

char a3[]="atma";
printf("sizeof a3 is %d\n",sizeof(a3));

char a4[10]={'a','t','m','a'}; //partial initialization. not all elements size utilized
printf("sizeof a4 is %d\n",sizeof(a4));

char a5[10]="atma";
printf("sizeof a5 is %d\n",sizeof(a5));

char a6[10]={'a','t','m','a','\0'};
printf("sizeof a6 is %d\n",sizeof(a6));

char a7[]={'a','t','m','a','\0','t','r','i','s','h','a','\0'};
printf("sizeof a7 is %d\n",sizeof(a7));
for(i=0;i<sizeof(a7);i++)
printf("%c",a7[i]);
printf("\n");

char a8[]="atma\\0";
printf("sizeof a8 is %d\n",sizeof(a8));
for(i=0;i<sizeof(a8);i++)
printf("%c",a8[i]);
printf("\n");

char a9[]="at\0ma"; //at ma. each element is unique so \ and 0 different. bcoz \0 are in middle
printf("sizeof a9 is %d\n",sizeof(a9)); //6
for(i=0;i<sizeof(a9);i++)
printf("%c",a9[i]);
printf("\n"); 
return 0;
} 


/*int main()
{
char str1[]={'a','t','m','a','t','r','i','s','h','a','\0'};
int i=0;
while(str1[i]!='\0')
{
	printf("%c",str1[i]);
	i++;
}
return 0;
}*/

/*int main()
{
char str3[100];
printf("enter the string ");
scanf("%s",str3);
printf("%s\n",str3); //reads til the null character(space)
}*/

/*int main()
{
char str6[100];
printf("enter the string ");
scanf("%[^\n]s",str6); //read input until newline met
printf("%s\n",str6); 
}*/


/*int main()
{
char str6[100];
printf("enter ur name ");
scanf("%[abcd]s",str6); //read input until newline met
printf("u entered %s\n",str6); 
}*/
a
/*int main()
{
char str7[100];
printf("enter the string ");
scanf("%[^abcd]s",str7); //negate abcd. shud not strt with abcd
printf("u entered %s\n",str7); 
}/*