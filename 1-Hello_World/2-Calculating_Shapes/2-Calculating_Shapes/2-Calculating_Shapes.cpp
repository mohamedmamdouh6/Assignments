#include <iostream>
using namespace std;

void main()
{
	float length;
	float breadth;
	float base;
	float height;
	float radius;

	// Rectangle
	cout << "		Rectangle" << endl;
	cout << "Enter length: ";
	cin >> length;
	cout << "Enter breadth: ";
	cin >> breadth;
	cout << "Perimeter: " << 2.0f * (length * breadth) << endl;
	cout << "Area: " << length * breadth << endl;

	// Square
	cout << "		Square" << endl;
	cout << "Enter length: ";
	cin >> length;
	cout << "Perimeter: " << length * length << endl;
	cout << "Area: " << 4.0f * length << endl;

	// Triangle
	cout << "		Triangle" << endl;
	cout << "Enter base: ";
	cin >> base;
	cout << "Enter heigt: ";
	cin >> height;
	cout << "Area: " << 0.5f * (base * height) << endl;

	// Circle
	cout << "		Circle" << endl;
	cout << "Enter radius: ";
	cin >> radius;
	cout << "Area: " << radius * radius * 3.14159f << endl;
	cout << "Circumference: " << 2.0f * 3.14159f * radius << endl;

	// Cube
	cout << "		Cube" << endl;
	cout << "Enter length: ";
	cin >> length;
	cout << "Surface: " << 6.0f * length * length << endl;
	cout << "Volume: " << length * length * length << endl;

	// Cylinder
	cout << "		Cylinder" << endl;
	cout << "Enter radius: ";
	cin >> radius;
	cout << "Enter height: ";
	cin >> height;
	cout << "Curved Surface Area: " << 2.0f * 3.14159f * radius * height << endl;
	cout << "Total Surface Area: " << 2.0f * 3.14159f * radius * (radius + height) << endl;
	cout << "Volume: " << 3.14f * radius * radius * height << endl;

	// Sphere
	cout << "		Sphere" << endl;
	cout << "Enter radius: ";
	cin >> radius;
	cout << "Surface Area: " << 4.0f * 3.14159f * radius * radius << endl;
	cout << "Volume: " << (4.0f / 3.0f) * 3.14159f * radius * radius * radius << endl;
}