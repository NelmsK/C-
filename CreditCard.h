////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                     
// Filename: CreditCard.h
// Date: September 18, 2021 
// Programmer: Kristen Nelms           
//
// Description:
//   Create the base class CreditCard from which all other derived classes can be created. 
//	This base class establishes the account holder name, credit limit, credit balance, interest rate, and various counter variables. 
//  This base class is used in order to calculate the charges, payments, monthly interest, and display credit 
//	info for each of the individual CreditCard objects created.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once 
#include <string>
using namespace std; 

///////////////////////////////////////////////////////////////////////
//
// Class: CreditCard                                          
//                                                                   
// Description:
//    Base class; acts as a template with which to store all member variables, functions, etc--anything necessary to calculate 
//	  payment, charge, monthlyInterest, and display information
//
//
//    List of data members: string name = " ";  //name of account holder
//							double creditLimit = 0.0; //limit of credit amount 
//							double creditBalance = 0.0; //balance charged on the account
//							double interestRate = 0.0; // annual interest rate on creditbalance.
//							static int accountID; //unique 3 digit account id assigned to each creditcard object use a static data member to generate this unique account id for each creditcard object created.
//
//    List of member functions: int accountIDGenerator(); //function to generate a random 3-digit number
//								void setName(string accountName); //function to set account holder name;
//								CreditCard(string accountName); //constructor with string parameter. 
//								void setInfo(double limit, double interest); //function to set creditLimit and interestRate 
//								void charge(double amount); //function which applies charge on creditcard.
//								void payment(double amount); //function which pays an amount towards the creditbalance.
//								void calculateMonthlyInterest(); //function which calculates the monthly interestand adds interest to the creditbalance.
//								void displayCreditInfo(); //function which displays the account holder name, accountid, chargebalance, creditlimit, interestrateand count of the number of creditcard objects created                                    
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int CreditCard::accountID = 0; //initalize unique 3 digit account ID assigned to each CreditCard object

template <typename T> //Curiously recurring template pattern in order to calc number of CreditCard objects created 
struct counter
{
    counter()
    {
        count++;
	
    }

    counter(const counter&)
    {
        count++;
		
    }

protected:
	virtual ~counter()
	{
		--count; 
	}
    static int count; //a static data member to track the count of the total number of CreditCard objects created.
};
template <typename T> int counter<T>::count(0); //initialize static data member to track the count of the number of CreditCard objects created.


class CreditCard: counter<CreditCard>
{ //base class

private: 
	string name = " ";  //name of account holder
	double creditLimit = 0.0; //limit of credit amount 
	double creditBalance = 0.0; //balance charged on the account
	double interestRate= 0.0; // annual interest rate on creditbalance.
	static int accountID; //unique 3 digit account id assigned to each creditcard object use a static data member to generate this unique account id for each creditcard object created.
	

public: 
	int accountIDGenerator(); //function to generate a random 3-digit number
	void setName(string accountName); //function to set account holder name;
	CreditCard(string accountName); //constructor with string parameter. 
	void setInfo(double limit, double interest); //function to set creditLimit and interestRate 
	void charge(double amount); //function which applies charge on creditcard.
	void payment(double amount); //function which pays an amount towards the creditbalance.
	void calculateMonthlyInterest(); //function which calculates the monthly interestand adds interest to the creditbalance.
	void displayCreditInfo(); //function which displays the account holder name, accountid, chargebalance, creditlimit, interestrateand count of the number of creditcard objects created
};


int CreditCard::accountIDGenerator() //random 3 digit generator for unique accountIDs 
{
    using namespace std::chrono;

    // the time point at which the random number was generated
    static auto timestamp = steady_clock::now();

    // the random engine and distribution
    static std::mt19937 twister(timestamp.time_since_epoch().count());
    static std::uniform_int_distribution<int> distribution(0, 999);

    int accountID = distribution(twister); // initial value

    auto time_now = steady_clock::now(); // current time

    // if 24 hors have passed since the last random number was generated
    if (duration_cast<hours>(time_now - timestamp) > hours(24))
    {
        timestamp = time_now; // update the timestamp
        accountID = distribution(twister); // and generate a new random number
    }

    return accountID;
}
void CreditCard::setName(string accountName)
//mutator function to set account holder name
{
    name = accountName;
} //end setname


CreditCard::CreditCard(string accountName)
//constructor; postcondition: name = accountname; if no value sepcified for accountname, then name = " ";
{
    name = accountName;
} //end constructor for name


void CreditCard::setInfo(double limit, double interest)
{
    creditLimit = limit;
    interestRate = interest;
}


void CreditCard::charge(double amount)
//function which applies charge on CreditCard.
{
    creditBalance = creditBalance + amount;
} //end charge

void CreditCard::payment(double amount)
//function which pays an amount towards the creditBalance.
{
    creditBalance = creditBalance - amount;
} //end payment 

void CreditCard::calculateMonthlyInterest()
//function which calculates the monthly interest and adds that interest to the creditBalance.
{
    creditBalance = (((interestRate / 12)) * creditBalance) + creditBalance;
} //end calculateMonthlyInterest


void CreditCard::displayCreditInfo()
//function which displays the account holder name, accountID, chargeBalance, creditLimit, interestRate
// and count of the number of CreditCard objects created.
{
    cout << "Account Holder Name: " << name << endl;
    cout << "Account Holder ID: " << accountIDGenerator() << endl;
    cout << "Current balance on the card:  $" << creditBalance << endl;
    cout << "Total Credit Limit: $" << creditLimit << endl;
    cout << "Interest Rate: " << interestRate << "%" << endl;
    cout << "Total number of CreditCard objects created: " << counter<CreditCard>::count << endl;
    cout << endl;

} //end displayCreditInfo 
