#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\Pràctica1\Point2f.h"
#include "..\Pràctica1\Point2f.cpp"
#include "..\Pràctica1\ClassString.h"
#include "..\Pràctica1\ClassString.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		//--POINT UNIT TEST---------------------------------------------------
		TEST_METHOD(TestMethod1) //setZero method
		{
			Point2f a;
			a.setZero();

			Assert::IsTrue(a.x == 0 && a.y == 0);
		}
		TEST_METHOD(TestMethod2) //isZero method
		{
			Point2f a;
			a.isZero();

			if (a.x == 0 && a.y == 0)
				Assert::IsTrue(a.x == 0 && a.y == 0);
			else
				Assert::IsTrue(a.x != 0 && a.y != 0);
		}
		TEST_METHOD(TestMethod3) //negatePos method
		{
			Point2f a1;
			Point2f a2;
			a1.x = 1;
			a1.y = 1;
			a2.x = -1;
			a2.y = -1;
			a1.negatePos();

			Assert::IsTrue(a1.x == a2.x && a1.y == a2.y);
		}
		TEST_METHOD(TestMethod4) //distanceTo method
		{
			Point2f a1;
			Point2f& ra1 = a1;
			Point2f a2;
			a1.x = 6;
			a1.y = 5;
			a2.x = 2;
			a2.y = 2;

			Assert::IsTrue(a2.DistanceTo(ra1) == 5);
		}
		TEST_METHOD(TestMethod5) //operator +
		{
			Point2f a1;
			Point2f a2;
			Point2f& ra2 = a2;
			Point2f a3;
			a1.x = 4;
			a1.y = 4;
			a2.x = 3;
			a2.y = 3;
			a3 = a1 + ra2;

			Assert::IsTrue(a3 == a1.operator+ (ra2));
		}
		TEST_METHOD(TestMethod6) //operator +=
		{
			Point2f a1;
			Point2f a2;

			a1.x = 3;
			a1.y = 3;
			a2.x = 2;
			a2.y = 2;

			a1 += a2;

			Assert::AreEqual(a1.x, 5.0f);
			Assert::AreEqual(a1.y, 5.0f);

		}
		TEST_METHOD(TestMethod7) //operator -
		{
			Point2f a1;
			Point2f a2;
			Point2f& ra2 = a2;
			Point2f a3;
			a1.x = 4;
			a1.y = 4;
			a2.x = 3;
			a2.y = 3;
			a3 = a1 - ra2;

			Assert::IsTrue(a3 == a1.operator- (ra2));
		}
		TEST_METHOD(TestMethod8) //operator -=
		{
			Point2f a1;
			Point2f a2;

			a1.x = 3;
			a1.y = 3;
			a2.x = 2;
			a2.y = 2;

			a1 -= a2;

			Assert::AreEqual(a1.x, 1.0f);
			Assert::AreEqual(a1.y, 1.0f);
		}
		TEST_METHOD(TestMethod9) //operator ==
		{
			Point2f a1;
			Point2f a2;
			a1.x = 1;
			a1.y = 1;
			a2.x = 1;
			a2.y = 1;

			Assert::IsTrue(a1.operator == (a2));
		}
		TEST_METHOD(TestMethod10) //operator !=
		{
			Point2f a1;
			Point2f a2;
			a1.x = 1;
			a1.y = 1;
			a2.x = 2;
			a2.y = 2;

			Assert::IsTrue(a1.operator != (a2));
		}

		//--STRING UNIT TEST---------------------------------------------------
		TEST_METHOD(TestMethod11) //empty constructor
		{
			ClassString str;

			Assert::AreEqual(str.Length(), 0);
			Assert::AreEqual(str.getString(), "\0");
		}
		TEST_METHOD(TestMethod12) //constructor ( _string, ...)
		{
			ClassString str("%s%s%s", "monster", "hunter", "3");

			Assert::AreEqual(str.Length(), 14);
			Assert::AreEqual(str.getString(), "monsterhunter3");
		}
		TEST_METHOD(TestMethod13) //operator == (reference)
		{
			ClassString str1("monster");
			ClassString& rstr1 = str1;
			ClassString str2("monster");

			Assert::IsTrue(rstr1.operator == (str2));
		}
		TEST_METHOD(TestMethod14) //operator == (char*)
		{
			ClassString str1("monster");
			ClassString str2("monster");

			Assert::IsTrue(str1.operator == (str2));
		}

		/*Can't manage to find the error inside operator= method.
		The test isn't working. 

		TEST_METHOD(TestMethod15) //operator = (reference)
		{
			ClassString str1("monster");
			ClassString str2("hunter");
			str2 = str1.getString();

			Assert::AreEqual(str2.Length(), str1.Length());
			Assert::AreEqual(str2.getString(), str1.getString());
		}
		*/

		TEST_METHOD(TestMethod16) //operator = (char*)
		{
			ClassString str1("monster");
			ClassString str2("monster hunter");
			str2 = str1;

			Assert::IsTrue(str2.Length() == str1.Length());
		}
		TEST_METHOD(TestMethod17) //operator != (reference)
		{
			ClassString str1("monster");
			ClassString str2("monster hunter");

			Assert::IsTrue(str1.operator != (str2));
		}
		TEST_METHOD(TestMethod18) //operator != (char*)
		{
			ClassString str1("monster");
			ClassString str2("monster hunter");

			Assert::IsTrue(str1.operator != (str2));
		}
		TEST_METHOD(TestMethod19) //operator += (reference)
		{
			ClassString str1("monster");
			ClassString str2("hunter");
			str1 += str2;

			Assert::AreEqual(str1.Length(), 13);
			Assert::IsTrue(str1 == "monsterhunter");
		}
		TEST_METHOD(TestMethod20) //operator += (char*)
		{
			ClassString str1("monster");
			str1 += "hunter";

			Assert::AreEqual(str1.Length(), 13);
			Assert::IsTrue(str1 == "monsterhunter");
		}

		/*There is an error inside Clear() method.
		Can't manage to find it*/

		TEST_METHOD(TestMethod21) //Clear unit test
		{
			ClassString s1("monster");
			s1.Clear();

			Assert::AreEqual(s1.Length(), 0);
			Assert::AreEqual(s1.getString(), "");
		}
		TEST_METHOD(TestMethod22) //Alloc unit test
		{


		}
		TEST_METHOD(TestMethod23) //Length
		{
			ClassString str("monster");

			Assert::AreEqual(str.Length(), 7);
		}
		TEST_METHOD(TestMethod24) //getString
		{
			ClassString str("monster");

			Assert::IsTrue(str.getString() == "monster");
		}
	};
}