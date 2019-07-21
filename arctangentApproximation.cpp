// Gabe Mersy
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace  std;

double arctanApprox(double x, double tol);

int main()
{
	double tol;
	char c;
	do{
	// Inputting tolerance 
	cout << "Input tolerance: ";
	cin >> tol;
	while (tol <= 0)
	{
	cout << "Tolerance must be positive. Input tolerance: ";
	cin >> tol;
	}
	// Call arctanApprox funtions for the two values 
	double firstValue = arctanApprox(1.0/5.0, tol/20.0);
	double secondValue = arctanApprox(1.0/239.0, tol/20.0);
	// Compute pis
	double pi = 16.0*firstValue - 4.0*secondValue;
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(13);
	cout << "Pi approximation: " << pi << endl;
	cout << "Do you wish to approximate pi again? ";
	cin >> c;
	} while (c == 'y' || c == 'Y');
}

double arctanApprox(double x, double tol)
{
	//Function definition
	double newEstimate = x;
	double xpow = x;
	double oldEstimate = 0.0;
	int denom = 1;
	do
	{
		oldEstimate = newEstimate;
		if(denom < 0)
		{
			denom = -denom + 2;
		}
		else
		{
			denom = -denom - 2;
		}
	xpow *= (x*x);
	newEstimate = oldEstimate + (xpow/denom);

	}
	while(abs(-newEstimate + oldEstimate) >= tol);
	return newEstimate;
}
