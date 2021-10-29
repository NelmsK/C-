#include <iostream>
#include <iomanip>

using namespace std; 

const double PI = 3.1416; 

int main()
{
	double radius; //declares radius to be a variable of type double 
	double* radiusPtr; //declares radiusPtr to be a pointer variable of type double 

	cout << fixed << showpoint << setprecision(2); 

	radius = 2.5; //stores 2.5 in radius 
	radiusPtr = &radius; //stores the address of radius in radiusPtr 

	//outputs the radius and area of the circle using the value stored in the memory location radius
	cout << "Line 12: Radius = " << radius
		<< ", area = " << PI * radius * radius
		<< endl; 

	//outputs the radius and area of the circle using the value stored in the memory location to which
	//radiusPtr is pointing 
	cout << "Line 13: Radius " << *radiusPtr
		<< ", area = "
		<< PI * (*radiusPtr) * (*radiusPtr)
		<< endl;

	//output in lines 12 and 13 same b/c radiusPtr points to radius 

	cout << "Line 14: Enter the radius: "; //prompts user to input the radius 
	cin >> *radiusPtr; //stores the radius in the memory location to which radiusPtr is pointing 
	cout << endl; 

	//Lines 17 and 18 outpout the radius and area using the variables radius and radiusPtr
	cout << "Line 17: Radius = " << radius << ", area = "
		 << PI * radius * radius << endl; 
	cout << "Line 18: Radius = " << *radiusPtr
		<< ", area = "
		<< PI * (*radiusPtr) * (*radiusPtr) << endl
		<< endl; 

	//The lines 19 to 22 output the address of radiusPtr, the value stored in radiusPtr, the address of radius, 
	//and the value stored in radius. 
	cout << "Line 19: Address of radiusPtr: "
		<< &radiusPtr << endl; 
	cout << "Line 20: Value stored in radiusPtr: "
		<< radiusPtr << endl; 
	cout << "Line 21: Address of radius: "
		<< &radius << endl; 
	cout << "Line 22: Value stored in radius: "
		<< radius << endl; 

	return 0; 

}