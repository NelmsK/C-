///////////////////////////////////////////////////////////////////////
//                                                                     
// Filename: Investment.h
// Date: September 25, 2021
// Programmer: Kristen Nelms                 
//
// Description:
//		There are many types of financial investments available, such as real estate, 
        //bank savings, stockand commodity for creating wealth.Each of these types
        //have various attributes which may restrict liquidation.For example, you may
        //have a savings account that requires a minimum balance or a real estate
        //investment which may require you to sell a property if sufficient cash reserve is
        //not available.

        //In this lab, you should use abstract classand pure virtual functions to design
        //classes to manipulate various types of investments.For simplicity, assume that
        //there are only four derived investment types : savings, real estate, stockand
        //commodity
//
//    
/////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////
//
// Class: Investment                                         
//                                                                   
// Description:
//    The base abstract class       
//
//    List of data members:
//							int accountNumber = 0; //unique account number for each investment 
//							double totalInvestmentValue = 5000.00; //default investment value = $5000.00
//							double annualInterestRate = 0.0;
//							string name = ""; //name of the account holder 
//							double balance = 0.0; //current balance of the account 
//
//    List of member functions:
//								virtual void liquidate(double amountWithdrawn); 
//								virtual void createMonthlyStatement();
//								virtual void print();
// 
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
//
// Function: virtual void liquidate(double amountWithdrawn);                                         
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

///////////////////////////////////////////////////////////////////////
//
// Function: virtual void createMonthlyStatement();                                          
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
// 
///////////////////////////////////////////////////////////////////////
//
// Function: virtual void print();                                        
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
#include <string>

class Investment //Abstract, Base class 
{
private: 
    int accountNo = 0; //unique account number 
    const char accountName = NULL; //account holder's name
    int totalInvestmentValue = 5000.00; //default investment value = $5000.00 
    double annualInterestRate = 0.0; //annual appreciation rate for the given investment types
public: 
    virtual void liquidate(int amountWithdrawn) = 0; //pure virtual function used to calculate the totalInvestmentValue after liquidating a given amount of assets
    virtual void createMonthlyStatement() = 0; //pure virtual function to generate monthly statements that manipulate various types of different investments
    virtual void print() = 0; //pure virtual function displays  a summary of ALL the attributes of the object

    virtual ~Investment(); 
    //virtual base class destructor 
    //Deletes all the elements contained within the vector 
    //Postcondition: Deletes all objects previously stored within vector investmentList;

    Investment(const char name, int balance); //constructor

    char setName(const char name); 
    //Function to set the account holder name
    //Postcondition: accountName = name; 

    char getName(); 
    //Function to return the account holder's name; 
    //Postcondition: The value of accountName is returned. 

    int getAccountID(); 
    //function to randomly generate unique account holder ID
    //Postcondition: The value of accountNo is returned. 

    int setInvestmentValue(int balance);
    //Function to set the investment value amount
    //Postcondition: totalInvestmentValue = balance; 

    int getInvestmentValue(); 
    //Function to return the total investment value; 
    //Postcondition: The value of totalInvestmentValue is returned. 

    double setAnnualInterestRate(double interestRate);
    //Function to set the annual interest rate
    //Postcondition: annualInterestRate = interestRate; 

    double getAnnualInterestRate(); 
    //Function to return the total annual interest rate; 
    //Postcondition: The value of annualInterestRate is returned. 
};

Investment::Investment(const char name, int balance) //constructor 
{
    const char accountName = name;
    totalInvestmentValue = balance;
}

char Investment::setName(const char name)
{
   const char accountName = name; 
}

char Investment::getName()
{
    return accountName;
}

int Investment::setInvestmentValue(int balance)
{
    totalInvestmentValue = balance; 
}

int Investment::getInvestmentValue()
{
    return totalInvestmentValue; 
}

double Investment::setAnnualInterestRate(double interestRate)
{
    annualInterestRate = interestRate; 
}

double Investment::getAnnualInterestRate()
{
    return annualInterestRate; 
}

int Investment::getAccountID()
{
    using namespace std::chrono;

    // the time point at which the random number was generated
    static auto timestamp = steady_clock::now();

    // the random engine and distribution
    static std::mt19937 twister(timestamp.time_since_epoch().count());
    static std::uniform_int_distribution<int> distribution(0, 999);

    int accountNo = distribution(twister); // initial value

    auto time_now = steady_clock::now(); // current time

    // if 24 hors have passed since the last random number was generated
    if (duration_cast<hours>(time_now - timestamp) > hours(24))
    {
        timestamp = time_now; // update the timestamp
        accountNo = distribution(twister); // and generate a new random number
    }

    return accountNo;
}

