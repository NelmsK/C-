#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>


using namespace std;

class Book
{
private:
    string title, ISBN, publisher, authors;
    int year = 0;
    int noOfCopies = 0; 
    int noOfAuthors = 0; 
    double cost = 0.0; 

public:
    void getBookData(ifstream& inFile, Book books[], int& noOfBooks); //Function Reads the input data file 
    void printBookData(Book books[], int noOfBooks); //Function Displays the list of book information 
    void searchBookData(Book books[], int bookCount); //Function Searches for book based on book title or ISBN 

    //Function searches list of books based on book ISBN and returns the location (index) of the found book. 
    void searchBookDataByISBN(Book books[], int bookCount, string ISBN, int& ISBNloc);

    //Function searches list of books based on book title and returns the location (index) of the found book. 
    void searchBookDataByTitle(Book books[], int bookCount, string title, int& titleLoc);

};

void showMenu()
//main menu displaying all options for book repository 
{
    cout << "Please select from the following options listed below by inputting the corresponding number: " << endl;
    cout << "1. List all available books." << endl;
    cout << "2. Search for book using A.Title or B.ISBN" << endl;
    cout << "3. Exit Program" << endl;
    cout << "Input the number corresponding to your given choice: ";
}

/*    C++Programing: From Problem Analysis to Program Design Line 1: title
       5 - 17 - 525281 - 3 Line 2: ISBN
       ABC Line 3: Publisher
       2000 Line 4: Publishing year
       52.50 Line 5: Cost
       20 Line 6: Number of copies of the book
       1 Line 7: number of authors
       Malik, D.S.  Line 8: author(s) */

void Book::getBookData(ifstream& inFile, Book books[], int& noOfBooks)
{
    int i = 0, lineNumber = 0, k = 0;

    if (inFile.is_open()) {

        string line;

        while (getline(inFile, line))
        {

            if (lineNumber == 0) {

                books[i].title = line;
            }

            else if (lineNumber == 1)

                books[i].ISBN = line;

            else if (lineNumber == 2)

                books[i].publisher = line;

            else if (lineNumber == 3)

                books[i].year = atoi(line.c_str());

            else if (lineNumber == 4)

                books[i].cost = atof(line.c_str());

            else if (lineNumber == 5)

                books[i].noOfCopies = atoi(line.c_str());

            else if (lineNumber == 6)

                books[i].noOfAuthors = atoi(line.c_str());

            else
            {
                for (int k = 0; k < (books[i].noOfAuthors); k++)

                    books[k].authors = line;
            }

        }
        lineNumber++;
    }
}
void Book::printBookData(Book books[], int noOfBooks) 
{

    for (int i = 0; i < noOfBooks; i++) {

        cout << "Book Title :" << books[i].title << endl;

        cout << "Book ISBN :" << books[i].ISBN << endl;

        cout << "Book Publisher :" << books[i].publisher << endl;

        cout << "Book Publish Year :" << books[i].year << endl;

        cout << "Book Cost :" << books[i].cost << endl;

        cout << "Books Available: :" << books[i].noOfCopies << endl;

        cout << "Book Authors :" << books[i].authors[0] << endl;

        for (int j = 1; j < books[i].noOfAuthors; j++)

            cout << " " << books[i].authors[j] << endl;

        cout << "\n\n" << endl;

    }

}

void Book::searchBookDataByTitle(Book books[], int bookCount, string title, int& titleLoc)
{
    bool found = false;
    titleLoc = 0;
    string bookTitle = "";

    cout << " Enter the title to be searched: ";
    cin >> bookTitle;

    while (titleLoc < bookCount && !found)
        if (bookTitle == title) {
            cout << title << " is found at index " << titleLoc << endl;
            found = true;
        }
        else if (bookTitle != title)
        {
            cout << title << " is not contained within this list." << endl;
        }
        else
            titleLoc++;        
}

void Book::searchBookDataByISBN(Book books[], int bookCount, string ISBN, int& loc)
//Function searches list of books based on book ISBN and returns the location (index) of the found book 
{
    bool found = false;
    string bookISBN = "";

    cout << " Enter the ISBN to be searched: ";
    cin >> bookISBN;

    for (int loc = 0; loc < bookCount; loc++)
        if (ISBN == bookISBN)
            cout << ISBN << " is found at index " << loc << endl;
        else
            cout << ISBN << " is not contained within this list." << endl;
}

void Book::searchBookData(Book books[], int noOfBooks)
//Function searches for book based on book title or ISBN 
{
    char letterChoice;//variable to store the letter choice selection made by user (A for sort by title B for sort by ISBN)
    cout << "Input the letter A to sort by Title or the letter B to search by ISBN" << endl;
    cin >> letterChoice;
    letterChoice = toupper(letterChoice); //convert character input to uppercase 
    int bookCount = 0;
    int loc = 0;

    if (letterChoice == 'A') //search by title
    {
        searchBookDataByISBN(books, bookCount, ISBN, loc);
    }
    else if (letterChoice == 'B') //search by ISBN
    {
        searchBookDataByTitle(books, bookCount, title, loc);
    }
}

