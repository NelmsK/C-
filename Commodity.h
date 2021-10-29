///////////////////////////////////////////////////////////////////////
//                                                                     
// Filename: Commodity.h
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
// Function: double calcUnitValue(double unitValue);                                       
//                                                                   
// Description:
//    Function to determine the given commodity's unit value
//
// Parameters:  
//    unitValue : The calculated value of a given commodity per 100 units.                  
//                                                       
// Returns:  
//    unitValue : The calculated value of a given commodity per 100 units.                 
//                                            
///////////////////////////////////////////////////////////////////////

#pragma once
#include "Investment.h" 

class Commodity : public Investment
{ 
private:
	enum COMMODITY_TYPE {}; //enumeration containing the different types of commodities in which an individual can invest
	const char name = NULL; //name of account holder
	int accountID = 0; //unique account ID 
	int numberOfUnits = 100; //assume num of units = 100 
	double annualInterestRate = .01; //annual interest rate of 1%	
	int totalInvestmentValue = 5000.00; //default investment value = $5000.00 
public: 
	void liquidate(int amountWithdrawn) const; //pure virtual function used to calculate the totalInvestmentValue after liquidating a given amount of assets
	void createMonthlyStatement() const; //pure virtual function to generate monthly statements that manipulate various types of different investments
	void print() const; //pure virtual function displays  a summary of ALL the attributes of the object
	Commodity(const char name, enum COMMODITY_TYPE, int balance);//constructor
	void getCommodityType(); 
	//Function to return/output a string type of the corresponding enum variant contained w/n COMMODITY_TYPE;

	~Commodity();//destructor 
};

void Commodity::getCommodityType()
{
	COMMODITY_TYPE commodityType; //declares variable commodityType of type COMMODITY_TYPE
	string type;

	switch (commodityType)
	{
	case GOLD:
		type = "GOLD";
		break;
	case SILVER:
		type = "SILVER";
		break;
	case SOLAR:
		type = "SOLAR";
		break;
	case LIVESTOCK:
		type = "LIVESTOCK";
		break;
	}
}

Commodity::Commodity(const char name, enum COMMODITY_TYPE, int balance) :Investment(name, balance)
{
	//syntax for enumeration type: enum typeName {value1, value2, ...}; 
	//To define an enumeration type, you need: a name for the data type; a set of values for the data type; a set of operations on the values 

	enum COMMODITY_TYPE { GOLD, SILVER, SOLAR, LIVESTOCK }; //enumeration containing the different types of commodities in which an individual can invest
}

void Commodity::liquidate(int amountWithdrawn) const
{
	int totalInvestmentValue = (totalInvestmentValue - amountWithdrawn);
}

void Commodity::createMonthlyStatement() const
{
	double unitValue = (totalInvestmentValue) / (numberOfUnits);
}

void Commodity::print() const
{
	string type;
	createMonthlyStatement();
	double unitValue; 

	cout << "Name of Account Holder: " << name << endl; 
	cout << "Account ID: " << accountID << endl; 
	cout << "Commodity Type: " << type << endl;
	cout << "Number of Units: " << numberOfUnits << endl;
	cout << "Annual Interest Rate: " << (annualInterestRate * 100) << "%" << endl;
	cout << "Total Investment Value: $" << totalInvestmentValue << endl; 
	cout << "Unit Value: $" << unitValue << endl; 
	
}