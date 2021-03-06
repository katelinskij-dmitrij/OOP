// HTMLEncodeTests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../HTMLEncode/Encode.h"

using namespace std;

string emptyString = "";
string stringWithoutHTML = "Fedya is the best programmer in the world";
string stringWithHTML = "Fedya <is the best> \"programmer\" in &the' world.";
string stringWithHTML2 = "\"'Mother \"''\" best'\"";
string resultString2 = "&quot;&apos;Mother &quot;&apos;&apos;&quot; best&apos;&quot;";
string resultString = "Fedya &lt;is the best&gt; &quot;programmer&quot; in &amp;the&apos; world.";

TEST_CASE("HTMLEncode tests")
{
	CHECK(HtmlEncode(emptyString) == emptyString);
	CHECK(HtmlEncode(stringWithoutHTML) == stringWithoutHTML);
	CHECK(HtmlEncode(stringWithHTML) == resultString);
	CHECK(HtmlEncode(stringWithHTML2) == resultString2);
}