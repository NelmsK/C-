
#include "Cylinder.h"

using namespace std;


void Cylinder::setInfo(double& r, double& h)
{
    radius = r;
    height = h;
}
double Cylinder::getRadius()
{
    return radius;
}
double Cylinder::getHeight()
{
    return height;
}

double Cylinder::calcVol()
{
    double volume;
    volume = ((3.14) * (radius * radius) * height);

    return volume;
}
double Cylinder::calcSurfaceArea()
{
    double surfaceArea;
    surfaceArea = (2 * 3.14 * radius * height) + (2 * 3.14 * (radius * radius));

    return surfaceArea; 
}

Cylinder::Cylinder() //default constructor 
//default Cylinder is Cylinder where radius and height are both equal to 1 
{
    radius = 1;
    height = 1;
}

Cylinder::Cylinder(double r, double h) //constructor with parameters
{
    height = h;
    radius = r;
}

bool Cylinder::operator==(Cylinder& cylinder)
{
    return (calcVol() == cylinder.calcVol()); 
}
bool Cylinder::operator!=(Cylinder& cylinder)
{
    return (calcVol() != cylinder.calcVol());
}
bool Cylinder::operator>=(Cylinder& cylinder) 
{
    return (calcVol() >= cylinder.calcVol());
}
bool Cylinder::operator<=(Cylinder& cylinder)
{
    return (calcVol() <= cylinder.calcVol());
}
bool Cylinder::operator<(Cylinder& cylinder)
{
    return (calcVol() < cylinder.calcVol());
}
bool Cylinder::operator>(Cylinder& cylinder) 
{
    return (calcVol() > cylinder.calcVol());
}

Cylinder Cylinder::operator+ (const Cylinder& cylinder) const
{
    Cylinder tempCylinder; 

    tempCylinder.radius = radius + cylinder.radius; 
    tempCylinder.height = height + cylinder.height; 

    return tempCylinder; 
}

Cylinder Cylinder::operator- (const Cylinder& cylinder) const
{
    Cylinder tempCylinder;

    tempCylinder.radius = radius - cylinder.radius;
    if (tempCylinder.radius < 0)
    {
        tempCylinder.radius = 1; 
    }

    tempCylinder.height = height - cylinder.height;
    if (tempCylinder.height < 0)
    {
        tempCylinder.height = 1;
    }
    return tempCylinder;
}

Cylinder Cylinder::operator* (const Cylinder& cylinder) const
{
    Cylinder tempCylinder;

    tempCylinder.radius = radius * cylinder.radius;
    tempCylinder.height = height * cylinder.height;

    return tempCylinder;
}

Cylinder Cylinder::operator++(int u)
{
    Cylinder temp = *this; 
    radius++; 
    height++; 

    return temp; 
}

ostream& operator<< (ostream& o, Cylinder& cylinder)
{
    o << "Radius: " << cylinder.getRadius() << "," << " Height: " << cylinder.getHeight() << endl; //extract data from radius and height variables to send to stream (o)

    return o; //send stream on its way 
}


int main()
{
    Cylinder Cylinder1(5.0, 10.0); //radius = 5.0 and height = 10.0                
    Cylinder Cylinder2(3.5, 20.0); //radius = 3.5 and height 20.0             
    Cylinder Cylinder3;
    Cylinder Cylinder4;
    Cylinder Cylinder5;

    cout << "Cylinder1: " << Cylinder1 << endl; 
    cout << "Cylinder2: " << Cylinder2 << endl;

    Cylinder3 = Cylinder1 + Cylinder2;

    cout << "Cylinder1 + Cylinder2 = " << "Cylinder3: " << Cylinder3 <<
        endl;

    Cylinder4 = Cylinder1 - Cylinder2;

    cout << "Cylinder1 - Cylinder2 = " << "Cylinder4: " << Cylinder4 <<
        endl;

    Cylinder5 = Cylinder1 * Cylinder2;

    cout << "Cylinder1 * Cylinder2 = " << "Cylinder5: " << Cylinder5 <<
        endl;

    if (Cylinder1 > Cylinder2)
        cout << "Volume of Cylinder1 is greater than the volume "
        << "of Cylinder2 ." << endl;
    else
        cout << "Volume of Cylinder1 is less than or equal to the volume "
        << "of Cylinder2 ." << endl;

    Cylinder1++;

    cout << "After increment the radius and height of "
        << "Cylinder1 by one unit, \nCylinder1: "
        << Cylinder1 << endl;

    Cylinder4 = Cylinder3++;

    cout << "New dimension of Cylinder3: " << Cylinder3 << endl;
    cout << "New dimension of Cylinder4: " << Cylinder4 << endl;

    cout << "Cylinder4 is " << (Cylinder4 != Cylinder3 ? "Not Equal to Cylinder3 " : "Equal to Cylinder3") << endl; 
    cout << "Cylinder4 is " << (Cylinder4 >= Cylinder3 ? "Greater or Equal to Cylinder3 " : "Not Greater or Equal to Cylinder3 ") << endl; 
    cout << "Cylinder4 is " << (Cylinder4 == Cylinder3 ? "Equal to Cylinder3 " : "Not Equal to Cylinder3") << endl; 
    cout << "Cylinder4 is " << (Cylinder4 < Cylinder3 ? "Less Than Cylinder3 " : "Not Less Than to Cylinder3") << endl; 
    cout << "Cylinder4 is " << (Cylinder4 <= Cylinder3 ? "Less Than or Equal to Cylinder3 " : "Not Less Than or Equal to Cylinder3") << endl; 


    return 0;
}