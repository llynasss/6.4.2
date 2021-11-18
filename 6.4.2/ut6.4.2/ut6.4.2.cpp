#include "pch.h"
#include "CppUnitTest.h"
#include "../6.4.2/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ut642
{
	TEST_CLASS(ut642)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			double a[4] = { -1, 2, 3, -4 };

			double s = 0;

			s = sum(a, 4, 0, 0);

			Assert::AreEqual(-5.0, s);
		}
	};
}
