// HTMLEncodeTests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

using namespace std;

string HTMLEncode(const string& text);

string emptyString = "";
string stringWithoutHTML = "Fedya is the best programmer in the world";
string stringWithHTML = "Fedya <is the best> \"programmer\" in &the' world.";
string resultString = "Fedya &lt;is the best&gt; &quot;programmer&quot; in &amp;the&apos; world.";

TEST_CASE("HTMLEncode tests")
{
	CAPTURE(emptyString);
	CHECK(HTMLEncode(emptyString) == emptyString);
	CAPTURE(stringWithoutHTML);
	CHECK(HTMLEncode(stringWithoutHTML) == stringWithoutHTML);
	CAPTURE(resultString);
	CHECK(HTMLEncode(stringWithHTML) == resultString);
}

string HTMLEncode(const string& text)
{
	string encodeText;
	for (char ch : text)
	{
		switch (ch)
		{
		case '\"':
			encodeText += "&quot;";
			break;
		case '\'':
			encodeText += "&apos;";
			break;
		case '<':
			encodeText += "&lt;";
			break;
		case '>':
			encodeText += "&gt;";
			break;
		case '&':
			encodeText += "&amp;";
			break;
		default:
			encodeText += ch;
			break;
		}
	}
	return encodeText;
}

