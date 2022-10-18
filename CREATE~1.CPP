
// creation of new file and write content inside file in c++
#include <iostream.h>
#include <fstream.h>
#include<conio.h>
void main()
{
ofstream myfile("newfile2.txt");      // file is created in bin folder , pls check file in bin folder
cout<<"Hi,welcome to Amity University";  // content is written in newfile2.txt
myfile.close();                                           //close the file
getch();
}
