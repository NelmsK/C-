#pragma once

class cashRegister
{
public:
	int getCurrentBalance() const;
	//function to show the current amonut in the cash register 
	// postcondition: the value of cashOnHand is returned 

	void acceptAmount(int amountIn);
	//function to receive the amount deposited by the customer and update the amount in teh register 
	// Post condition: cashOnHand = cashOnHand + amountIn; 


	cashRegister(int cashIn = 500);
	//constructor 
	//sets the cash in the register to a specific amount 
	// postcondition: cashOnHan = cashIn; 
	//					if no value is specified when the object is declared, the default value is assigned to cashOnHand is 500. 

private:
	int cashOnHand; //variable to store the cash in the regiser
};

class dispenserType
{
public:
	int getNoOfItems() const;
	//function to show the number of items in the machine 
	//postcondition: the value of numberOfItems is returned

	int getCost() const;
	//function to show the cost of the item 
	//Postcondition: The value of cost is returned 

	void makeSale();
	//Function to reduce the number of items by 1
	// Postcondition: numberOfItems--; 

	dispenserType(int setNoOfItems = 50, int setCost = 50);
	//Constructor
	//Sets the cost and number of items in the dispenser to the values specified by the user 
	//Postcondition: numberOfItems = setNoOfItems; 
	//				 cost = setCost; 
	//				 IF no value is specified for a parameter, then its default value is assigned to the correspondign number variable 

private:
	int numberOfItems; //variable to store the number of items in the dispenser 
	int cost; //variable to store the cost of an item 
};