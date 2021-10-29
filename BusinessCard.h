////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                     
// Filename: BusinessCard.h
// Date: September 18, 2021 
// Programmer: Kristen Nelms           
//
// Description:
//   Create the derived class, BusinessCard, from base class: CreditCard. 
//	This derived class has its own pre-established constant values for interest rate, charge limit, and fee
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once
#include "CreditCard.h"

//derived class 
class BusinessCard: public CreditCard
{
public: 
	BusinessCard(string accountName); //constructor for BUSINESS account holder name 
	void setInfo(double, double);
	void charge(double amount); 
	
		

private: 
	const double DEFAULT_INTEREST_RATE_BUSINESS = 0.10; //annual interest rate for the BUSINESS card
	const double BUSINESS_CHARGE_LIMIT = 5000.00; //credit limit for the BUSINESS card
	const double DEFAULT_FEE_BUSINESS = 50.0;   //BusinessCard Fee 
};

BusinessCard::BusinessCard(string accountName) //constructor for BUSINESS card's account name is executed which...
    :CreditCard(accountName) //triggers the execution of the CreditCard constructor 
{
    accountName = accountName;
    setInfo(BUSINESS_CHARGE_LIMIT, DEFAULT_INTEREST_RATE_BUSINESS);
} //end BusinessCard string constructor

void BusinessCard::setInfo(const double BUSINESS_CHARGE_LIMIT, const double DEFAULT_INTEREST_RATE_BUSINESS)
{
    CreditCard::setInfo(BUSINESS_CHARGE_LIMIT, DEFAULT_INTEREST_RATE_BUSINESS);
}

void BusinessCard::charge(double amount)
{
    if (amount > BUSINESS_CHARGE_LIMIT)
    {
        amount = amount + DEFAULT_FEE_BUSINESS;
        CreditCard::charge(amount);
    }
    else
    {
        CreditCard::charge(amount);
    }
}
