#include "pch.h"
#include "CppUnitTest.h"
#include "test.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		Calculate cal1;
		TEST_METHOD(TestMethod1)
		{
			string originalText = "我叫小明";
			string plagiarzedText = "我叫小红";
			Assert::AreEqual(0.75, cal1.CalculateSimilarity(originalText, plagiarzedText));
		}
	};
}
