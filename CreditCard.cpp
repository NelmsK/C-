///////////////////////////////////////////////////////////////////////
//                                                                     
// Filename: CreditCard.cpp
// Date: September 18, 2021 
// Programmer: Kristen Nelms           
//
// Description:
//    Create the following classes: CreditCard (base class), PremiumCard, BusinessCard (derived classes) 
//    Using the unique member variables associated with the derived classes, create a template program using the base class in order 
//    to calculate charges applied to each credit card, payments for those credit cards, and the monthly interest for each card as 
//    well. Then display all member variables and your calculated results
////////////////////////////////////////////////////////////////////////


#include <iostream> 
#include <iomanip> 
#include <random>
#include <chrono>
#include "CreditCard.h"
#include "PremiumCard.h" 
#include "BusinessCard.h" 

using namespace std;

int main()
{
    BusinessCard businessCard1("Happy Reading Bookstore LLC");
    BusinessCard businessCard2("Triangle Florist LLC");
    PremiumCard premiumCard1("Charlie Brown");
    PremiumCard premiumCard2("Lucy Van Pelt");

    businessCard1.charge(6000);
    businessCard2.charge(2500);
    premiumCard1.charge(2100);
    premiumCard2.charge(250);

    businessCard1.calculateMonthlyInterest();
    businessCard2.calculateMonthlyInterest();
    premiumCard1.calculateMonthlyInterest();
    premiumCard2.calculateMonthlyInterest();

    cout << "***********************************" << endl;
    businessCard1.displayCreditInfo();
    businessCard2.displayCreditInfo();
    premiumCard1.displayCreditInfo();
    premiumCard2.displayCreditInfo();
    cout << "***********************************" << endl << endl;

    businessCard1.payment(5000);
    businessCard2.payment(2500);
    premiumCard1.payment(2100);
    premiumCard2.payment(290);

    cout << "********After Payment ***************" << endl;
    businessCard1.displayCreditInfo();
    businessCard2.displayCreditInfo();
    premiumCard1.displayCreditInfo();
    premiumCard2.displayCreditInfo();
    cout << "***********************************" << endl << endl;

    system("pause");
    return 0;
}