#include "pch.h"
#include "CppUnitTest.h"

extern "C" char* analyzeTriangle(int, int, int);


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TESTTRIANGLE
{
	TEST_CLASS(TESTTRIANGLE)
	{
	public:
		
		TEST_METHOD(Analyze)
		{
			// This is testing the function analyzeTriangle 
			// using sides of triangle 8 7 6, it should return "   Scalene triangle"
			char* result = "";
			result = analyzeTriangle(8,7,6);
			Assert::AreEqual("   Scalene triangle", result);

		}
	};
}
