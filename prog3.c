
//count number of words
#include <stdio.h>
int main()
/*
{
int nl=0,nw=0,nc=0,inword=0;
char ch;
while((ch=getchar())!=EOF)
{
nc++;
if(ch=='\n')
nl++;
if(inword && (ch==' '|| ch=='\n'|| ch=='\t'))
{
nw++;
inword=0;
}
else if(!(ch==' '||ch=='\n'||ch=='\t'))
inword=1;
}
printf("words= %d\nlines= %d\ncharacters= %d\n",nw,nl,nc);
return 0;
}
*/

/*{
float a=23.5;
printf("%d %f %d %f\n",5,5.5,5.5,5.5);
printf("a is %d\n",a); //ud behaviour
printf("value is %s\n","50"); //proper behaviour
printf("value is %s\n",50); //ud behaviour
printf("%u %u %u\n",sizeof(int),sizeof(short int),sizeof(float)); //implementation defined behavour
int d=10;
printf("%d %d %d\n",d++,d++ - --d,--d);  //unspecified behaviour
return 0;
}
*/

{
int i,j,n,p,q;
printf("no of rows: ");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
if(i%2==0)
{
p=1;q=0;
}
else
{
p=0;q=1;
}
for(j=1;j<=i;j++)
if(j%2==0)
printf("%d",p);
else
printf("%d",q);
printf("\n");
}
}