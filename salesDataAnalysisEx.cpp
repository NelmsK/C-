//Program: Sales Data Analysis 
//This program processes sales data for a company. For each salesperson, it outputs the ID; the total sales by each quarter; and the total sales for the year. 
// It also calculates/determines the salesperson who generated the highest company profit for that year and outputs both values. 
// Finally, the program also calculates/determines the quarter in which the highest profit was earned and outputs the requisite quarter along with the profit value. 

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std; 

const int NO_OF_SALES_PERSON = 6; 

struct salesPersonRec
	//struct data-type salesPersonRec to group related items of different types.
{
	string ID; //salesperson's ID
	double saleByQuarter[4]; //array to store the total sales for each quarter 
	double totalSale; //salesperson's yearly sales amount
};

//function prototypes 
void initialize(ifstream& inData, salesPersonRec list[], int listSize);
void getData(ifstream& inFile, salesPersonRec list[], int listSize);
void saleByQuarter(salesPersonRec list[], int listSize, double totalByQuarter[]);
void printReport(ofstream& outFile, salesPersonRec list[], int listSize, double saleByQuarter[]);
void maxSaleByPerson(ofstream& outData, salesPersonRec list[], int listSize);
void maxSaleByQuarter(ofstream& outData, double saleByQuarter[]);


//array of 6 components to store salesperson data 
salesPersonRec salesPersonList[NO_OF_SALES_PERSON]; //value of NO_OF_SALES_PERSON = 6 as there are 6 sales people 

//Algorithm: 
//step 1: iniitialize the array salesPersonList
//Step 2: Process the sales data 
//Step 3: Calculate the total sales by quarter 
//Step 4: Calculate the total sales by salesperson 
//Step 5: Print the report 
// Step 6: Calculate and print the maximum sales by salesperson 
//Step 7: Calculate and print the maximum sales by quarter 

void initialize(ifstream& inData, salesPersonRec list[], int listSize)
//reads the salesperson's ID from the input file 
{
	int index; 
	int quarter; 

	for (index = 0; index < listSize; index++)
	{
		inData >> list[index].ID; //get salesperson's ID from input file and stores salesperson's ID in the array list

		//initialize quarterly sales amount to 0.0
		for (quarter = 0; quarter < 4; quarter++)
			list[index].saleByQuarter[quarter] = 0.0; 

		list[index].totalSale = 0.0; //initialize total sales amount for each sales person to zero 
	}
}

void getData(ifstream& inFile, salesPersonRec list[], int listSize)
//reads sales data from input file and stores appropriate information in the salesPersonRec list array
{
	int index; 
	int quarter; 
	string sID; 
	int month; 
	double amount; 

	inFile >> sID; //read the salesperson's ID 

	while (inFile)
	{
		inFile >> month >> amount; //get the sale month and the sale amount for that month 

		//search the array for the component corresponding to the salesperson
		for (index = 0; index < listSize; index++)
			if (sID == list[index].ID)
				break; 

		//determination of quarter 
		if (1 <= month && month <= 3)
			quarter = 0;
		else if (4 <= month && month <= 6)
			quarter = 1;
		else if (7 <= month && month <= 9)
			quarter = 2;
		else
			quarter = 3; 

		if (index < listSize)
			list[index].saleByQuarter[quarter] += amount; //update the sales for the quarter by adding the sales amount for the month 
		else
			cout << "Invalid salesperson ID." << endl; //error message if salesperson's ID is invalid 

		inFile >> sID; 
	}
}

void saleByQuarter(salesPersonRec list[], int listSize, double totalByQuarter[])
//finds company's total sales for each quarter 
{
	int quarter; 
	int index; 

	//initialize totalByQuarter[quarter] to 0
	for (quarter = 0; quarter < 4; quarter++)
		totalByQuarter[quarter] = 0.0; 

	//to find total sales amount for each salesperson by quarter, add the sales amount for each salesperson for that quarter
	// so we know this function must have access to the salesPersonRec list[] and the array totalSaleByQuarter[]
	for (quarter = 0; quarter < 4; quarter++)
	{
		for (index = 0; index < listSize; index++)
			totalByQuarter[quarter] +=
				list[index].saleByQuarter[quarter]; 
	}
}

void totalSaleByPerson(salesPersonRec list[], int listSize)
//finds each salesperson's yearly sales amount 
{
	int index; 
	int quarter; 

	//add employee's sales amount to the four quarters 
	for (index = 0; index < listSize; index++)
		for (quarter = 0; quarter < 4; quarter++)
			list[index].totalSale +=
			list[index].saleByQuarter[quarter]; 
}

