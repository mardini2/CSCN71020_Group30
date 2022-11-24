#include "pch.h"
#include "CppUnitTest.h"

extern "C"
{
#include"main.h"
#include <triangleSolver.h>
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PolygonCheckerTests
{
	TEST_CLASS(PolygonCheckerTests)
	{
	public:
		
		TEST_METHOD(T001_TypeOfTriangle_ZeroAndZeroAndZero_NotATriangle)
		{
			int side1 = 0;
			int side2 = 0;
			int side3 = 0;

			char* result = analyzeTriangle(side1, side2, side3);

			Assert::AreEqual("Not a Triangles", result);
		}
		TEST_METHOD(T002_TypeOfTriangle_FiveAndFiveAndFive_EquilateralTriangle)
		{
			int side1 = 5;
			int side2 = 5;
			int side3 = 5;

			char* result = analyzeTriangle(side1, side2, side3);

			Assert::AreEqual("Equilateral Triangle", result);
		}
		TEST_METHOD(T003_TypeOfTriangle_OneAndOneAndFive_IsocelesTriangle)
		{
			int side1 = 1;
			int side2 = 1;
			int side3 = 5;

			char* result = analyzeTriangle(side1, side2, side3);

			Assert::AreEqual("Isoceles Triangles", result);
		}
		TEST_METHOD(T004_TypeOfTriangle_OneAndTwoAndThree_ScaleneTriangle)
		{
			int side1 = 1;
			int side2 = 2;
			int side3 = 3;

			char* result = analyzeTriangle(side1, side2, side3);

			Assert::AreEqual("Isoceles Triangles", result);
		}
	};
}
