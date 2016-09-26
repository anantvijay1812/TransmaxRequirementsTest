#include "stdafx.h"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace	Microsoft::VisualStudio::TestTools::UnitTesting;

namespace GradesDllTest
{
	[TestClass]
	public ref class UnitTest
	{
	public: 
		/*
		 * Test the comparator used in the Record class of GradesDll 
		 */
		[TestMethod]
		void TestRecordComparator()
		{
			Record rec1("First", "Place", 99);
			Record rec2("Second", "Place", 98);

			// rec1 has a higher score that rec2
			Assert::IsTrue(rec2 < rec1);

			// Same score, but rec1's last-name comes before rec3's
			Record rec3("Ground", "Place", 99);
			Assert::IsTrue(rec3 < rec1);


			// Score and last-names now match, all down to first-name
			// rec1's first name comes before rec4
			Record rec4("First", "Queen", 99);
			Assert::IsTrue(rec4 < rec1);

			// Identical!
			Record rec5("First", "Place", 99);
			Assert::IsTrue(rec5 == rec1);
		}
	};
}
