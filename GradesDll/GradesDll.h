#include "stdafx.h"
#include "Record.h"

#define GRADESDLL_API __declspec(dllexport) 

namespace Grades
{
	#define NUM_FIELDS 3

    class OrganizeGrades
    {
    public: 
        // Tokenize string separated by delimiter
        static GRADESDLL_API void tokenize(const string& str, vector<string>& tokens, const string& delimiters = " "); 

        // Reads the records from the file and stores them in the ordered priority queue.
        static GRADESDLL_API priority_queue<Record> parseRecords(const string& fileName);
    };
}