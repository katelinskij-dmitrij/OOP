#include "stdafx.h"
#include "CHttpURL.h"
#include "CUrlParsingError.h"
#include "Errors.h"

static const int MAX_NUMBER_OF_PORT = 65535;
static const int MIN_NUMBER_OF_PORT = 1;
static const string PROTOCOL_DELIMITER = "://";

CHttpUrl::CHttpUrl(string const& url)
{
	string strUrl(url);
	m_protocol = ParseProtocol(strUrl);
	m_domain = ParseDomain(strUrl);
	ValidateDomain(m_domain);
	m_port = ParsePort(strUrl);
	ValidateDocument(strUrl);
	m_document = (strUrl[0] == '/') ? strUrl : "/";
};

CHttpUrl::CHttpUrl(
	string const& domain,
	string const& document,
	Protocol protocol,
	unsigned short port
)
	:m_domain(domain)
	, m_document(document)
	, m_protocol(protocol)
	, m_port(port)
{
	ValidateDomain(domain);
	ValidateDocument(document);
}

Protocol CHttpUrl::GetProtocol() const
{
	return m_protocol;
}

string CHttpUrl::GetDomain() const
{
	return m_domain;
}

unsigned short CHttpUrl::GetPort() const
{
	return m_port;
}

string CHttpUrl::GetDocument() const
{
	return m_document;
}

string CHttpUrl::GetURL() const
{
	return ToStringProtocol() + "://" + m_domain + ToStringPort() + m_document;
}

string CHttpUrl::ToStringPort() const
{
	return ((m_port == static_cast<unsigned short>(Protocol::HTTP)) ||
		(m_port == static_cast<unsigned short>(Protocol::HTTPS))) ? "" : ":" + to_string(m_port);
}

string CHttpUrl::ToStringProtocol() const
{
	string result;
	if (m_protocol == Protocol::HTTP)
	{
		result = "http";
	}
	else if (m_protocol == Protocol::HTTPS)
	{
		result = "https";
	}
	return result;
}
Protocol CHttpUrl::ToProtocolType(string const& protocol) const
{
	if (protocol == "http")
	{
		return Protocol::HTTP;
	}
	if (protocol == "https")
	{
		return Protocol::HTTPS;
	}
	throw CUrlParsingError(INVALID_PROTOCOL);
}

Protocol CHttpUrl::ParseProtocol(string & urlRef) const
{
	auto position = urlRef.find(PROTOCOL_DELIMITER);
	if (position == string::npos)
	{
		throw CUrlParsingError(PROTOCOL_PARSING_ERROR);
	}
	auto protocol = urlRef.substr(0, position);
	transform(protocol.begin(), protocol.end(), protocol.begin(), ::tolower);
	urlRef = urlRef.substr(position + PROTOCOL_DELIMITER.size());
	return ToProtocolType(protocol);
}

void CHttpUrl::ValidateDomain(string const& domain) const
{
	bool isContainsInvalidChar = (domain.find(" ") != string::npos) ||
		(domain.find("\'") != string::npos) ||
		(domain.find("\"") != string::npos);
	if (isContainsInvalidChar)
	{
		throw CUrlParsingError(INVALID_DOMAIN);
	}
}

string CHttpUrl::ParseDomain(string & urlRef) const
{
	auto position = urlRef.find(":");
	if (position == string::npos)
	{
		position = urlRef.find("/");
	}
	auto domain = urlRef.substr(0, position);
	if (domain.empty())
	{
		throw CUrlParsingError(DOMAIN_PARSING_ERROR);
	}
	urlRef = urlRef.substr(domain.size());
	transform(domain.begin(), domain.end(), domain.begin(), ::tolower);
	return domain;
}

unsigned short CHttpUrl::ParsePort(string & urlRef) const
{
	int port;
	if (urlRef[0] == ':')
	{
		auto endPos = urlRef.find('/');
		auto portStr = urlRef.substr(1, endPos - 1);
		urlRef = urlRef.substr(portStr.size() + 1, urlRef.size() - 1);
		if (portStr.empty())
		{
			throw CUrlParsingError(PORT_PARSING_ERROR);
		}
		try
		{
			port = stoi(portStr);
		}
		catch (invalid_argument const& error)
		{
			throw CUrlParsingError(error.what());
		}
		ValidatePort(port);
	}
	else
	{
		port = static_cast<unsigned short>(m_protocol);
	}
	return port;
}

void CHttpUrl::ValidateDocument(string const& document) const
{
	bool isValidDocument = document.find(" ") != string::npos;
	if (isValidDocument)
	{
		throw CUrlParsingError(INVALID_DOCUMENT);
	}
}
void CHttpUrl::ValidatePort(int port)const
{
	bool isValidPort(port < MIN_NUMBER_OF_PORT || port > MAX_NUMBER_OF_PORT);
	if (isValidPort)
	{
		throw CUrlParsingError(INVALID_PORT);
	}
}