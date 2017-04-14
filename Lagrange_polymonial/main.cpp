#include <iostream>
#include <time.h>
using namespace std;

double lagrangePolynomial(double *args, double *values, double valueAtPoint, int arraySize);

int main()
{
	srand(time(NULL));
	int arraySize;
	cout << "Enter array size: ";
	cin >> arraySize;

	double *valuesAtPoint = new double[arraySize];
	double *functionValuesAtPoint = new double[arraySize];

	for (int i = 0; i < arraySize; i++)
		valuesAtPoint[i] = rand() % 10;

	for (int i = 0; i < arraySize; i++)
		functionValuesAtPoint[i] = valuesAtPoint[i] * valuesAtPoint[i];

	int argumentNumber;
	cout << "Enter argument to calculate value in: ";
	cin >> argumentNumber;

	cout << endl << "Value at point is equal to: " << lagrangePolynomial(valuesAtPoint, functionValuesAtPoint, argumentNumber, arraySize) << endl;

	system("PAUSE");
}

double lagrangePolynomial(double *args, double *values, double valueAtPoint, int arraySize)
{
	double valueInTheSearchPoint = 0.0;
	double tmpValue = 0.0;

	for (int i = 0; i < arraySize; i++)
	{
		tmpValue = 1.0;

		for (int j = 0; j < arraySize; j++)
			if (j != i)
				tmpValue = tmpValue*((valueAtPoint - args[j]) / (args[i] - args[j]));

		valueInTheSearchPoint += tmpValue * values[i];
	}

	return valueInTheSearchPoint;
}