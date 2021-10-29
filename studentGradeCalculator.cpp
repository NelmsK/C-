///////////////////////////////////////////////////////////////////////
//                                                                     
// Filename: studentGradeCalculator.cpp
// Date: September 4, 2021
// Programmer: Kristen Nelms           
//
// Description:
//    Write a C++ program that reads the following student input data
//(student.dat) into an array of Student c - struct objects.Provide a function in the
//program that can calculate the student’s final grade based on the following
//criteria :
//Midterm = 25 %, Final Exam = 25 % andLabs = 50 %
//
//The format of the file is as follows :
//STUDENT_NAME 
		   // MIDTERM_EXAM  FINAL_EXAM 
 //LAB1 LAB2 LAB3 LAB4 
//
//• The program should display a summary of all the final grades in
//main().
//
//For example, Joe Doe’s final grade is 89.475 % (grade : A) and Derrick
//Myer’s final grade is 91.85 (grade: A).
//
//HINT:  All data members should be public.No non - constant data should be
//declared globally.
/////////////////////////////////////////////////////////////////////////

#include "studentGradeCalculator.h"

/*Function Prototypes*/
void getData(ifstream& inFile, Students List[], int listSize);
void calculateGrade(Students List[], int listSize);
void print(const Students List[], int listSize);

int main()
{
	ifstream inFile; //input stream variable 
	inFile.open("student.dat"); //opening "student.dat" file 

	if (!inFile) // error message if unable to open input file 
	{
		cout << "Cannot open the input file."
			<< endl;
		return 1;
	}
	
	Students List[18]; //Defining student array to hold student objects (used 18 to account for total 18 lines in student.dat)
	getData(inFile, List, 6); //calling getData function to retrieve student data
	calculateGrade(List, 6); //calling calculateGrade function to calculate average and determine letter grade based on said avg 
	print(List, 6); //calling print function to output results 
	inFile.close(); //closing input file 

	return 0;
}

void getData(ifstream& inFile, Students List[], int listSize)
//reads student data from input file and stores appropriate information in the Student list array
{
	int n = 0; //arbitrary count variable 
	while (n < listSize)
	{
		string line = ""; //variable to store lines parsed from "student.dat"
		getline(inFile, line); //retrieve entire line from text file 
		istringstream iss(line); // string class object which is used to stream the string into different variables
		//parsing name information (as some students have middle initial; whereas, others dont
		if (line != "") {
			int numName = 1; //intialize "first" name
			do
			{
				std::string name;
				iss >> name;
				if (numName == 1)
					List[n].firstName = name; //parse first text file name entry into designated "first name" slot
				else if (numName == 2) //parse second text file name entry into designated "middle initial" slot
					List[n].middleInitial = name;
				else if (numName == 3) //parse third text file name entry into designated "surname" slot
					List[n].lastName = name;
				numName++; //increments number of names until reaching end of file 
			
			} while (!iss.eof()); //while NOT at the end of the file... 

			// means only 2 words were entered... example first and last
			if (numName == 3) {
				List[n].lastName = List[n].middleInitial;
				List[n].middleInitial = "";
			}
			//getting grades for each of the students
			inFile >> List[n].midtermExam;
			inFile >> List[n].finalExam;
			inFile >> List[n].lab1;
			inFile >> List[n].lab2;
			inFile >> List[n].lab3;
			inFile >> List[n].lab4;

			n++;//Increment counter
		}

	}

}


void calculateGrade(Students studentArray[], int listSize)
// calculates student average for each student and then uses that to discern their respective letter grade
{
	int i;

	for (i = 0; i < listSize; i++)
	{
		//Midterm = 25 % of avg, Final Exam = 25 % of avg, and Labs = 50 % of total avg
		studentArray[i].avg = ((studentArray[i].midtermExam * .25) + (studentArray[i].finalExam * .25) + (((studentArray[i].lab1 + studentArray[i].lab2 + studentArray[i].lab3 + studentArray[i].lab4) / 4) * 0.50));

		//using calculated average to then determine student's letter grade
		if (studentArray[i].avg < 60)

			studentArray[i].grade = 'F';

		else if (studentArray[i].avg < 70)

			studentArray[i].grade = 'D';

		else if (studentArray[i].avg < 80)

			studentArray[i].grade = 'C';

		else if (studentArray[i].avg < 90)

			studentArray[i].grade = 'B';

		else
			studentArray[i].grade = 'A';
	}
}

void print(const Students List[], int listSize)
//output statement with student's name, their respective average, and their letter grade based on that average 
{
	string name; //holds name value to restring individual "pieces" of name back together 
	int i; //counter

	for (i = 0; i < listSize; i++)
	{
		name = List[i].firstName + " " + List[i].middleInitial + " " + List[i].lastName;
		cout << name << "'s final grade is " << List[i].avg << "% (grade: " << List[i].grade << ")" << endl;
	}
}