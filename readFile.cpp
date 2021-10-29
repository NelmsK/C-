#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std; 

int main(int argc, char const *argv[])
{
	// Step 1: open a file 
	ifstream inFile(argv[1]); //input file stream; name of thaf file comes from argument vector (argv) and it will be the FIRST argument ([1]); 

	// step 2: create a place to store the line you've read in
	string line; 

	unsigned int lineNumber = 0; //(unsigned because there WON'T be any negative file lines) variable to keep track of line numbers 
	// step 3: go into a loop reading lines 
	while (getline(inFile, line))  //as long as I'm able to aquire a line, using getline to parse info (2 parameters: file stream variable and line--variable to which we want to store the string we read from the file)
	{
		lineNumber++; //increment line number counting variable 
		cout << lineNumber << ":   " << line << endl; //prints the line number followed by the line from the input file 
	}
	
	
	
	return 0; 
}