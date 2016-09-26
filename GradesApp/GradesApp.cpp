// GradesApp.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "Record.h"
#include "GradesDll.h"

int main(int argc, char* argv[])
{
	if(argc != 2)
	{
		cout<<"Usage: GradesApp.exe <File Name>";
		return 0;
	}

	//Stores the input file name into a string. 
	string inputFileName = argv[1];

	//Uses the parseRecords method of the GradesDLL to sort the contents of the input file and store them in
	//a queue.
	priority_queue<Record> organizedRecords = Grades::OrganizeGrades::parseRecords(inputFileName);

	//generate the nameof the output file based on the input file.
	string outFileName = inputFileName.substr(0, inputFileName.find_first_of('.') ) + "-graded.txt";

	ofstream outputFile;
	outputFile.open(outFileName);

	//print the sorted elements of the queue andstore them in the output file.
	while(!organizedRecords.empty())
	{
		Record re = organizedRecords.top();
		organizedRecords.pop();
		outputFile<<re.getLastName()<<", "<<re.getFirstName()<<", "<<re.getScore()<<"\n";
		cout << re.getLastName() << ", " << re.getFirstName() << ", " << re.getScore() << "\n";
	}

	cout<<"\nFinished: created "<< outFileName;
	outputFile.close();

	return 0;
}