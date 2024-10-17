#include "pch.h"
#include "CppUnitTest.h"
#include "../LR6.4rec/LR6.4rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TEST_METHOD_1)
		{

			double* b = new double[5];
			b[0] = 4.444;b[1] = -19.43;b[2] = 11;b[3] = 1.00;b[4] = 17.224;
			double result = MinElement(b, 5, b[0], 0);
			double expected = b[1];
			Assert::AreEqual(result, expected, 0.000001);
		}

		TEST_METHOD(TEST_METHOD_2)
		{
			double sum = 0;
			double* b = new double [5];
			b[0] = -3;b[1] = 6;b[2] = 14.2;b[3] = -9;b[4] = 67;
			int firstInd = 0, secondInd = 3;
			double result = SumBetweenElements(b, firstInd, secondInd, sum);
			double expected = 6 + 14.2;
			Assert::AreEqual(result, expected, 0.0000001);
		}

		TEST_METHOD(TEST_METHOD_3)
		{
			int i = 0, N = 0, n = 5;
			double* b = new double [5];
			b[0] = 5;b[1] = 6.2;b[2] = -17.78;b[3] = -9;b[4] = 6.7;
			double result = negativeLeftElement(b, n, N, i);
			double expected = -17.78;
			Assert::AreEqual(result, expected, 0.000001);
		}
	};
}
