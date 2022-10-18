//Read the content of file 

#include <iostream.h>
#include <fstream.h>
#include<conio.h>
void main() {

	ifstream my_file;                            //input file stream
	my_file.open("newfile2.txt", ios::in);  //open mode of the file 
	if (!my_file) { 
		cout << "No such file";
	}
	else {
		char ch;
		while (1) {
			my_file>> ch;
			if (my_file.eof())
				break;
			cout << ch;     
		}
	}
	my_file.close();
	getch();
}