#include <stdio.h>
#include <stdbool.h>
#include<math.h>
#include <string.h>
#include <stdlib.h>
#include "triangleSolver.h"

char* analyzeTriangle(int side1, int side2, int side3)
{
	char* result = "";
	if (side1 <= 0 || side2 <= 0 || side3 <= 0) 
	{
		result = "   Not a triangle";
	}
	else if (side1 == side2 && side1 == side3) 
	{
		result = "   Equilateral triangle";
	}
	else if ((side1 == side2 && side1 != side3) || (side1 == side3 && side1 != side2))
	{
		result = "   Isosceles triangle"; 
	}
	else 
	{
		result = "   Scalene triangle";
	}

	return result;
}


int angleTriangle(int side1, int side2, int side3)
{
	char  result[100]="";
	double pi, A=0, B = 0, C = 0;		//A --> side 1, B --> side 2 , C --> side 3 


	if (side1 <= 0 || side2 <= 0 || side3 <= 0)
	{
		int output_len1 = snprintf(result, 100, "   Not a triangle, it is not possible determines angles\0");

	}
	else {

		//The Law of Cosines
		pi = acos(-1);
	
		A = (pow(side2, 2) + pow(side3, 2) - pow(side1, 2)) / (2 * side2 * side3);
		B = (pow(side1, 2) + pow(side3, 2) - pow(side2, 2)) / (2 * side1 * side3);
		C = (pow(side1, 2) + pow(side2, 2) - pow(side3, 2)) / (2 * side1 * side2);

		A = ( acos(A) * 180 / pi);
		B = ( acos(B) * 180 / pi);
		C = ( acos(C) * 180 / pi);


		int output_len2 = snprintf(result, 100, "   Inside Angles, Side 1's Angle: %6.2f , Side 2's Angle: %6.2f , Side 3's Angle: %6.2f\0", A, B, C);

	}
	printf("%s\n", result);

	return 1;
}
