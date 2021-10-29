///////////////////////////////////////////////////////////////////////
//                                                                     
// Filename: RealEstate.h
// Date: September 25, 2021
// Programmer: Kristen Nelms                 
//
// Description:
//		Description of what the code in the file is meant to do and 
//		how it does what it is meant to do.
//    
//
/////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
//
// Class: RealEstate                                          
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

//RealEstate: Suppose that this investment type has N = number of properties
//and cash reserve percentage.Each property value is determined as follows :
//[20 pts]

//Property value = (total investment value – cash reserve) / (N = number of properties}

//RealEstate:  Assume number of properties = 10 (of equal value),
//annual appreciation rate = 15 % and percent of reserves = 10 % of investment balance.

class RealEstate: public Investment
{
public:
	RealEstate(const char name, int balance); //constructor 
	~RealEstate(); //destructor
    void liquidate(double amountWithdrawn) const 
    {
       double totalInvestmentValue = ((totalInvestmentValue - amountWithdrawn));
    }
	void createMonthlyStatement() const;
    void liquidate(double amountWithdrawn) const;
	void print() const; //displays a summary of ALL the attributes of the object

    double setcashReserve(double reserve);
    //Function to set the % cash reserve amount
    //Postcondition: cashReserve = reserve; 

    double getcashReserve();
    //Function to return the cash reserve value--which is 10% of the total investment value; 
    //Postcondition: The value of totalInvestmentValue is returned. 

    int setNumberOfProperties(int n);
    //Function to set the number of properties held by the account holder; 
    //Postcondition: numberOfProperties = n; 

    int getNumberOfProperties();
    //Function to return the total number of properties held by the account holder; 
    //Postcondition: The value of numberOfProperties is returned.

    double setAnnualInterestRate(double interestRate);
    //Function to set the annual interest rate
    //Postcondition: annualInterestRate = interestRate; 

    double getAnnualInterestRate();
    //Function to return the total annual interest rate; 
    //Postcondition: The value of annualInterestRate is returned. 	
private: 
    const char name = NULL; //account holder's name 
    int accountID = 0; //unique account ID 
	double cashReserve; //10% of investment balance 
	int numberOfProperties = 10; //Assume number of properties = 10 (of equal value);
	double annualInterestRate = .15; //annual appreciation rate of 15%
    int totalInvestmentValue = 5000.00; //default investment value = $5000.00 
};

RealEstate::RealEstate(const char name, int balance) : Investment(name, balance)
{

}
double RealEstate::setcashReserve(double reserve)
//Function to set the % cash reserve amount
//Postcondition: cashReserve = reserve; 
{
    cashReserve = reserve;
}

double RealEstate::getcashReserve()
//Function to return the cash reserve value--which is 10% of the total investment value; 
//Postcondition: The value of totalInvestmentValue is returned. 
{
    int totalInvestmentValue;
    getInvestmentValue(); 

    cashReserve = (0.10 * totalInvestmentValue); 

    return cashReserve; 
}

int RealEstate::setNumberOfProperties(int n)
//Function to set the number of properties held by the account holder; 
//Postcondition: numberOfProperties = n; 
{
    numberOfProperties = n;
}

int RealEstate::getNumberOfProperties()
//Function to return the total number of properties held by the account holder; 
//Postcondition: The value of numberOfProperties is returned. 
{
    return numberOfProperties; 
}

double RealEstate::setAnnualInterestRate(double interestRate)
{
    annualInterestRate = interestRate;
}

double RealEstate::getAnnualInterestRate()
{
    return (annualInterestRate/12);
}

void RealEstate::liquidate(double amountWithdrawn) const 
{
    double totalInvestmentValue = ((totalInvestmentValue - amountWithdrawn));
}

void RealEstate::createMonthlyStatement() const
{
    double propertyValue; 
    int totalInvestmentValue;
  
    propertyValue = (totalInvestmentValue - cashReserve) / (numberOfProperties);
}

void RealEstate::print() const
{
    createMonthlyStatement();
    double propertyValue; 

    cout << "Name of Account Holder: " << name << endl;
    cout << "Account ID: " << accountID << endl;
    cout << "Cash Reserve: " << cashReserve << endl;
    cout << "Number of Properties: " << numberOfProperties << endl;
    cout << "Annual Interest Rate: " << (annualInterestRate * 100) << "%" << endl;
    cout << "Total Investment Value: $" << totalInvestmentValue << endl;
    cout << "Property Value: $" << propertyValue << endl;
}