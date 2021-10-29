///////////////////////////////////////////////////////////////////////
//                                                                     
// Filename: SavingsAccount.h
// Date: September 25, 2021
// Programmer: Kristen Nelms                
//
// Description:
//		Description of what the code in the file is meant to do and 
//		how it does what it is meant to do.
/////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
//
// Class: className                                          
//                                                                   
// Description:
//    Description of the class and its purpose         
//
//    List of data members
//
//    List of member functions                                       
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

//SavingsAccount: Assume Service Charge = 2 % if customer's balance falls below minimum balance of $1000 and annual interest rate = 1 %

class SavingsAccount : public Investment
{
public: 
	SavingsAccount(const char name, int balance); //constructor 
	~SavingsAccount(); //destructor 
	void createMonthlyStatement() const;
	void liquidate(double amountWithdrawn) const;
	void print() const;

	int setServiceCharge(int charge);
	//Function to set the vlaue of the service charge should the total investment value drop BELOW $1000.00; 
	//Postcondition: serviceCharge = charge; 

	double getServiceCharge();
	//Function to return the value for the service charge; 
	//Postcondition: The value of serviceCharge is returned; 

	int setMinimumBalance(int minBalance);
	//Function to set the minimum balance used to determine if 
	//Postcondition: minimumBalance = minBalance; 

	int getMinimumBalance();
	//Function to return the minimum balance allowed for the account holder's total investment value; 
	//Postcondition: The value of minimumBalance is returned. 

private: 
	const char name = NULL; //account holder's name; 
	int accountID = 0; //unique account ID 
	double serviceCharge = .02; //serivice charge of 2% if customer balance falls below minimum balance;  
	double annualInterestRate = .01; //annual interest rate of 1%; 
	double minimumBalance = 1000.00; //minimum balance = $1000
	double totalInvestmentValue = 5000.00; //total investment value or balance; 
};

SavingsAccount::SavingsAccount(const char name, int balance)
    : Investment(name, balance)
{
 
}

int SavingsAccount::setServiceCharge(int charge)
//Function to set the vlaue of the service charge should the total investment value drop BELOW $1000.00; 
//Postcondition: serviceCharge = charge; 
{
	serviceCharge = charge;
}

double SavingsAccount::getServiceCharge()
//Function to return the total investment value with the added service charge; 
//Postcondition: If (totalInvestmentValue < minimumBalance) {totalInvestmentValue = ((serviceCharge*totalInvestmentValue) + totalInvestmentValue)}; 
{
	return serviceCharge; 
}

int SavingsAccount::setMinimumBalance(int minBalance)
//Function to set the minimum balance used to determine if 
//Postcondition: minimumBalance = minBalance; 
{
	minimumBalance = minBalance;
}
int SavingsAccount::getMinimumBalance()
//Function to return the minimum balance allowed for the account holder's total investment value; 
//Postcondition: The value of minimumBalance is returned. 
{
	return minimumBalance; 
}

void SavingsAccount::liquidate(double amountWithdrawn) const
{
	double totalInvestmentValue = (totalInvestmentValue - amountWithdrawn);
}

void SavingsAccount::createMonthlyStatement() const
//Function to return the total investment value with the added service charge IF the total investement balance is BELOW the minimum balance ($1000.00); 
{
	double totalInvestmentValue; 

	if (totalInvestmentValue < minimumBalance)
	{
		totalInvestmentValue = (((serviceCharge * totalInvestmentValue) + totalInvestmentValue)* (annualInterestRate /12));
	}
	else
		totalInvestmentValue = (totalInvestmentValue* (annualInterestRate /12));
}

void SavingsAccount::print() const
{
	createMonthlyStatement();

	cout << "Name of Account Holder: " << name << endl;
	cout << "Account ID: " << accountID << endl;
	cout << "Annual Interest Rate: " << (annualInterestRate * 100) << "%" << endl;
	cout << "Total Investment Value: $" << totalInvestmentValue << endl;
}