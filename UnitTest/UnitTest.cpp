#include "pch.h"
#include "CppUnitTest.h"
#include"../Brainfuck/ArrayOfValues.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{

    TEST_CLASS(BFarray)
    {
    public:
        ArrayOfValues array;
        TEST_METHOD(Test1)
        {
            array.plus();
            array.plus();
            Assert::AreEqual(array.getValue(), 2);
        }

        TEST_METHOD(Test2)
        {
            array.increment();
            array.plus();
            Assert::AreEqual(array.getValue(), 1);
        }

        TEST_METHOD(Test3)
        {
            array.minus();
            array.minus();
            Assert::AreEqual(array.getValue(), -2);
        }

    };
    


}


