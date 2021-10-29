/////////////////////////////////////////////////////////////////////
 //                                                                    
 //filename: lab04.cpp
 //date: september 25, 2021
 //programmer: kristen nelms                 

 //description:
 //     this program creates classes for various types of financial investments--realestate, stock, commodity, and savings account. 
 //     each investment type has its own barrier restricting liquidation and means of accruing value. 
 //     this program uses those factors to then calculate value, liquidation, create monthly statements, and generate an output of all of that information.
///////////////////////////////////////////////////////////////////////

#include <iostream> 
#include <iomanip> 
#include <vector> 
#include <random>
#include <chrono>

#include "Investment.h" 
#include "RealEstate.h" 
#include "Stock.h" 
#include "SavingsAccount.h" 
#include "Commodity.h"

using namespace std; 

enum COMMODITY_TYPE { GOLD, SILVER, SOLAR, LIVESTOCK };

int main()
{
 
    vector<Investment*> investmentList; //vector investmentList stores the address of objects of type Investment.
    
    //operator "new" allocates memory of type [class commodity] and stores the address of the allocated memory in commodity accessed indirectly by the pointer returned by new
    investmentList.push_back(new Commodity("Bill", GOLD, 1500)); //dynamically allocated a new Commodity invoking its constructor, passing it the name "Bill", the COMMODITY_TYPE GOLD, and $1500 balance

    investmentList.push_back(new RealEstate("Susan", 35000));

    investmentList.push_back(new Stock("John", 20100));

    investmentList.push_back(new SavingsAccount("Ravi", 3100));

    investmentList.push_back(new SavingsAccount("Sandy", 1000));

    investmentList.push_back(new RealEstate("Jamal", 20200));

    investmentList.push_back(new Commodity("Hamid", SOLAR, 51001));

    for (auto* i : investmentList)
    {

        cout << "January:\n-------------" << endl;
        for (int i = 0; i < investmentList.size(); i++)
        {
            investmentList[i]->createMonthlyStatement();
            investmentList[i]->print();
            cout << endl;
        }

        cout << "\nFebruary:\n-------------" << endl;
        for (int i = 0; i < investmentList.size(); i++)
        {
            investmentList[i]->createMonthlyStatement();
            investmentList[i]->print();
            cout << endl;
        }

        for (int i = 0; i < investmentList.size(); i++)
        {
            investmentList[i]->liquidate(1000);
        }

        cout << "\nMarch:\n-------------" << endl;
        for (int i = 0; i < investmentList.size(); i++)
        {
            investmentList[i]->createMonthlyStatement();
            investmentList[i]->print();
            cout << endl;
        }
    }

    for (auto* i : investmentList)
    {
        delete i; 
    }
    return 0;
}
