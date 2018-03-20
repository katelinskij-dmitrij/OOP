// HTMLEncode.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

using namespace std;

string HtmlEncode(const string& text)
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

int main()
{
	string inputLine, encodeText;
	char ch = NULL;
	cout << "To exit the program, press @." << endl;
	cout << "Enter text for encode: " << endl;
	while (ch != '@')
	{
		ch = cin.get();
		inputLine += ch;
		if (ch == '\n')
		{
			encodeText += HtmlEncode(inputLine);
			inputLine = "";
		}
	}
	cout << "Decode text:" << endl;
	cout << encodeText << endl;
    return 0;
}

