#include "StdAfx.h"
#include "Record.h"

/*
* Initialization constructor with 3 arguments
*/
Record::Record(string firstName, string lastName, int score)
{
	m_FirstName = firstName;
	m_LastName = lastName;
	m_Score = score;
}

/*
* Copy construstor
*/
Record::Record(const Record& pRec)
{
	m_FirstName = pRec.m_FirstName;
	m_LastName = pRec.m_LastName;
	m_Score = pRec.m_Score;
}

/*
* Assignment Operator
*/
Record& Record::operator=(const Record& pRec)
{
	if(this == &pRec)
		return *this;

	m_FirstName = pRec.m_FirstName;
	m_LastName = pRec.m_LastName;
	m_Score = pRec.m_Score;

	return *this;
}

/*
* Compares if 2 instances of record are equal in score, last name and first name.
*/
bool Record::operator==(const Record& pRec) const
{
	if(m_FirstName == pRec.m_FirstName && m_LastName == pRec.m_LastName && m_Score == pRec.m_Score)
		return true;
	else 
		return false;
}

/* 
* Comparator to compare one record instance with the other.
* First compare by score, then last name & at last by first name.
*/
bool Record::operator<(const Record& pRec) const
{
	if(m_Score < pRec.m_Score)
		return true;
	else if(m_Score > pRec.m_Score)
		return false;
	else if(m_Score == pRec.m_Score)
	{
		if(m_LastName.compare(pRec.m_LastName) > 0)
			return true;
		else if(m_LastName.compare(pRec.m_LastName) < 0)
			return false;
		else if(m_LastName.compare(pRec.m_LastName) == 0)
		{
			if(m_FirstName.compare(pRec.m_FirstName) > 0)
			return true;
			else if(m_FirstName.compare(pRec.m_FirstName) < 0)
				return false;
			else if(m_FirstName.compare(pRec.m_FirstName) == 0)
				return true;
		}
	}
	 return true;
}