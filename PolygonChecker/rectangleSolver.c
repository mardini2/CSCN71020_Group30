#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>


#define NUMBERPOINTS  4


void GetPointsFromUser(double* X, double* Y)
{
	printf("	Please enter the 4 points (x,y) of rectangle:\n");

	for (int i = 0; i < NUMBERPOINTS; i++)
	{
		printf("		Point %d, Value X : ", i + 1);
		scanf_s("%Lf", &X[i]);
		printf("		         Value Y : ");
		scanf_s("%Lf", &Y[i]);
		printf("		\n");
	}

}

void orderCoordinates(double* X, double* Y)		//function to order coordinates
{
	double sum[NUMBERPOINTS], sumSmallest, sumLargest;
	int point1, point3;
	double tempX1 = 0, tempX2 = 0, tempX3 = 0, tempX4 = 0;
	double tempY1 = 0, tempY2 = 0, tempY3 = 0, tempY4 = 0;

	for (int i = 0; i < NUMBERPOINTS; i++)
		sum[i] = X[i] + Y[i];


	sumSmallest = sum[0], sumLargest = sum[0], point1 = 0, point3 = 0;
	for (int i = 0; i < NUMBERPOINTS; i++)
	{
		if (sumSmallest >= sum[i])
		{
			sumSmallest = sum[i];
			point1 = i;
		}
		if (sumLargest <= sum[i])
		{
			sumLargest = sum[i];
			point3 = i;
		}
	}

	double centre_x = 0.0;
	for (int i = 0; i < NUMBERPOINTS; i++)
		centre_x = centre_x + X[i];

	centre_x = (centre_x / NUMBERPOINTS);



	int point2 = point1, point4 = point1;
	for (int i = 0; i < NUMBERPOINTS; i++)
	{
		if (i != point1 && i != point3) {
			if (X[i] > centre_x)	//evaluates the rightmost X with respect to point 1
			{
				point2 = i;
			}
			else
			{
				point4 = i;
			}
		}

	}
	
	tempX1 = X[point1],tempX2 = X[point2], tempX3 = X[point3], tempX4 = X[point4];
	tempY1 = Y[point1], tempY2 = Y[point2], tempY3 = Y[point3], tempY4 = Y[point4];


	X[0] = tempX1,	X[1] = tempX2,	X[2] = tempX3,	X[3] = tempX4;
	Y[0] = tempY1,	Y[1] = tempY2,	Y[2] = tempY3,	Y[3] = tempY4;

}

//function to check whether the rectangle coordinates is valid or invalid
bool validCoordinates(double* X, double* Y)
{
	double centre_x = 0.0, centre_y = 0.0, distanceControl = 0.0, distanceAverage = 0.0;
	bool IsRectangle = false;
	
	for (int i = 0; i < NUMBERPOINTS; i++)
	{	centre_x = centre_x + X[i];
		centre_y = centre_y + Y[i];
	}
	centre_x = (centre_x / NUMBERPOINTS);
	centre_y = (centre_y / NUMBERPOINTS);
	

	distanceControl = pow((centre_x - X[0]), 2) + pow((centre_y - Y[0]), 2);
	for (int i = 0; i < NUMBERPOINTS; i++)
	{
		distanceAverage = distanceAverage + (pow((centre_x - X[i]), 2) + pow((centre_y - Y[i]), 2));
	}
	distanceAverage = distanceAverage / NUMBERPOINTS;
	
	IsRectangle = (distanceControl == distanceAverage);
	
	orderCoordinates(X, Y);	//function to order coordinates

	return IsRectangle;
}


//function to calculate the perimeter of the figure with 4 coordinates
double findPerimeter(double* X, double* Y)
{
	double P = 0,distanceP1P2 = 0, distanceP2P3 = 0, distanceP3P4 = 0, distanceP4P1 = 0;

	distanceP1P2 = sqrt(( pow((X[1] - X[0]), 2) + pow((Y[1] - Y[0]), 2)));
	distanceP2P3 = sqrt(( pow((X[2] - X[1]), 2) + pow((Y[2] - Y[1]), 2)));
	distanceP3P4 = sqrt(( pow((X[3] - X[2]), 2) + pow((Y[3] - Y[2]), 2)));
	distanceP4P1 = sqrt(( pow((X[0] - X[3]), 2) + pow((Y[0] - Y[3]), 2)));
	 
	P  = distanceP1P2 + distanceP2P3 + distanceP3P4 + distanceP4P1;
	return P;
}

//function to calculate the area of the rectangle
double findArea(double* X, double* Y)
{
	/*
	Formula: A= B * H
	Where:  B = (x2 - x1) --> It is to say X[1] - X[0]
			H = (y3 - y2) --> It is to say Y[2] - Y[1]

	*/
	double A = 0, B = 0, H = 0;

	B = (X[1] - X[0]);
	H = (Y[2] - Y[1]);


	B = (B < 0) ? (B * -1) : B;	//absolute value
	H = (H < 0) ? (H * -1) : H;//absolute value

	A = (B * H);

	return A;
}

