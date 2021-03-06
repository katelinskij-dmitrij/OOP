// HTTPURLTests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../HTTPURL/CHttpURL.h"
#include "../HTTPURL/CUrlParsingError.h"
#include "../HTTPURL/Errors.h"

void VerifyUrl(CHttpUrl url,
	string const& urlStr,
	Protocol protocol,
	string const& domain,
	string const& document,
	unsigned short port)
{
	CHECK(url.GetProtocol() == protocol);
	CHECK(url.GetDomain() == domain);
	CHECK(url.GetDocument() == document);
	CHECK(url.GetPort() == port);
	CHECK(url.GetURL() == urlStr);
}

TEST_CASE("CHttpURLTest")
{
	cout << "CHttpURLTest" << endl;
	SECTION("ParseUrl")
	{
		cout << "ParseUrl" << endl;
		SECTION("can_parse_url")
		{
			cout << "can_parse_url" << endl;
			string url = "https://site.com/page.php?id=100";
			VerifyUrl(CHttpUrl(url), url, Protocol::HTTPS, "site.com", "/page.php?id=100", 443);
			VerifyUrl(CHttpUrl("vk.com", "/theoriginalcas"), "http://vk.com/theoriginalcas", Protocol::HTTP, "vk.com", "/theoriginalcas", 80);
			VerifyUrl(CHttpUrl("vk.com", "/theoriginalcas", Protocol::HTTPS, 2425), "https://vk.com:2425/theoriginalcas", Protocol::HTTPS, "vk.com", "/theoriginalcas", 2425);
		}
	}
	SECTION("ParseProtocol")
	{
		cout << "ParseProtocol" << endl;
		SECTION("can_parse_protocol")
		{
			cout << "can_parse_protocol" << endl;
			CHECK(CHttpUrl("https://site.com/").GetProtocol() == Protocol::HTTPS);
			CHECK(CHttpUrl("http://site.com/").GetProtocol() == Protocol::HTTP);
			CHECK(CHttpUrl("HTTp://site.com/").GetProtocol() == Protocol::HTTP);
		}
	}
	SECTION("ParseDomain")
	{
		cout << "ParseDomain" << endl;
		SECTION("can_parse_domain")
		{
			cout << "can_parse_domain" << endl;
			CHECK(CHttpUrl("https://site.com").GetDomain() == "site.com");
			CHECK(CHttpUrl("https://localhost:8221").GetDomain() == "localhost");
			CHECK(CHttpUrl("http://site.ru/").GetDomain() == "site.ru");
			CHECK(CHttpUrl("http://site.ru:266/index.html").GetDomain() == "site.ru");
			CHECK(CHttpUrl("http://SiTe.ru:266/index.html").GetDomain() == "site.ru");
		}
	}
	SECTION("ParsePort")
	{
		cout << "ParsePort" << endl;
		SECTION("can_parse_port")
		{
			cout << "can_parse_port" << endl;
			CHECK(CHttpUrl("https://site.com:3424").GetPort() == 3424);
			CHECK(CHttpUrl("https://site.com").GetPort() == 443);
			CHECK(CHttpUrl("http://vk.com").GetPort() == 80);
		}
	}
	SECTION("ParseDocument")
	{
		cout << "ParseDocument" << endl;
		SECTION("can_parse_document")
		{
			cout << "can_parse_document" << endl;
			CHECK(CHttpUrl("https://site.com").GetDocument() == "/");
			CHECK(CHttpUrl("https://site.com:3424").GetDocument() == "/");
			CHECK(CHttpUrl("http://alenacpp.blogspot.ru/2005/09/const-2.html").GetDocument() == "/2005/09/const-2.html");
		}
	}
	SECTION("GetUrl")
	{
		cout << "GetUrl" << endl;
		SECTION("can_return_url")
		{
			cout << "can_return_url" << endl;
			CHECK(CHttpUrl("https://site.com").GetURL() == "https://site.com/");
			CHECK(CHttpUrl("http://dimacpp.blogspot.ru:3256/2005/09/const-2.html").GetURL() == "http://dimacpp.blogspot.ru:3256/2005/09/const-2.html");
		}
	}
}