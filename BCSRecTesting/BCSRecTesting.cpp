#include "pch.h"
#include "CppUnitTest.h"

extern "C" {
    #include "../BCSRec/main.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BCSRecTesting
{
    TEST_CLASS(PerimeterTests)
    {
    public:
        TEST_METHOD(TestPerimeter_NormalCase)
        {
            Assert::AreEqual(40, getPerimeter(8, 12));
        }

        TEST_METHOD(TestPerimeter_MinValues)
        {
            Assert::AreEqual(4, getPerimeter(1, 1));
        }

        TEST_METHOD(TestPerimeter_MaxValues)
        {
            Assert::AreEqual(400, getPerimeter(100, 100));
        }

        TEST_METHOD(TestPerimeter_Rectangle)
        {
            Assert::AreEqual(30, getPerimeter(5, 10));
        }
    };

    TEST_CLASS(AreaTests)
    {
    public:
        TEST_METHOD(TestArea_NormalCase)
        {
            Assert::AreEqual(96, getArea(8, 12));
        }

        TEST_METHOD(TestArea_MinValues)
        {
            Assert::AreEqual(1, getArea(1, 1));
        }

        TEST_METHOD(TestArea_MaxValues)
        {
            Assert::AreEqual(10000, getArea(100, 100));
        }

        TEST_METHOD(TestArea_Rectangle)
        {
            Assert::AreEqual(50, getArea(5, 10));
        }
    };

    TEST_CLASS(SetLengthTests)
    {
    public:
        TEST_METHOD(TestSetLength_ValidInput)
        {
            int length = 0;
            setLength(50, &length);
            Assert::AreEqual(50, length);
        }

        TEST_METHOD(TestSetLength_MinBoundary)
        {
            int length = 0;
            setLength(1, &length);
            Assert::AreEqual(1, length);
        }

        TEST_METHOD(TestSetLength_MaxBoundary)
        {
            int length = 0;
            setLength(100, &length);
            Assert::AreEqual(100, length);
        }

        TEST_METHOD(TestSetLength_BelowMin)
        {
            int length = 10;
            setLength(0, &length);
            Assert::AreEqual(10, length);
        }

        TEST_METHOD(TestSetLength_AboveMax)
        {
            int length = 10;
            setLength(101, &length);
            Assert::AreEqual(10, length);
        }

        TEST_METHOD(TestSetLength_Negative)
        {
            int length = 10;
            setLength(-5, &length);
            Assert::AreEqual(10, length);
        }
    };

    TEST_CLASS(SetWidthTests)
    {
    public:
        TEST_METHOD(TestSetWidth_ValidInput)
        {
            int width = 0;
            setWidth(20, &width);
            Assert::AreEqual(20, width);
        }

        TEST_METHOD(TestSetWidth_MinBoundary)
        {
            int width = 0;
            setWidth(1, &width);
            Assert::AreEqual(1, width);
        }

        TEST_METHOD(TestSetWidth_MaxBoundary)
        {
            int width = 0;
            setWidth(100, &width);
            Assert::AreEqual(100, width);
        }

        TEST_METHOD(TestSetWidth_BelowMin)
        {
            int width = 30;
            setWidth(0, &width);
            Assert::AreEqual(30, width);
        }

        TEST_METHOD(TestSetWidth_AboveMax)
        {
            int width = 30;
            setWidth(150, &width);
            Assert::AreEqual(30, width);
        }

        TEST_METHOD(TestSetWidth_Negative)
        {
            int width = 30;
            setWidth(-10, &width);
            Assert::AreEqual(30, width);
        }
    };
}
