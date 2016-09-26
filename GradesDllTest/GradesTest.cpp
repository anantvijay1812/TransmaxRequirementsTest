#include "stdafx.h"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;
using namespace std;

namespace GradesDllTest
{
	[TestClass]
	public ref class GradesTest
	{
	private:
		TestContext^ testContextInstance;

	public: 
		/// <summary>
		///Gets or sets the test context which provides
		///information about and functionality for the current test run.
		///</summary>
		property Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ TestContext
		{
			Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ get()
			{
				return testContextInstance;
			}
			System::Void set(Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ value)
			{
				testContextInstance = value;
			}
		}; 

		/* 
		 * Test the string tokeniser of class OrganizeGrades in GradesDll
		 */
		[TestMethod]
		void TestTokenize()
		{
			string inputString = "Vijay, Anant, 90";
			vector<string> tokens;
			Grades::OrganizeGrades::tokenize(inputString, tokens, ",");
			Assert::AreEqual<int>(3, tokens.size());
			Assert::AreEqual<int>(0,tokens[0].compare("Vijay"));
			Assert::AreEqual<int>(0,tokens[1].compare(" Anant"));
			Assert::AreEqual<int>(0,tokens[2].compare(" 90"));
		};

		/*
		* Test the sorting of records using parseRecords of OrganizeGrades class in GradesDll
		*/
		[TestMethod]
		void TestParseRecords()
		{
			priority_queue<Record> organizedRecords = Grades::OrganizeGrades::parseRecords("../GradesDllTest/InputFile.txt");

			//The input file contains 11 records out of which 2 are in invalid format, therfore will be ignored.
			//The remaining 9 will be sorted and stored in the return priority queue.
			cout << organizedRecords.size();
			Assert::AreEqual<int>(9, organizedRecords.size());

			//Validating the order of each record returned in the priority queue.
			Record rec = organizedRecords.top();
			organizedRecords.pop();
			Assert::AreEqual<bool>(true, rec == Record("ewr", "cxv", 765) ? true : false);
			
			rec = organizedRecords.top();
			organizedRecords.pop();
			Assert::AreEqual<bool>(true, rec == Record("fff", "ddd", 333) ? true : false);
			
			rec = organizedRecords.top();
			organizedRecords.pop();
			Assert::AreEqual<bool>(true, rec == Record("aaa", "aad", 34) ? true : false);
			
			rec = organizedRecords.top();
			organizedRecords.pop();
			Assert::AreEqual<bool>(true, rec == Record("cbv", "aad", 34) ? true : false);
			
			rec = organizedRecords.top();
			organizedRecords.pop();
			Assert::AreEqual<bool>(true, rec == Record("cxv", "aad", 34) ? true : false);
			
			rec = organizedRecords.top();
			organizedRecords.pop();
			Assert::AreEqual<bool>(true, rec == Record("aaa", "asd", 34) ? true : false);
			
			rec = organizedRecords.top();
			organizedRecords.pop();
			Assert::AreEqual<bool>(true, rec == Record("aba", "asd", 34) ? true : false);
			
			rec = organizedRecords.top();
			organizedRecords.pop();
			Assert::AreEqual<bool>(true, rec == Record("bbb", "asd", 34) ? true : false);
			
			rec = organizedRecords.top();
			organizedRecords.pop();
			Assert::AreEqual<bool>(true, rec == Record("aaa", "bad", 34) ? true : false);
		}
	};
}
