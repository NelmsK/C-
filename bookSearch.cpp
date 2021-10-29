///////////////////////////////////////////////////////////////////////
//                                                                     
// Filename: bookSearch.cpp
// Date: September 4, 2021
// Programmer: Kristen Nelms           
//
// Description:
//    Description of what the code in the file is meant to do and 
//    how it does what it is meant to do.
/////////////////////////////////////////////////////////////////////////

#include "bookSearch.h"

int main()
{
    ifstream inFile; //declare file stream variable 
    inFile.open("book.dat");
    Book books[45];
    int noOfBooks = 0;
    int loc;
    Book bookObj;
    int bookCount = 0; 
    string title = ""; 
    int titleLoc = 0; 
    string ISBN = ""; 
    int ISBNloc = 0; 

    if (!inFile) //if input file cannot be opened, terminate the program 
    {
        cout << "Cannot open the input file."
            << endl;
        return 1;
    }
    for (int index = 0; index < noOfBooks; index++)
    {
        books[index].getBookData(inFile, books, noOfBooks);
    }   

    cout << "++++++ Welcome to the Online Book Repository ++++++" << endl;
    int choice; //variable to store the selection made by the user 

    showMenu(); //calling function to show menu selection to user
    cin >> choice; // store choice entered by user in variable choice 

    while (choice != 3)
    {
        if (choice == 1)
        {
            for (int index = 0; index < noOfBooks; index++)
            {
                books[index].printBookData(books, noOfBooks);
                choice++; //increment choice variable by 1 to proceed to sorting options
            }
        }
        else if (choice == 2)
        {
            bookObj.searchBookData(books, noOfBooks);
        }
        else if (choice == 3) //exit menu loop
        {
            break;
        }
        else
        {
            cout << "Invalid user input. Please try again." << endl;
        }
        //if user inputs incorrectly, show selection again and get new choice 
        showMenu();
        cin >> choice;
    }
    inFile.close();

    return 0;
} //end of main

 