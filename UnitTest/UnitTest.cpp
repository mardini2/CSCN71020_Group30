#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

extern "C" char* analyzeTriangle(int, int, int);
extern "C" char* angleTriangle(int, int, int);
extern "C" bool validCoordinates(double*, double*);
extern "C" double findPerimeter(double*, double*);
extern "C" double findArea(double*, double*);
extern "C" void orderCoordinates(double* X, double* Y);

namespace UnitTest
{
	TEST_CLASS(TESTTRIANGLE)
	{
	public:

		TEST_METHOD(Analyze)
		{
			// This is testing the function analyzeTriangle 
			// using sides of triangle 8 7 6, it should return "   Scalene triangle"
			char* result = "";
			result = analyzeTriangle(8, 7, 6);
			Assert::AreEqual("   Scalene triangle", result);
		}
		TEST_METHOD(Angle)
		{
			// This is testing the function angleTriangle 
			// using sides of triangle 4 4 4, it should return "Inside Angles, Side 1's Angle:  60.00 , Side 2's Angle:  60.00 , Side 3's Angle:  60.00"
			char* angles = "";
			angles = angleTriangle(4, 4, 4);
			Assert::AreEqual("Inside Angles, Side 1's Angle:  60.00 , Side 2's Angle:  60.00 , Side 3's Angle:  60.00", angles);
		}
	};

	TEST_CLASS(TESTRECTANGLE)
	{
	public:

		TEST_METHOD(Validate)
		{

			// This is testing the function validCoordinates 
			// using two array X[1,11,11,1] and Y [2,2,8,8] which represent 4 points(X,Y), it should return "True" if it is a rectangle
			// and "False" if it is not a rectangle
			double  X[] = { 1,11,11,1 }, Y[] = { 2,2,8,8 };
			bool result = false;
			result = validCoordinates(X, Y);
			Assert::AreEqual(true, result);

		}
		TEST_METHOD(OrderPoints)
		{

			// This is testing the function orderCoordinates 
			// using two array X[1,1,11,11 ] and Y [2,8,2,8] which represent 4 points(X,Y), 
			// it should return points in order: X[] = { 1,11,11,1 }, Y[] = { 2,2,8,8 };
			double X[] = { 1,1,11,11 }, Y[] = { 2,8,2,8 };
			orderCoordinates(X, Y);
			Assert::AreEqual(1.0, X[0]);
			Assert::AreEqual(2.0, Y[0]);

			Assert::AreEqual(11.0, X[1]);
			Assert::AreEqual(2.0, Y[1]);

			Assert::AreEqual(11.0, X[2]);
			Assert::AreEqual(8.0, Y[2]);

			Assert::AreEqual(1.0, X[3]);
			Assert::AreEqual(8.0, Y[3]);

		}

		TEST_METHOD(Perimeter)
		{
			// This is testing the function findPerimeter 
			// using two array XX[1,11,11,1] and Y [2,2,8,8] which represent 4 points(X,Y), it should return 32
			double  X[] = { 1,11,11,1 }, Y[] = { 2,2,8,8 };
			double result = 0.0;
			result = findPerimeter(X, Y);
			Assert::AreEqual(32.0, result);
		}
		TEST_METHOD(Area)
		{
			// This is testing the function findPerimeter 
			// using two array X[1,11,11,1] and Y [2,2,8,8] which represent 4 points(X,Y), it should return 60
			double  X[] = { 1,11,11,1 }, Y[] = { 2,2,8,8 };
			double result = 0.0;
			result = findArea(X, Y);
			Assert::AreEqual(60.0, result);
		}
	};
}
