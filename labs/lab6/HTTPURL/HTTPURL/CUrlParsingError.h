#pragma once

class CUrlParsingError
	: public invalid_argument
{
public:
	CUrlParsingError(const string &err);
};