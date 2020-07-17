#include <iostream>
#include <string>
#include "dot.h"
#include "vector.h"
using namespace std;
int main()
{
	int dim;
	string v1, v2;
	cout << "Please enter two vectors you want to calculate:\nDimension: ";
	cin >> dim;
	cin.ignore(1000, '\n');
	cout << "Vector 1: ";
	getline(cin, v1);
	cout << "Vector 2: ";
	getline(cin, v2);
	cout << "\n";
	try
	{
		Vector u = createVectorFromStringOfNumbers(v1, dim);
		Vector v = createVectorFromStringOfNumbers(v2, dim);
		cout << sumAnswer(u, v) << endl;
		cout << substractAnswer(u, v) << endl;
		cout << dotAnswer(u, v, dim) << endl;
	}
	catch (int err)
	{
		cout << "Invalid Input\n";
	}
	return 0;
}