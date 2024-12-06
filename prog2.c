#include <stdio.h>
int main()
/*{
int i,n,sum;
sum=0;
printf("enter a number: ");
scanf("%d",&n);
for (i=1;i<=n;i++)
{
sum=sum+i;
}
printf("sum:%d\n",sum);
return 0;
} */

{
int i;
printf("enter a no: ")
scanf("%d",&n);
for (i=
*/

//count number of words
{
int nl=0,nw=0,nc=0,inword=0;
char ch;
while((ch=getchar())!=EOF)
{
nc++;
if(ch=='\n')
nl++;
if(inword && (ch==''|| ch=='\n'|| ch=='\t'))
{
nw++;
inword=0;
}
else if(!(ch==' '||ch=='\n'||ch=='\t'))
inword=1;
}
printf("words= %d\ncharacters= %d\n",nw,nl,nc);
return 0;
}
