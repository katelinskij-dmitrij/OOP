#pragma once

enum Protocol
{
	HTTP = 80,
	HTTPS = 443
};

class CHttpUrl
{
public:
	CHttpUrl(string const& url);

	CHttpUrl(
		string const& domain,
		string const& document,
		Protocol protocol = Protocol::HTTP,
		unsigned short port = static_cast<unsigned short>(Protocol::HTTP)
	);

	string GetURL()const;
	string GetDomain()const;
    string GetDocument()const;
    Protocol GetProtocol()const;
	unsigned short GetPort()const;
	string ToStringProtocol() const;

private:
	string m_document;
	string m_domain;
	Protocol m_protocol;
	unsigned short m_port;

	string ToStringPort() const;
	Protocol ToProtocolType(string const & protocol) const;
	Protocol ParseProtocol(string & urlRef) const;
	string ParseDomain(string & urlRef) const;
	unsigned short ParsePort(string & urlRef) const;
	void ValidateDocument(string const & document) const;
	void ValidateDomain(string const & domain) const;
	void ValidatePort(int port) const;
};