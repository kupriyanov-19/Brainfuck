#include "pch.h"
#include "CppUnitTest.h"
#include"../Brainfuck/BrainfuckParser.h"
#include"../Brainfuck/BrainfuckParser.cpp"
#include"../Brainfuck/BrainfuckTokenizer.h"
#include"../Brainfuck/BrainfuckTokenizer.cpp"
#include"../Brainfuck/BrainfuckVirtualMachine.h"
#include"../Brainfuck/BrainfuckVirtualMachine.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{

    TEST_CLASS(BFtokenizer)
    {
    public:
        BrainfuckTokenizer tokenizer;
        TEST_METHOD(Test1)
        {
            std::string string = "..";
            std::vector<Tokens> expected = { Tokens::PRINT, Tokens::PRINT };
            std::vector<Tokens> result = tokenizer.tokenize(string);
            Assert::AreEqual(result.size(), expected.size());
            for (int i = 0; i < expected.size(); i++)
                Assert::AreEqual(static_cast<int>(result[i]), static_cast<int>(expected[i]));
        }

        TEST_METHOD(Test2)
        {
            std::string string = "[+]";
            std::vector<Tokens> expected = { Tokens::STARTCYCLE, Tokens::PLUS, Tokens::ENDCYCLE };
            std::vector<Tokens> result = tokenizer.tokenize(string);
            Assert::AreEqual(result.size(), expected.size());
            for (int i = 0; i < expected.size(); i++)
                Assert::AreEqual(static_cast<int>(result[i]), static_cast<int>(expected[i]));
        }

        TEST_METHOD(Test3)
        {
            std::string string = "><+-.[]";
            std::vector<Tokens> expected = { Tokens::INCREMENT, Tokens::DECREMENT, Tokens::PLUS, Tokens::MINUS,
                Tokens::PRINT, Tokens::STARTCYCLE, Tokens::ENDCYCLE };
            std::vector<Tokens> result = tokenizer.tokenize(string);
            Assert::AreEqual(result.size(), expected.size());
            for (int i = 0; i < expected.size(); i++)
                Assert::AreEqual(static_cast<int>(result[i]), static_cast<int>(expected[i]));
        }

    };

    TEST_CLASS(BFparser)
    {
    public:
        BrainfuckParser parser;

        bool compareNodes(const Node& first, const Node& second) {
            if (first.isInstruction() ^ second.isInstruction()) return false;
            if (first.isInstruction())
                return (first.getInstruction() == second.getInstruction());
            else
                return compareVectors(*first.getChild(), *second.getChild());
        }

        bool compareVectors(const std::vector<Node>& first, const std::vector<Node>& second) {
            if (first.size() != second.size()) return false;
            bool answer = true;
            for (int i = 0; i < first.size(); i++)
                answer &= compareNodes(first[i], second[i]);
            return answer;
        }
        TEST_METHOD(Test1)
        {
            std::vector<Tokens> tokens = { Tokens::PRINT, Tokens::PLUS };
            std::vector<Node> expected = { Node(Instructions::PRINT), Node(Instructions::PLUS) };
            std::vector<Node> result = parser.parse(tokens.begin(), tokens.end());
            Assert::AreEqual(compareVectors(expected, result), true);
        }

        TEST_METHOD(Test2)
        {
            std::vector<Tokens> tokens = { Tokens::STARTCYCLE, Tokens::INCREMENT, Tokens::ENDCYCLE };
            std::vector<Node> cycleBody = std::vector<Node>{ Node(Instructions::INCREMENT) };
            std::vector<Node> expected = { Node(cycleBody) };
            std::vector<Node> result = parser.parse(tokens.begin(), tokens.end());
            Assert::AreEqual(compareVectors(expected, result), true);
        }

        TEST_METHOD(Test3)
        {
            std::vector<Tokens> tokens = { Tokens::MINUS, Tokens::PRINT, Tokens::STARTCYCLE, Tokens::ENDCYCLE };
            std::vector<Node> expected = { Node(Instructions::MINUS), Node(Instructions::PRINT), Node() };
            std::vector<Node> result = parser.parse(tokens.begin(), tokens.end());
            Assert::AreEqual(compareVectors(expected, result), true);
        }

        TEST_METHOD(Test4)
        {
            std::vector<Tokens> tokens = { Tokens::STARTCYCLE, Tokens::STARTCYCLE, Tokens::ENDCYCLE, Tokens::PLUS, Tokens::ENDCYCLE };
            std::vector<Node> cycleBody = std::vector<Node>{ Node(), Node(Instructions::PLUS) };
            std::vector<Node> expected = { Node(cycleBody) };
            std::vector<Node> result = parser.parse(tokens.begin(), tokens.end());
            Assert::AreEqual(compareVectors(expected, result), true);
        }
    };
}
