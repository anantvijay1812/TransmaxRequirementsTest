#include "StdAfx.h"
#include "StringUtils.h"

StringUtils::StringUtils(void)
{
}


StringUtils::~StringUtils(void)
{
}

string StringUtils::trim(const string& s)
{
    return trimRight(trimLeft(s));
}

string StringUtils::trimLeft(const string& s)
{
    size_t startpos = s.find_first_not_of(" \n\r\t");
    return (startpos == string::npos) ? "" : s.substr(startpos);
}

string StringUtils::trimRight(const string& s)
{
    size_t endpos = s.find_last_not_of(" \n\r\t");
    return (endpos == string::npos) ? "" : s.substr(0, endpos+1);
}