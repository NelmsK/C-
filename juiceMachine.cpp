//Show the products sold by the juice machine 
// Let the customer make a selection 
//show cost of item selected 
// accept money from the customer 
// release the item 
// input: item selected and cost of item
// output: selected item 

#include <iostream>
#include "juiceMachine.h"

using namespace std; 

//Function prototypes:
void showSelection(); 
void sellProduct(dispenserType& product, cashRegister& pCounter); 

int cashRegister::getCurrentBalance() const
{
	return cashOnHand; 
}

void cashRegister::acceptAmount(int amountIn)
{
	cashOnHand = cashOnHand + amountIn; //updates the cash in the register by adding the amount added in by the custoomer to the value already on hand 

}

cashRegister::cashRegister(int cashIn)
//if user does not specify any value when the object is declared the default value is used to initialize the member variable cashOnHand
{
	if (cashIn >= 0) 
		cashOnHand = cashIn;  
	else
		cashOnHand = 500; 
}

//Dispenser: releases the selected item if the despenser is NOT empty 
// needs to display number of items in dispenser as well as their cost 



int dispenserType::getNoOfItems() const
{
	return numberOfItems;
}

int dispenserType::getCost() const
{
	return cost;
}

void dispenserType::makeSale()
//decrements the value of numberOfItems by 1
{
	numberOfItems--; 
}

dispenserType::dispenserType(int setNoOfItems, int setCost)
{
	if (setNoOfItems >= 0)
		numberOfItems = setNoOfItems;
	else
		numberOfItems = 50; 

	if (setCost >= 0)
		cost = setCost;
	else
		cost = 50; 
}

void showSelection()
{
	cout << "+++ Welcome to the juice shop +++" << endl;
	cout << "To slect an item, enter: " << endl; 
	cout << "1. for orange juice" << endl; 
	cout << "2. for apple juice" << endl; 
	cout << "3. for cranberry juice" << endl; 
	cout << "4. for grape juice" << endl; 
	cout << "5. to exit" << endl; 
}

void sellProduct(dispenserType& product, cashRegister& pCounter)
//attempts to sell product selected by customer
{
	int amount; //variable to hold the amount entered 
	int amountNeeded; //variable to hold the extra amount needed 

	if (product.getNoOfItems() > 0) //if the dispenser is NOT empty 
	{
		cout << "Please depost " << product.getCost() << " cents" << endl; //prompt customer to enter the cost of the item
		cin >> amount; //amount deposited by customer 

		if (amount < product.getCost())
		{
			//promopt customer to enter the additional amount
			cout << "Please deposit another "
				<< product.getCost() - amount
				<< " cents" << endl;
			cin >> amountNeeded;
			amount = amount + amountNeeded; //calculate total amount entered by user 
		}

		if (amount >= product.getCost()) //if amount entered is greater than or equal to cost of the product 
		{
			pCounter.acceptAmount(amount); //update amount in cashRegister 
			product.makeSale(); //select product for sale 
			cout << "Collect your item below and enjoy!" << endl;
		}
		else
			//if amount deposited is NOT enough 
			cout << "The amount is not enough."
			<< "Collect what you deposited." << endl;
	}
	else
		//if dispenser is empty 
		cout << "Sorry, this item is sold out." << endl; 
}

int main()
{
	cashRegister counter; //declare an object of type cashRegister 

	//declare and initialize 4 objects of type dispenserType to represent the four juices within the machine 
	dispenserType orange(100, 50); 
	dispenserType apple(100, 65); 
	dispenserType cranberry(75, 45); 
	dispenserType grape(100, 85); 

	int choice; //variable to store the selection made by the user 

	showSelection(); //calling function to show selection to user 
	cin >> choice; // store choice entered by user in variable choice 

	//use switch statement to sell desired product 
	while (choice != 5)
	{
		switch (choice)
		{
		case 1: 
			sellProduct(orange, counter); 
			break;
		case 2: 
			sellProduct(apple, counter);
			break; 
		case 3:
			sellProduct(cranberry, counter);
			break;
		case 4:
			sellProduct(grape, counter);
			break;
		default : //output error message if choice is anything other than the above
			cout << "Invalid selection." << endl; 
		}

		//if user inputs incorrectly, show selection again and get new choice 
		showSelection(); 
		cin >> choice; 
	}

	return 0; 
}