#pragma once

#include <stdio.h>
#include <stdbool.h>

void GetPointsFromUser(double* X, double* Y);
bool validCoordinates(double* X, double* Y);	//To check whether the rectangle coordinates is valid or invalid
double findPerimeter(double* X, double*Y);	//To calculate the perimeter of the figure with 4 coordinates
double findArea(double* X, double* Y);		//To calculate the area of the rectangle
