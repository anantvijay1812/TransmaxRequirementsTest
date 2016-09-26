#pragma once
#include"stdafx.h"
#define RECORDDLL_API __declspec(dllexport) 

class Record
{
	string m_FirstName;
	string m_LastName;
	int m_Score;

public:
	RECORDDLL_API Record(string firstName, string lastName, int score);
	RECORDDLL_API Record(const Record& pRec);
	RECORDDLL_API Record& operator=(const Record& pRec);
	RECORDDLL_API bool operator==(const Record& pRec) const;
	RECORDDLL_API bool operator<(const Record& pRec) const;

	RECORDDLL_API string getFirstName()
	{
		return m_FirstName;
	}
	RECORDDLL_API string getLastName()
	{
		return m_LastName;
	}
	RECORDDLL_API int getScore()
	{
		return m_Score;
	}
};

