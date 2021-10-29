//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                     
// Filename: Cylinder.h
// Date: October 09, 2021
// Programmer: Kristen Nelms            
//
// Description:
//		Define a class Cylinder which implements the overloaded operators described in the driver given below.
//			A.The default Cylinder is a Cylinder where the radius and height are equal to 1. 
//			B.The overloaded arithmetic operators perform the operations on the radius and height of the Cylinder(i.e. operator+(...)  
//			 will add the radius and radius of the two Cylinders)
//			C.When comparing Cylinders, you should compare the volume of the Cylinders. 
//			D.The unary++ operator should increment both radiusand height by one. 
//			E.When displaying a Cylinder, you should display the radius, height volume and surface area of the Cylinder. 
// 
//		NOTE: If the operation results in a radius or height <= 0 then change the Cylinder radius and height to 1 by default.
//                                                                  
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <ostream>
class Cylinder
{
public: 
	void setInfo(double&, double&); 
	double getRadius(); 
	double getHeight(); 
	double calcVol(); 
	double calcSurfaceArea();  
	Cylinder(); 
	Cylinder(double, double);

	bool operator==(Cylinder& cylinder);
	bool operator!=(Cylinder& cylinder); 
	bool operator>=(Cylinder& cylinder); 
	bool operator<=(Cylinder& cylinder);
	bool operator<(Cylinder& cylinder); 
	bool operator>(Cylinder& cylinder);

	Cylinder operator+ (const Cylinder&) const; 
	Cylinder operator- (const Cylinder&) const; 
	Cylinder operator* (const Cylinder&) const; 

	Cylinder operator++(int);
	//for use with cout : cout << radius << height;
		//friend function gives it access to private "parts" of Cylinder class; gives it direct access to private height and radius variables

private: 
	double radius = 1; 
	double height = 1; 
};
