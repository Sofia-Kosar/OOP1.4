#include "pch.h"
#include "CppUnitTest.h"
#include "../OOP1.44/Polynomial.h"
#include "../OOP1.44/Polynomial.cpp"
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest14
{
    TEST_CLASS(UnitTest14)
    {
    public:

        TEST_METHOD(TestSubtraction)
        {
            // Arrange
            Polynomial p1, p2;
            std::vector<double> p1Coefficients = { 1, 2, 3 };
            std::vector<double> p2Coefficients = { 2, 3, 4 };

            // Initializing p1(x) = 1 + 2x + 3x^2
            p1.Init(2, p1Coefficients.data());

            // Initializing p2(x) = 2 + 3x + 4x^2
            p2.Init(2, p2Coefficients.data());

            // Expected result: -1 - x - x^2
            std::vector<double> expectedCoefficients = { -1, -1, -1 };
            Polynomial expectedResult;
            expectedResult.Init(2, expectedCoefficients.data());

            // Act
            Polynomial result = p1.subtract(p2);

            // Assert
            Assert::AreEqual(expectedResult.getDegree(), result.getDegree());
            for (int i = 0; i <= expectedResult.getDegree(); ++i) {
                Assert::AreEqual(expectedCoefficients[i], result.getCoefficients()[i]);
            }
        }

        TEST_METHOD(TestAddition)
        {
            // Arrange
            Polynomial p1, p2;
            std::vector<double> p1Coefficients = { 1, 2, 3 };
            std::vector<double> p2Coefficients = { 2, 3, 4 };

            // Initializing p1(x) = 1 + 2x + 3x^2
            p1.Init(2, p1Coefficients.data());

            // Initializing p2(x) = 2 + 3x + 4x^2
            p2.Init(2, p2Coefficients.data());

            // Expected result: 3 + 5x + 7x^2
            std::vector<double> expectedCoefficients = { 3, 5, 7 };
            Polynomial expectedResult;
            expectedResult.Init(2, expectedCoefficients.data());

            // Act
            Polynomial result = p1.add(p2);

            // Assert
            Assert::AreEqual(expectedResult.getDegree(), result.getDegree());
            for (int i = 0; i <= expectedResult.getDegree(); ++i) {
                Assert::AreEqual(expectedCoefficients[i], result.getCoefficients()[i]);
            }
        }
    };
}