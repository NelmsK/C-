////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                     
// Filename: PremiumCard.h
// Date: September 18, 2021 
// Programmer: Kristen Nelms           
//
// Description:
//   Create the derived class, PremiumCard, from base class: CreditCard. 
//	This derived class has its own pre-established constant values for interest rate, charge limit, and fee
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
/* PremiumCard.cpp */
// Incorrect way
CreditCard::PremiumCard() { /* code */ }
CreditCard::PremiumCard(string n) { /* code */ }
// Correct way
PremiumCard::PremiumCard() : CreditCard() { /* code*/ }
PremiumCard::PremiumCard(string n) : CreditCard(n) { /* code*/ }
/*
 * You define the constructor in the same way as you did in creditcard.cpp
 * the difference comes when you call the parent class constructor.
 * the format being ChildClass::ChildClass() : ParentClass()
 * /
 */

#pragma once
#include "CreditCard.h"

//derived class 
class PremiumCard: public CreditCard
{
public: 
	PremiumCard(string accountName);  //constructor for PREMIUM account holder name
	void charge(double amount);
	void setInfo(double, double);

	
private:
	const double DEFAULT_INTEREST_RATE_PREMIUM = 0.12; //annual interest rate for the PREMIUM card
	const double DEFAULT_FEE_PREMIUM = 150.0; //PremiumCard Fee 
	const double PREMIUM_CHARGE_LIMIT = 2000.00; //credit limit for the PREMIUM card
	
};


PremiumCard::PremiumCard(string accountName) //constructor for PREMIUM card's account name is executed which...
    :CreditCard(accountName) //triggers the execution of the CreditCard constructor 
{
    accountName = accountName;
    setInfo(PREMIUM_CHARGE_LIMIT, DEFAULT_INTEREST_RATE_PREMIUM);
}
void PremiumCard::setInfo(const double PREMIUM_CHARGE_LIMIT, const double DEFAULT_INTEREST_RATE_PREMIUM)
{
    CreditCard::setInfo(PREMIUM_CHARGE_LIMIT, DEFAULT_INTEREST_RATE_PREMIUM);
}

void PremiumCard::charge(double amount)
{
    if (amount > PREMIUM_CHARGE_LIMIT)
    {
        amount = amount + DEFAULT_FEE_PREMIUM;
        CreditCard::charge(amount);
    }
    else
    {
        CreditCard::charge(amount);
    }
}