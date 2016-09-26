#pragma once
#include "stdafx.h"
using namespace std;

class StringUtils
{
public:
	StringUtils(void);
	~StringUtils(void);

	static string trim(const string& s);
	static string trimLeft(const string& s);
	static string trimRight(const string& s);
};

