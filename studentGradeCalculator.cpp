// Filename: studentGradeCalculator.cpp
// Date: August 28, 2021
// Programmer: Kristen Nelms           
//
// Description:
//    This program prompts the user to enter student name, student ID, exam-1 grade, exam-2 grade, final exam grade, lab grade and homework grade for a total of 5 students. 
//    The final weighted grade is then calculated, three bonus points are added, and the output is parsed into two text files: "pass.txt" and "fail.txt" based on student average 
/////////////////////////////////////////////////////////////////////////

#include "NelmsLab01.h"

void getDetails(students& student)
//user input to retrieve student name, student ID, exam-1 grade, exam-2 grade, final exam grade, lab grade and homework grades for the 5 total students
{
    cout << "Enter student name: ";
    cin >> student.name;

    cout << "Enter student ID: ";
    cin >> student.ID;

    cout << "Enter their grade for the first exam: ";
    cin >> student.exam1;

    cout << "Enter their grade for the second exam: ";
    cin >> student.exam2;

    cout << "Enter their grade for the final exam: ";
    cin >> student.final;

    cout << "Enter their lab grade: ";
    cin >> student.lab;

    cout << "Enter their homework grade: ";
    cin >> student.homework;

    cout << "\n";

}

double calculateFinalGrade(students& student)
//calculate the preliminary final semester grade for each individual student
{
    double avg;

    avg = ((student.exam1 * .15) + (student.exam2 * .15) + (student.final * .20) + (student.lab * .40) + (student.homework * .10));

    return avg;
}

double giveBonus(students& student)
//function to give students an additional 3 pts added to their final grade; however, students cannot exceed 100 total points
{
    student.avg += 3;
    if (student.avg > 100)
    {
        student.avg = 100;
    }
    return student.avg;
}

void writeToFile(students& student, ofstream& outPass, ofstream& outFail)
//output student data to one of two text files based on their final avg
{  
    if (student.avg >= 60) //if the student's average is GREATER than or equal to 60, then output is directed to "pass.txt" file
    {
        outPass << fixed << showpoint; //sets output of floating-point # in fixed decimal format w/ decimal point & trailing zeros
        outPass << setprecision(2); //set precision to 2 decimal places for grades
        outFail << setfill(' ');

        outPass << student.name << setw(19) << student.ID << setw(16) << student.exam1 << setw(14) << student.exam2 << setw(16) << student.final << setw(17)
            << student.lab << setw(18) << student.homework << setw(17) << student.avg << endl;
    }
    else //if the student's average is LESS THAN 60, then output is directed to "fail.txt" file
    {
        outFail << fixed << showpoint;
        outFail << setprecision(2); //set precision to 2 decimal places for grades
        outFail << setfill(' ');

        //passing these values to "fail.txt" file
        outFail << student.name << setw(19) << student.ID << setw(16) << student.exam1 << setw(14) << student.exam2 << setw(16) << student.final << setw(17)
            << student.lab << setw(18) << student.homework << setw(17) << student.avg << endl;
    }
   
}

int main()
{
    students studentArray[5]; //array to hold the student's data 

    ofstream outPass; //output pass.txt file stream variable 
    ofstream outFail; //output fail.txt file stream variable 

    outPass.open("pass.txt", ios::out);  //create and open text file for students whose avg is GREATER than 60
    outFail.open("fail.txt", ios::out); //create and open text file for students whose avg is less than 60
            
    for (int i = 0; i < 5; i++) //iterate through the 5 total students
    {
        cout << "Enter details for student " << (i + 1) << endl;

        getDetails(studentArray[i]); //get information relating to the 5 students

        studentArray[i].avg = calculateFinalGrade(studentArray[i]); //calculate the final grade 

        studentArray[i].avg = giveBonus(studentArray[i]); //assign additional 3 bonus points, if necessary
    }

    outPass << "Student Name" << setw(15) << "Student ID" << setw(13) << "Exam 1" << setw(14) << "Exam 2" << setw(18) << "Final Exam" << setw(16)
        << "Lab Grade" << setw(20) << "Homework Grade" << setw(20) << "Adjusted Average" << endl;

    outFail << "Student Name" << setw(15) << "Student ID" << setw(13) << "Exam 1" << setw(14) << "Exam 2" << setw(18) << "Final Exam" << setw(16)
        << "Lab Grade" << setw(20) << "Homework Grade" << setw(20) << "Adjusted Average" << endl;

    for (int i = 0; i < 5; i++)
    {
        writeToFile(studentArray[i], outPass, outFail);
    }
    outPass.close(); //closing "pass.txt" file
    outFail.close(); //closing "fail.txt" file

    return 0;
}