void printReport(ofstream& outFile, salesPersonRec list[], int listSize, double saleByQuarter[])
{
	int index; 
	int quarter; 

	outFile << "------------ Annual Sales Report ------------"
		<< "----" << endl; 
	outFile << endl; 
	outFile << "  ID             QT1             QT2             QT3             "
		<< "QT4             Total" << endl; 

	outFile << "__________________________________________"
		<< "________________" << endl; 

	for (index = 0; index < listSize; index++)
	{
		outFile << list[index].ID << "   "; //output salesperson's ID 

		//output salesperson's sale by quarter 
		for (quarter = 0; quarter < 4; quarter++) 
			outFile << setw(10)
			<< list[index].saleByQuarter[quarter]; 

		outFile << setw(10) << list[index].totalSale << endl; 
	}
	
	outFile << "Total   "; 

	//output salesperson's total sales 
	for (quarter = 0; quarter < 4; quarter++)
		outFile << setw(10) << saleByQuarter[quarter];

	outFile << endl << endl; 
}

void maxSaleByPerson(ofstream& outData, salesPersonRec list[], int listSize)
//function to print the name of the salesperson who produces the maximum sales amount 
{
	int maxIndex = 0; 
	int index; 

	//find the largest sales amount
	for (index = 1; index < listSize; index ++)
		if (list[maxIndex].totalSale < list[index].totalSale)
			maxIndex = index;

	//output the ID of the salesperson who accrued the largest sales amount followed by the actual max sales amount 
	outData << "Max Sale by SalesPerson: ID = "
		<< list[maxIndex].ID
		<< ", Amount = $" << list[maxIndex].totalSale
		<< endl; 
}

void maxSaleByQuarter(ofstream& outData, double saleByQuarter[])
//function to print the quarter in which the maximum sales were made
{
	int quarter; 
	int maxIndex = 0; 

	//look at total sales for EACH quarter and then determine the largest sales amount from that 
	for (quarter = 0; quarter < 4; quarter++)
		if (saleByQuarter[maxIndex] < saleByQuarter[quarter])
			maxIndex = quarter; 

	//output maximum sale by quarter amount 
	outData << "Max Sale by Quarter: Quarter = "
		<< maxIndex + 1
		<< ", Amount = $" << saleByQuarter[maxIndex]
		<< endl; 
}

int main()
{
	ifstream inFile; //input file stream variable 
	ofstream outFile; //output file stream variable 

	string inputFile; //variable to store the input file name 
	string outputFile; //variable to store the output file name

	double totalSaleByQuarter[4]; //array to hold the total sale by quarter 

	salesPersonRec salesPersonlist[NO_OF_SALES_PERSON]; // array to hold the salesperson's data 

	cout << "Enter the salesPerson ID file name: ";
	cin >> inputFile; 
	cout << endl; 

	inFile.open(inputFile.c_str());

	if (!inFile) //if input file cannot be opened, terminate the program 
	{
		cout << "Cannot open the input file."
			<< endl; 
		return 1; 
	}

	initialize(inFile, salesPersonList, NO_OF_SALES_PERSON); //call initialize function to read the salesperson's ID and store it in salesPersonList
	
	inFile.close(); 
	inFile.clear(); 

	//input sales data file name in variable inputFile 
	cout << "Enter the sales data file name: "; 
	cin >> inputFile; 
	cout << endl; 

	inFile.open(inputFile.c_str());
	if (!inFile)
	{
		cout << "Cannot open the input file."
			<< endl;
		return 1;
	}

	//output sales data file name in variable outputFile 
	cout << "Enter the output file name: ";
	cin >> outputFile;
	cout << endl;

	//output floating point numbers in a fixed decimal format with dec point and trailing zeros (2 decimal places)
	outFile.open(outputFile.c_str());
	outFile << fixed << showpoint << setprecision(2); 

	//process sales data, call function getData
	getData(inFile, salesPersonList, NO_OF_SALES_PERSON);

	//calculate total sales by quarter, call saleByQuarter function 
	saleByQuarter(salesPersonList, NO_OF_SALES_PERSON, totalSaleByQuarter);

	//calculate total sales for each salesperson 
	totalSaleByPerson(salesPersonList, NO_OF_SALES_PERSON);

	//print report in tabular format
	printReport(outFile, salesPersonList, NO_OF_SALES_PERSON, totalSaleByQuarter);

	//find and print the salesperson who produced max sales for the year
	maxSaleByPerson(outFile, salesPersonList, NO_OF_SALES_PERSON); 

	//find and print quarter that produced max sales for the year 
	maxSaleByQuarter(outFile, totalSaleByQuarter); 

	inFile.close(); 
	outFile.close(); 

	return 0; 
}