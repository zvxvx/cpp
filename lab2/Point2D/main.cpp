#include <iostream>
#include "Point2D.h"

int main() {
	Point2D P1, P2;

	double xP, yP;
	cout << "\nEnter the x coordinate of the first point: " << endl;
	cin >> xP;

	cout << "Enter the y coordinate of the first point: " << endl;
	cin >> yP;

	P1 = { xP, yP };

	cout << "Enter the x coordinate of the second point: " << endl;
	cin >> xP;

	cout << "Enter the y coordinate of the second point: " << endl;
	cin >> yP;

	P2 = { xP, yP };

	cout << endl;

	cout << "Multiplied value of P1 and P2: " << P1.multiplyPoints(P2) << endl;

	return 0;
}