#include "pch.h"
#include "CppUnitTest.h"

extern "C"
{
	#include "..\BCSRec\main.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BCSRecTesting
{
    TEST_CLASS(BCSRecTesting)
    {
    public:
        // Test for getPerimeter function
        TEST_METHOD(TestGetPerimeter)
        {
            int length = 8;
            int width = 12;
            int expectedPerimeter = 40; // 2 * length + 2 * width
            int actualPerimeter = getPerimeter(&length, &width);

            // Assert if the actual perimeter matches the expected value
            Assert::AreEqual(expectedPerimeter, actualPerimeter);
        }

        //Test for getArea function
        TEST_METHOD(TestGetArea)
        {
            int length = 8;
            int width = 12;
            int expectedArea = 96; // length * width
            int actualArea = getArea(&length, &width);

            //Assert if the actual area matches the expected value
            Assert::AreEqual(expectedArea, actualArea);
        }





        // Test 1: Valid input within range (usual case)
        TEST_METHOD(TestSetLength_ValidInput)
        {
            int length = 0;
            setLength(50, &length);
            Assert::AreEqual(50, length); // Expected: length should be set to 50
        }

        // Test 2: Boundary case (maximum valid input)
        TEST_METHOD(TestSetLength_MaxBoundary)
        {
            int length = 0;
            setLength(99, &length);
            Assert::AreEqual(99, length); // Expected: length should be set to 99
        }

        // Test 3: Invalid input (negative number, unusual case)
        TEST_METHOD(TestSetLength_InvalidInputNegative)
        {
            int length = 10;
            setLength(-5, &length);
            Assert::AreEqual(10, length); // Expected: length should remain unchanged
        }






        // Test 1: Valid input within range (usual case)
        TEST_METHOD(TestSetWidth_ValidInput)
        {
            int width = 0;
            setWidth(20, &width);
            Assert::AreEqual(20, width); // Expected: width should be set to 20
        }

        // Test 2: Boundary case (minimum valid input)
        TEST_METHOD(TestSetWidth_MinBoundary)
        {
            int width = 0;
            setWidth(1, &width);
            Assert::AreEqual(1, width); // Expected: width should be set to 1
        }

        // Test 3: Invalid input (above maximum limit, unusual case)
        TEST_METHOD(TestSetWidth_InvalidInputAboveMax)
        {
            int width = 30;
            setWidth(150, &width);
            Assert::AreEqual(30, width); // Expected: width should remain unchanged
        }

    };

}
