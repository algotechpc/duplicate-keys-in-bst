
// Reading of file in C
#include <iostream.h>
#include <fstream.h>
#include<conio.h>
#include<String.h>
#include<stdio.h>
void main()
{
FILE *fp;
fp= fopen("newfile2.txt","r");

if(!fp)
{
cout<<"No such file"; }
else {
char ch;
while((ch= fgetc(fp))!=EOF)
{
printf("%c",ch);
}
}
fclose(fp);
getch();
}