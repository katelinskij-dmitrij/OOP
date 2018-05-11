#include "stdafx.h"
#include "CUrlParsingError.h"

CUrlParsingError::CUrlParsingError(string const& message)
	:invalid_argument(message)
{
}