// Filename: NelmsLab01.h
// Date: August 28, 2021
// Programmer: Kristen Nelms           
//
// Description:
//    This program prompts the user to enter student name, student ID, exam-1 grade, exam-2 grade, final exam grade, lab grade and homework grade for a total of 5 students. 
//    The final weighted grade is then calculated, three bonus points are added, and the output is parsed into two text files: "pass.txt" and "fail.txt" based on student average 
/////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////
//
// Structure: students                                          
//                                                                   
// Description:
//    //Students structure created to hold the following data/members for 5 total students: student name, student ID, exam-1 grade, exam-2 grade, final exam grade, lab grade and homework grade.        
//
//    List of data members: string name, int ID{}, double exam1{}, exam2{}, final{}, lab{}, homework{}, avg{};                                       
// 
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
//
// Function: void getDetails(students& student)                                         
//                                                                   
// Description:
//    function to retrieve student name, student ID, exam-1 grade, exam-2 grade, final exam grade, lab grade and homework grades for the 5 total students via user input
//
// Parameters:  
//    students& student: struct variable of type students; used to allocate memory to store student data and pass as reference between functions       
//                 
//                                                                    
//                                            
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
//
// Function: double calculateFinalGrade(students& student)                                        
//                                                                   
// Description:
//    calculate the preliminary final semester grade for each individual student
//
// Parameters:  
//    students& student: struct variable of type students; used to allocate memory to store student data and pass between functions        
//
// Returns:  
//    avg: calculated, weighted final semester grade BEFORE adding bonus 3 points           
//                                            
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
//
// Function: double giveBonus(students& student)                                        
//                                                                   
// Description:
//    function to give students an additional 3 pts added to their final grade; however, students cannot exceed 100 total points
//
// Parameters:  
//    students& student: struct variable of type students; used to allocate memory to store student data and pass as reference between functions                 
//
// Returns:  
//    student.avg: (accesses avg structure member from students structure) and returns MODIFIED final semester grade with bonus points added (or just returns value of 100 if student's score were to exceed 100 points)            
//                                            
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
//
// Function: void writeToFile(students& student, ofstream& outPass, ofstream& outFail)                                        
//                                                                   
// Description:
//    function to retrieve student name, student ID, exam-1 grade, exam-2 grade, final exam grade, lab grade and homework grades for the 5 total students via user input
//
// Parameters:  
//    students& student: struct variable of type students; used to allocate memory to store student data and pass as reference  between functions     
//    ofstream& outPass: creates and writes to "pass.txt" file in main() function and then passed as reference to writeToFile function
//    ofstream& outFail: creates and writes to "fail.txt" file in main() function and then passed as reference to writeToFile function
//                                                                    
//                                            
///////////////////////////////////////////////////////////////////////


#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

struct students
    //Students structure created to hold the following data for 5 students: student name, student ID, exam-1 grade, exam-2 grade, final exam grade, lab grade and homework grade.
{
    string name; //student's name 
    int ID{}; //student's ID 
    double exam1{}, exam2{}, final{}, lab{}, homework{}, avg{}; //student's avgs for components needed to calc final grade
};
