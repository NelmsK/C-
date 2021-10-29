///////////////////////////////////////////////////////////////////////
//                                                                     
// Filename: Stock.h
// Date: September 25, 2021
// Programmer: Kristen Nelms                 
//
// Description:
//		Description of what the code in the file is meant to do and 
//		how it does what it is meant to do.
/////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
//
// Class: Stock                                          
//                                                                   
// Description:
//		One of the mamy different types of financial investments given. 
//		This class is designed to manipulate various types of investments.
//		Stocks have a certain number of shares and the value of each share is determined via the total investment value 
//		and the number of shares owned.       
//
//    List of data members:
// 							double totalInvestmentValue; //total amount invested
//							int numberOfShares = 100; //assume number of shares is 100 
//							double annualInterestRate = 0.10; //annual interest rate is 10%
//
//    List of member functions:
//								double calculateValueOfShare(double shareValue);                               
// 
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
//
// Function: functionName                                          
//                                                                   
// Description:
//    Description of the function
//
// Parameters:  
//    firstParam  : first parameter's description          
//    secondParam : second parameter's description               
//                                                       
// Returns:  
//    returnVal : description of what is returned to caller                 
//                                            
///////////////////////////////////////////////////////////////////////

#pragma once
#include "Investment.h" 

//Stock: Suppose that this investment type has a certain number of shares and the value of each share is determined as follows :
//
//	Share value = (total investment value) / (number of shares)
//
//Assume number of shares is 100 and annual appreciation rate = 10 %

class Stock : public Investment
{
public: 
	Stock(const char name, int balance); //constructor 
	~Stock(); //destructor 
	int setNumberOfShares(int totalShares);
	//Function to set the total number of shares of a stock the account holder has; 
	//Postcondition: numberOfShares = totalShares; 

	int getNumberOfShares();
	//Function to return the value for the total number of shares of stock; 
	//Postcondition: The value of numberOfShares is returned; 

	void createMonthlyStatement() const;
	void liquidate(double amount) const; 
	void print() const;

private: 
	const char name = NULL; //account holder's name
	int accountID = 0; //unique account ID 
	double totalInvestmentValue; //total amount invested
	int numberOfShares = 100; //assume number of shares is 100 
	double annualInterestRate = 0.10; //annual interest rate is 10%
};

Stock::Stock(const char name, int balance)
    :Investment(name, balance)
{
    
}

int Stock::setNumberOfShares(int totalShares)
//Function to set the total number of shares of a stock the account holder has; 
//Postcondition: numberOfShares = totalShares; 
{
	numberOfShares = totalShares;
}

int Stock::getNumberOfShares()
//Function to return the value for the total number of shares of stock; 
//Postcondition: The value of numberOfShares is returned; 
{
	return numberOfShares;
}


void Stock::liquidate(double amountWithdrawn) const
{
	double totalInvestmentValue = (totalInvestmentValue - amountWithdrawn); 
}

void Stock::createMonthlyStatement() const
{
	double shareValue; 

	shareValue = ((totalInvestmentValue) / (numberOfShares));
}

void Stock::print() const
{
	createMonthlyStatement();
	double shareValue;
	cout << "Name of Account Holder: " << name << endl;
	cout << "Account ID: " << accountID << endl;
	cout << "Annual Interest Rate: " << (annualInterestRate * 100) << "%" << endl;
	cout << "Total Investment Value: $" << totalInvestmentValue << endl;
	cout << "Total Number of Shares: " << numberOfShares << endl;
	cout << "Total Share Value: $" << shareValue << endl; 
}
