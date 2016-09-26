#include "stdafx.h"
#include "GradesDll.h"
#include "StringUtils.h"

namespace Grades
{
	/*
	* Parse a line into a Record class object. 
	*/
	Record parseRecord(string pLine)
	{
		vector<string> tokens;

		OrganizeGrades::tokenize(pLine, tokens, ",");
	
		if(tokens.size() == NUM_FIELDS)
		{
			try {
				return Record(StringUtils::trim(tokens[1]), StringUtils::trim(tokens[0]), stoi(StringUtils::trim(tokens[2])));
			}
			catch (const std::invalid_argument& ) {
				throw "Invalid score: '"+tokens[2]+" '.Line skipped from processing.\n";
			}
		
		}
		else
		{
			throw "\nUnable to parse line: '"+pLine+"' .Line skipped from processing.\n";
		}
	}

	/*
	* Breakdown a line contaiing the last name, first name & score into individual tokens.
	*/
	void OrganizeGrades::tokenize(const string& str, vector<string>& tokens, const string& delimiters)
	{
		string::size_type lastPos = str.find_first_not_of(delimiters, 0);
		
		string::size_type pos = str.find_first_of(delimiters, lastPos);

		while (string::npos != pos || string::npos != lastPos)
		{
			tokens.push_back(str.substr(lastPos, pos - lastPos));
			lastPos = str.find_first_not_of(delimiters, pos);
			pos = str.find_first_of(delimiters, lastPos);
		}
	}

	/*
	* Parse a file containing last name, first name & scores into a sorted queue.
	*/
    priority_queue<Record> OrganizeGrades::parseRecords(const string& fileName)
	{
		priority_queue<Record> records;
		ifstream inputFile;
		
		string line;
		inputFile.open(fileName);

		for( std::string line; getline( inputFile, line ); )
		{
			try {
				records.push(parseRecord(line));
			}
			catch(string ex) {
				cout<<ex;
				continue;
			}
		}

		inputFile.close();

		return records;
	}
}